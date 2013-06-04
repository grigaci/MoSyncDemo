/* Copyright (C) 2009 Mobile Sorcery AB

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
*/

#include <string.h>
#include <string>

//todo: cleanup
#define LOGGING_ENABLED
#define CONFIG_H

#include "helpers/helpers.h"

#include "stabs_parse.h"
#include "stabs_types.h"
#include "stabs_builtins.h"
#include "stabs_typedefs.h"
#include "stabs_function.h"
#include "stabs.h"
	
using namespace std;

//updates *pText to point to the text following the type declaration.
static const TypeBase* subParseArray(char** pText);
static const TypeBase* subParseRangeType(char** pText);
static const TypeBase* subParseEnum(char** pText, const string& enumName);
static const TypeBase* subParseMembers(int size, char** pText, const string& name);
static char* subParseMember(char* text, StructType* st);
static char* subParseMethodDeclaration(char* text, const string& name, StructType* st);
static char* subParseInheritance(char* text, StructType* st);
static bool setVisibility(Visibility&, char c);

bool parseLSym(Tuple t, char* text) {
	Type s;
	char* colon = text;
	//search for a single colon.
	//a double colon is part of the typename.
	while(1) {
		colon = strchr(colon, ':');
		FAILIF(!colon);
		if(colon[1] != ':')
			break;
		colon += 2;
	}
	*colon = 0;
	s.name = text;
	char* declType = colon + 1;
	switch(declType[0]) {
	case 't':	//simple type
	case 'T':	//struct, union, enum
		break;
	case '(':	//local stack variable
		{
			StackVariable* sv = new StackVariable;
			sv->name = s.name;
			sv->offset = t.b;
			TEST(sv->dataType = subParseType(&declType, Tuple(), string()));
			Function* f = gLastFunction;
			TEST(f);
			ScopedVariable scv;
			scv.v = sv;
			f->locals.push_back(scv);
			return true;
		}
		break;
	default:	//unknown
		FAIL;
	}
	if(declType[1] == 't')	//inline typedef? ignore.
		declType++;
	char* equalSign = scanTuple(declType + 1, &s.id);
	FAILIF(!equalSign);
	//if it's a builtin, don't try to parse any more;
	//it'd be too tricky.
	for(int i=0; i<snBuiltins; i++) {
		if(s.name == sBuiltins[i].name) {
			s.type = sBuiltins[i].type;
			TEST(addType(s));
			return true;
		}
	}
	if(*equalSign == 0) {	//typedef. tuple must already be defined.
		FAILIF(findTypeByTuple(s.id) == NULL);
		return true;
	}
	FAILIF(*equalSign != '=');
	char* typeText = equalSign + 1;
	TEST(s.type = subParseType(&typeText, s.id, s.name));
	TEST(addType(s));
	return true;
}

//xref := text ('<' xref '>')? ':'
//text := [^<>]+
static bool scanXrefTypename(char*& ptr, char delim) {
	while(1) {
		char c = *ptr;
		TEST(c);
		if(c == '<') {
			ptr++;
			TEST(scanXrefTypename(ptr, '>'));
		} else if(c == delim) {
			return true;
		}
		ptr++;
	}
}


//typeDecl := pointerDecl | tupleDecl | structDecl | arrayDecl | functionDecl |
//	constDecl | enumDecl | crossRefDecl | cppRefDecl | ptmDecl
//tupleDecl := typeId ('=' typeDecl)?
//pointerDecl := '*' typeDecl
//structDecl := 's' members
//functionDecl := ('f' | '#') typeDecl (',' typeDecl)*
//constDecl := 'k' typeDecl
//crossRefDecl := 'x' ('s' | 'u' | 'e') name ':'
//cppRefDecl := '&' typeDecl
//ptmDecl := '@' typeDecl ',' typeDecl
const TypeBase* subParseType(char** pText, const Tuple& id, const string& name) {
	const TypeBase* result = NULL;
	char* typeText = *pText;
	//otherwise, continue on.
	switch(typeText[0]) {
	case '*':
		{
			*pText = typeText + 1;
			const TypeBase* tb = subParseType(pText, id, name);
			TEST(tb);
			//TEST(*pText = scanTuple(typeText + 1, &t));
			PointerType* p = new PointerType(tb);
			//TEST(p->set(t));
			result = p;
			TEST(result);
		}
		break;
	case '(':
		{
			Tuple t;
			char* next = scanTuple(typeText, &t);
			TEST(next);
			if(*next == '=') {	//new type definition
				*pText = next + 1;
				result = subParseType(pText, t, name);
				TEST(result);

				Type s;
				s.id = t;

				// if it is an anonymous struct we need to do a little hack.
				if(result->type() == TypeBase::eStruct && name=="") {
					StringPrintFunctor spf;
					result->printTypeMI(spf, false);
					s.name = spf.getString();
				}
				else s.name = name;

				s.type = result;
				TEST(addType(s));
			} else {	//ordinary typedef
				result = findTypeByTuple(t);
				if(!result) {
					result = new DelayedType(new TupleReference(t));
				}
				*pText = next;
			}
		}
		break;
	case 's':	//struct (or "size in bytes", unclear which)
	case 'u':	//union
		{
			int size, len;
			int res = sscanf(typeText + 1, "%i%n", &size, &len);
			FAILIF(res != 1);
			char* members = typeText + 1 + len;
			result = subParseMembers(size, &members, name);
			TEST(result);
			*pText = members;
		}
		break;
	case 'a':	//array
		(*pText)++;
		result = subParseArray(pText);
		TEST(result);
		break;
	case 'f':	//function
	case '#':	//member function
		{
			*pText = typeText + 1;
			const TypeBase* tb = subParseType(pText, id, name);
			TEST(tb);
			FunctionType* p = new FunctionType(tb);
			if(typeText[0] == '#') {
				TEST(**pText == ',');
				while(**pText == ',') {	//parameters
					(*pText)++;
					TEST(tb = subParseType(pText));
					p->addParam(tb);
				}
				TEST(**pText == ';');
				(*pText)++;
			}
			result = p;
		}
		break;
	case 'k':	//const
		{
			*pText = typeText + 1;
			const TypeBase* tb = subParseType(pText, id, name);
			TEST(tb);
			TEST(result = new ConstType(tb));
		}
		break;
	case 'B':	//volatile
		{
			*pText = typeText + 1;
			const TypeBase* tb = subParseType(pText, id, name);
			//should maybe have its own type, but is not needed at this time.
			TEST(result = tb);
		}
		break;
	case 'e':	//enum
		*pText = typeText + 1;
		TEST(result = subParseEnum(pText, name));
		break;
	case 'x':	//cross-reference
		{
			char crossType = typeText[1];
			char* crossName = typeText + 2;
			char* colon = crossName;
			//find the end of the typename
			TEST(scanXrefTypename(colon, ':'));
			*colon = 0;
			if(crossType == 's' || crossType == 'u' || crossType == 'e') {
				TEST(result = new DelayedType(new CrossReferenceType(id, crossName)));
			} else {
				FAIL;
			}
			*pText = colon + 1;
		}
		break;
	case '&':	//C++ reference
		{
			*pText = typeText + 1;
			const TypeBase* tb = subParseType(pText, id, name);
			TEST(tb);
			TEST(result = new ReferenceType(tb));
		}
		break;
	case '@':	//C++ Pointer-to-member
		{
			*pText = typeText + 1;
			const TypeBase* classType = subParseType(pText, id, name);
			TEST(classType);
			TEST(**pText == ',');
			(*pText)++;
			const TypeBase* memberType = subParseType(pText, id, name);
			TEST(memberType);
			TEST(classType->type() == TypeBase::eStruct);
			TEST(result = new PointerToMemberType((StructType*)classType, memberType));
		}
		break;
	case ':':
		{
			// this seems to appear when we have a pointer to member (it describes what arguments the function have.. let's just skip it for now..
			while(**pText != ';')
				pText++;
		}
		break;
	default:	//unknown
		FAIL;
	}
	return result;
}

//grammar:
// typeId := '(' a ',' b ')'
// rangeTypeDefinition := typeId '=r' typeId ';' rangeMin ';' rangeMax ';'
// rangeType := 'r' (typeId | rangeTypeDefinition) ';'
// arrayDecl := 'a' rangeType lowerBound ';' upperBound ';' elementType
static const TypeBase* subParseArray(char** pText) {
	char* text = *pText;
	const TypeBase* rangeType = subParseRangeType(&text);
	TEST(rangeType);
	//the rangeType can be ignored, because it's always going to be the same.
	int lower, upper, len;
	int res = sscanf(text, "%i;%i%n", &lower, &upper, &len);
	FAILIF(res != 2);

	bool isUnboundedArray = true;

	if(lower == 0 && upper == -1) {
		isUnboundedArray = false;
	} else {
		FAILIF(lower > upper);
	}

	text += len;
	FAILIF(text[0] != ';');
#if 0
	Tuple t;
	TEST(*pText = scanTuple(text + 1, &t));
	const TypeBase* elemType = findTypeByTuple(t);
#endif
	*pText = text + 1;
	const TypeBase* elemType = subParseType(pText, Tuple(), string());
	TEST(elemType);
	
	if(isUnboundedArray) {
		int size = (upper - lower) + 1;
		return new ArrayType(size, elemType, rangeType);
	} else {
		return new PointerType(elemType);
	}
}

// alt.rangeTypeDefinition := '=r' typeId ';' rangeMin ';' rangeMax ';'
// alt.rangeType := 'r' typeId alt.rangeTypeDefinition? ';'
static const TypeBase* subParseRangeType(char** pText) {
	char* text = *pText;
	FAILIF(text[0] != 'r');
	Tuple t;
	char* next = scanTuple(text + 1, &t);
	TEST(next);
	if(*next == ';') {	//no definition
		*pText = next + 1;
		const TypeBase* tb = findTypeByTuple(t);
		TEST(tb);
		return tb;
	}
	//alt.rangeTypeDefinition
	FAILIF(next[0] != '=');
	FAILIF(next[1] != 'r');
	Tuple t2;
	TEST(next = scanTuple(next + 2, &t2));
	FAILIF(t != t2);
	int min, max, len;
	int res = sscanf(next, ";%i;%i%n", &min, &max, &len);
	FAILIF(res != 2);
	FAILIF(next[len] != ';');
	FAILIF(next[len+1] != ';');
	*pText = next + len + 2;
	RangeType* rt = new RangeType(min, max);
	TEST(rt);
	Type s;
	s.id = t;
	s.type = rt;
	TEST(addType(s));
	return rt;
}

//grammar:
// enumDecl := (name ':' value ',')+ ';'
static const TypeBase* subParseEnum(char** pText, const string& enumName) {
	EnumType* et = new EnumType(enumName);
	char* next = *pText;
	do {
		EnumMember em;
		char* name = next;
		next = strchr(next, ':');
		TEST(next);
		em.name = string(name, int(next - name));
		next++;
		int len;
		TEST(sscanf(next, "%i%n", &em.value, &len) == 1);
		next += len;
		TEST(*next == ',');
		next++;
		et->addMember(em);
	} while(*next != ';');
	*pText = next + 1;
	return et;
}

//grammar:
// visibilityDigit := ('0' | '1' | '2')	//private, protected, public
// constVolatile := ('A' | 'B' | 'C' | 'D')	//normal, const, volatile, const volatile
// virtuality := ('.' | '?' | ('*' int ';' typeDecl ';'))	//thiscall, static, virtual (vtable index), baseType
// visibility := '/' visibilityDigit
// member-data := name ':' (visibility)? typeDecl ',' offsetBits ',' lengthBits ';'
// funcMeta := (',' typeDecl)+ ';'
// funcMods := visibilityDigit constVolatile virtuality
// method-type-decl := typeDecl (funcMeta)? ':' globalName ';' funcMods
// member-function := localName '::' (method-type-decl)+ ';'
// member := (member-data | member-function)
// baseVirtuality := ('0' | '1')	//normal, virtual
// baseClass := baseVirtuality visibilityDigit offset ',' typeId ';'
// inheritance := numberOfBases ',' (baseClass)+
// firstBaseClass := '~%' typeDecl ';'
// members := (inheritance)? (member)+ ';' (firstBaseClass)?

static const TypeBase* subParseMembers(int size, char** pText, const string& name) {
	//LOG("subParseMembers %s\n", *pText);
	StructType* st;
	if(name.length() == 0) {
		// for anonymous structs generate a type name that isn't valid c or c++.
		static int anonId = 0;
		char tmp[16];
		sprintf(tmp, "%i", anonId++); 
		st = new StructType(size, "___AnonymousStruct" + string(tmp));
	} else {
		st = new StructType(size, name);
	}

	char* next = *pText;
	if(*next == '!') {	//this struct has base class(es)
		TEST(next = subParseInheritance(next + 1, st));
	}
	while(*next != ';') {
		TEST(iscsym(*next) || *next == ':');	//sanity
		TEST(next = subParseMember(next, st));
		//LOG("subParseMember next %s\n", next);
	}
	next++;
	if(*next == '~') {	//reference to first base class
		next++;
		TEST(*next == '%');
		next++;
		//we ignore it, but it may contain type definitions that are needed later.
		subParseType(&next);
		TEST(*next == ';');
		next++;
	}
	*pText = next;
	TEST(
		**pText == ':' || // test, don't know if this works.
		**pText == 0 || **pText == ',' || iscsym(**pText));	//sanity
	return st;
}

static char* subParseInheritance(char* text, StructType* st) {
	int len;
	int nBases;
	int res = sscanf(text, "%i%n", &nBases, &len);
	TEST(res == 1);
	text += len;
	TEST(*text == ',');
	text++;
	for(int i=0; i<nBases; i++) {
		BaseClass bc;
		if(*text == '0')
			bc.isVirtual = false;
		else if(*text == '1')
			bc.isVirtual = true;
		else
			FAIL;
		text++;
		TEST(setVisibility(bc.visibility, *text));
		text++;
		res = sscanf(text, "%i%n", &bc.offset, &len);
		TEST(res == 1);
		text += len;
		TEST(*text == ',');
		text++;
		TEST(bc.type = subParseType(&text));
		//TEST(bc.type->type() == TypeBase::eStruct);
		TEST(*text == ';');
		text++;
		st->addBaseClass(bc);
	}
	return text;
}

static bool setVisibility(Visibility& v, char c) {
	switch(c) {
		case '0':
			v = ePrivate;
			break;
		case '1':
			v = eProtected;
			break;
		case '2':
			v = ePublic;
			break;
		default:
			FAIL;
	}
	return true;
}

static char* subParseMember(char* text, StructType* st) {
	//LOG("subParseMember(%s)\n", text);
	int len;
	char* end;
	char* colon = strchr(text, ':');
	TEST(colon);
	string name = string(text, int(colon - text));
	if(colon[1] == ':') {	//member function
		TEST(end = subParseMethodDeclaration(colon + 2, name, st));

	} else {
		Visibility v = ePublic;
		char* next = colon + 1;
		const TypeBase* type;
		if(next[0] == '/') {	//visibility
			TEST(setVisibility(v, next[1]));
			next += 2;
		}
		TEST(type = subParseType(&next));
#if 0
		char* next = scanTuple(colon + 1, &m.id);
		TEST(next);
		if(*next == '=') {	//inline new type declaration
			//m.id is the id of the new type, and also of the member.
			Type s;
			s.id = m.id;
			s.name = m.name;
			next++;
			TEST(s.type = subParseType(&next, s.id, s.name));
			TEST(addType(s));
		}
#endif
		if(*next == ':') {	//static member
			StaticDataMember sm;
			sm.name = name;
			sm.visibility = v;
			sm.type = type;

			next++;
			char* semi = strchr(next, ';');
			TEST(semi);
			sm.globalName = string(next, int(semi - next));
			st->addStaticDataMember(sm);
			end = semi;
		} else {
			DataMember m;
			m.name = name;
			m.visibility = v;
			m.type = type;

			// anonymous members can use the generated type name as a name.
			if(name.length()==0) {
				StringPrintFunctor spf;
				m.type->printTypeMI(spf,false);
				m.name = std::string(spf.getString()) + "Member";
			}
			int res = sscanf(next, ",%i,%i%n", &m.offsetBits, &m.sizeBits, &len);
			FAILIF(res != 2);
			end = next + len;
			st->addDataMember(m);
		}
		FAILIF(*end != ';');
	}
	return end + 1;
}

static char* subParseMethodDeclaration(char* text, const string& name, StructType* st) {
	char* end;
	//LOG("member function '%s'\n", name.c_str());
	Method m;
	m.name = name;
#if 0
	//skip typeId (funcMeta)? for now
	char* semi0 = strchr(text, ';');
	TEST(semi0);
	TEST(semi0[1] == ':');
	char* globName = semi0 + 2;
#else
	// funcMeta := (',' typeDecl)+ ';'
	// method-type-decl := typeDecl (funcMeta)? ':' globalName ';' funcMods
	char* next = text;
	const TypeBase* funcType = subParseType(&next);
	TEST(funcType);
	if(*next == ',') {
		while(*next == ',') {
			next++;
			/*const TypeBase* argType =*/ subParseType(&next);
		}
		TEST(*next == ';');
		next++;
	}
	TEST(*next == ':');
	char* globName = next + 1;
#endif
	char* semi1 = strchr(globName, ';');
	TEST(semi1);
	m.globalName = string(globName, int(semi1 - globName));
	//LOG("global name '%s'\n", m.globalName.c_str());
	semi1++;
	/*end = strchr(semi1, ';');
	TEST(end);
	*end = 0;*/

	//mods
	//visibility
	//const/volatile
	//static/virtual
	TEST(setVisibility(m.visibility, semi1[0]));
	switch(semi1[1]) {
		case 'A':
			m.isConst = false;
			m.isVolatile = false;
			break;
		case 'B':
			m.isConst = true;
			m.isVolatile = false;
			break;
		case 'C':
			m.isConst = false;
			m.isVolatile = true;
			break;
		case 'D':
			m.isConst = true;
			m.isVolatile = true;
			break;
		default:
			FAIL;
	}
	next = semi1 + 3;
	switch(semi1[2]) {
	case '.':
		m.linkage = Method::eNormal;
		end = next;
		break;
	case '*':
		m.linkage = Method::eVirtual;
		{
			int len;
			TEST(sscanf(next, "%i%n", &m.virtualOffset, &len) == 1);
			TEST(next[len] == ';');
			next += len + 1;
			TEST(m.virtualBaseType = subParseType(&next));
			TEST(*next == ';');
			end = next + 1;
		}
		break;
	case '?':
		m.linkage = Method::eStatic;
		end = next;
		break;
	default:
		FAIL;
	}

	st->addMethod(m);

	if(*end == '(') {	//overloaded function
		TEST(end = subParseMethodDeclaration(end, name, st));
	} else {
		FAILIF(*end != ';');
	}
	return end;
}
