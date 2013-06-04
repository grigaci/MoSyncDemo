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

#ifndef _BASE_FILE_STREAM_H_
#define _BASE_FILE_STREAM_H_

#include "Platform.h"

#include "Stream.h"

#include <time.h>

// platform specific

#ifdef _android
#include <jni.h>
#endif

namespace Base {

	class FileStream : public Stream {	//read-only
	public:
		FileStream(const char* filename);
#ifdef _android
		explicit FileStream(int fd);
#endif
		virtual ~FileStream();
		virtual bool isOpen() const;
		virtual bool read(void* dst, int size);
		virtual bool write(const void*, int) { FAIL; }

		virtual bool length(int& aLength) const;
		virtual bool seek(Seek::Enum mode, int offset);
		virtual bool tell(int& aPos) const;
		virtual bool mTime(time_t&) const;

#ifndef _android
		virtual Stream* createLimitedCopy(int size) const;
#else
		virtual Stream* createLimitedCopy(int size, JNIEnv* jniEnv, jobject jthis) const;
#endif
		virtual Stream* createCopy() const;

		const char* getFilename() const;
		
		virtual bool truncate(int size) { FAIL; }

#include "FileImpl.h"
	};

	class WriteFileStream : public FileStream {
	public:
		// if append: open an existing file, or create a new one if needed.
		// else if exist: open an existing file with write access.
		// else: create a file. overwrite any existing file.
		WriteFileStream(const char* filename, bool append=false, bool exist=false);
		bool write(const void* src, int size);
		Stream* createLimitedCopy(int /*size*/) const { FAIL; }
		Stream* createCopy() const { FAIL; }
		bool truncate(int size);
	};

	class LimitedFileStream : public FileStream {	//read-only
	public:
#ifndef _android
		LimitedFileStream(const char* filename, int offset, int len);
#else
		LimitedFileStream(const char* filename, int offset, int len, JNIEnv* jNIEnv, jobject jThis);
#endif
		bool read(void* dst, int size);

		bool length(int& aLength) const;
		bool seek(Seek::Enum mode, int offset);
		bool tell(int& aPos) const;

		Stream* createLimitedCopy(int size) const;
		Stream* createCopy() const;
	protected:
		const int mStartPos, mEndPos;
		bool _open();
#ifdef _android
		JNIEnv* mJNIEnv;
		jobject mJThis;
#endif
	};

} // namespace Base

#endif // _BASE_FILE_STREAM_H_
