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

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <fstream>
#include "helpers/attribute.h"

using namespace std;

void setTokenStream(istream* is);
void readToken(string& token);
void readLine(string& line);
void readTextToken(string& token);
void readQuotedString(string& token);
void doExact(const string& aToken);
string getComment();
void ATTRIBUTE(noreturn, tokenError(const string& token));
void ATTRIBUTE(noreturn, Error(const string& type, const string& str));
int getCurrentLine();
void doEOF();

#endif	//TOKENIZER_H
