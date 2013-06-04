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

#include "config_platform.h"
#include <helpers/helpers.h>

#include "MemStream.h"

#ifdef _android
#include <jni.h>
#endif

//******************************************************************************
//MemStreamC
//******************************************************************************

using namespace Base;

MemStreamC::MemStreamC(const void* src, int size) : mSrc(src), mSize(size), mPos(0) {}
bool MemStreamC::isOpen() const {
	return mSrc != NULL;
}
bool MemStreamC::read(void* dst, int size) {
	TEST(isOpen());
	if(mPos + size > mSize) {
		FAIL;
	}
	memcpy(dst, (char*)mSrc + mPos, size);
	mPos += size;
	return true;
}

bool MemStreamC::length(int& aLength) const {
	TEST(isOpen());
	aLength = mSize;
	return true;
}
bool MemStreamC::seek(Seek::Enum mode, int offset) {
	TEST(isOpen());
	int newpos;
	switch(mode) {
	case Seek::Start: newpos = offset; break;
	case Seek::Current: newpos = mPos + offset; break;
	case Seek::End: newpos = mSize + offset; break;
	default:
		FAIL;
	}
	if(newpos > mSize || newpos < 0) {
		FAIL;
	}
	mPos = newpos;
	return true;
}
bool MemStreamC::tell(int& aPos) const {
	TEST(isOpen());
	aPos = mPos;
	return true;
}

#ifndef _android
Stream* MemStreamC::createLimitedCopy(int size) const {
#else
Stream* MemStreamC::createLimitedCopy(int size, JNIEnv* jNIEnv, jobject jThis) const {
#endif
	if(size < 0)
		size = mSize - mPos;
	else if(mPos + size > mSize) {
		FAIL;
	}
	return new MemStreamC(CBP mSrc + mPos, size);
}

Stream* MemStreamC::createCopy() const {
	return new MemStreamC(CBP mSrc, mSize);
}


//******************************************************************************
//MemStream
//******************************************************************************
MemStream::MemStream(int _size) : MemStreamC(open(_size), _size) {
#ifdef _android
	externalAllocated = false;
#endif
}
MemStream::MemStream(char* buf, int _size) : MemStreamC(buf, _size) {
	mBuffer = buf;
#ifdef _android
	externalAllocated = true;
#endif
}

MemStream::~MemStream() {
#ifdef _android
	if(false == externalAllocated)
#endif
	delete mBuffer;
}
char* MemStream::open(int size) {
	return mBuffer = new char[size];
	//return mBuffer = (char*) malloc(size);
}
bool MemStream::write(const void* src, int size) {
	TEST(isOpen());
	if(mPos + size > mSize) {
		FAIL;
	}
	memcpy(mBuffer + mPos, src, size);
	mPos += size;
	return true;
}
