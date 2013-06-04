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

#include "FileStream.h"

namespace Base {

	Stream* FileStream::createCopy() const {
		return new FileStream(getFilename());
	}
#ifndef _android
	Stream* FileStream::createLimitedCopy(int size) const {
#else
	Stream* FileStream::createLimitedCopy(int size, JNIEnv* jniEnv, jobject jthis) const {
#endif
		int curPos;
		TEST(tell(curPos));
		int src_size;
		TEST(length(src_size));
		if(size < 0)
			size = src_size - curPos;
		else if(curPos + size > src_size) {
			FAIL;
		}
#ifndef _android
		return new LimitedFileStream(getFilename(), curPos, size);
#else
		return new LimitedFileStream(getFilename(), curPos, size, jniEnv, jthis);
#endif
	}

	bool LimitedFileStream::_open() {
		//make sure it's big enough
		TEST(FileStream::seek(Seek::Start, mEndPos));
		//seek to our starting point
		TEST(FileStream::seek(Seek::Start, mStartPos));
		return true;
	}

	bool LimitedFileStream::read(void* dst, int size) {
		int curPos;
		TEST(FileStream::tell(curPos));
		if(curPos + size > mEndPos) {
			FAIL;
		}
		TEST(FileStream::read(dst, size));
		return true;
	}

	bool LimitedFileStream::length(int& aLength) const {
		TEST(isOpen());
		aLength = mEndPos - mStartPos;
		return true;
	}

	bool LimitedFileStream::tell(int& aPos) const {
		TEST(FileStream::tell(aPos));
		aPos -= mStartPos;
		return true;
	}

	bool LimitedFileStream::seek(Seek::Enum mode, int offset) {
		int newPos;
		if(mode == Seek::Start) {
			newPos = mStartPos + offset;
		} else if(mode == Seek::Current) {
			int curPos;
			TEST(FileStream::tell(curPos));
			newPos = curPos + offset;
		} else if(mode == Seek::End) {
			newPos = mEndPos + offset;
		} else {	//unsupported mode
			FAIL;
		}
		if(newPos < mStartPos || newPos > mEndPos) {
			FAIL;
		}
		TEST(FileStream::seek(Seek::Start, newPos));
		return true;
	}

	Stream* LimitedFileStream::createLimitedCopy(int size) const {
		int curPos;
		TEST(FileStream::tell(curPos));
		if(size < 0)
			size = mEndPos - curPos;
		else if(curPos + size > mEndPos) {
			FAIL;
		}

#ifndef _android
		return new LimitedFileStream(getFilename(), curPos, mEndPos - curPos);
#else
		return new LimitedFileStream(getFilename(), curPos, mEndPos - curPos, mJNIEnv, mJThis);
#endif
	}

	Stream* LimitedFileStream::createCopy() const {
		int curPos;
		TEST(FileStream::tell(curPos));

#ifndef _android
		return new LimitedFileStream(getFilename(), mStartPos, mEndPos - mStartPos);
#else
		return new LimitedFileStream(getFilename(), mStartPos, mEndPos - mStartPos, mJNIEnv, mJThis);
#endif
	}

}
