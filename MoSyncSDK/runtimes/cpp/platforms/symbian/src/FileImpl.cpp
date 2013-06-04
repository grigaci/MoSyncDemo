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
#include "FileStream.h"
#include "symbian_helpers.h"

#ifdef __SERIES60_3X__
#define FILE_SHARE EFileShareReadersOrWriters
#else
#define FILE_SHARE EFileShareAny
#endif

namespace Base {
	//******************************************************************************
	//FileStream
	//******************************************************************************
	const char* FileStream::getFilename() const {
		return (const char*)mFilename->Ptr();	//hack, see open()
	}
	
	FileStream::FileStream() : mOpenResult(KErrGeneral) {}

	FileStream::FileStream(const char* filename) {
		open(filename, false, false, false);
	}
	void FileStream::open(const char* filename, bool write, bool append, bool exist) {
		mOpenResult = mFs.Connect();
		if(mOpenResult != KErrNone)
			return;

		TPtrC8 namePtr(CBP filename);
		mFilename = HBufC8::New(namePtr.Length() + 1);
		if(!mFilename) {
			mOpenResult = KErrNoMemory;
			return;
		}
		mFilename->Des().Copy(namePtr);
		mFilename->Des().PtrZ();	//set the zero terminator, for getFilename().

		TCleaner<HBufC16> unicodeName(CreateHBufC16FromDesC8LC(namePtr));
		if(write) {
			if(append || exist) {
				LOG("AFO %s\n", filename);
				TSNR(mOpenResult = mFile.Open(mFs, *unicodeName, FILE_SHARE | EFileWrite));
				if(IS_SYMBIAN_ERROR(mOpenResult))
					return;
				TInt offset = 0;
				if(append) {
					// TODO: set a flag so that every write goes to the end of the file,
					// even if you seek to another position.
					TSNR(mOpenResult = mFile.Seek(ESeekEnd, offset));
				}
			} else {
				LOG("WFO %s\n", filename);
				TSNR(mOpenResult = mFile.Replace(mFs, *unicodeName, FILE_SHARE | EFileWrite));
			}
		} else {
			LOG("RFO %s\n", filename);
			TSNR(mOpenResult = mFile.Open(mFs, *unicodeName, FILE_SHARE | EFileRead));
		}
	}

	bool FileStream::isOpen() const {
		return mOpenResult == KErrNone;
	}
	FileStream::~FileStream() {
		mFile.Close();
		mFs.Close();
	}
	bool FileStream::read(void* dst, int size) {
		TEST(isOpen());
		TPtr8 des((byte*)dst, size);
		TEST_SYMBIAN(mFile.Read(des));
		return des.Length() == des.MaxLength();
	}
	bool FileStream::length(int& aLength) const {
		TEST(isOpen());
		TEST_SYMBIAN(mFile.Size(aLength));
		return true;
	}
	bool FileStream::seek(Seek::Enum mode, int offset) {
		TEST(isOpen());
		TSeek ts;
		switch(mode) {
		case Seek::Current: ts = ESeekCurrent; break;
		case Seek::Start: ts = ESeekStart; break;
		case Seek::End: ts = ESeekEnd; break;
		default: DEBIG_PHAT_ERROR;
		}
		TEST_SYMBIAN(mFile.Seek(ts, offset));
		return true;
	}
	bool FileStream::tell(int& aPos) const {
		TEST(isOpen());
		aPos = 0;
		TEST_SYMBIAN(mFile.Seek(ESeekCurrent, aPos));
		return true;
	}
	bool FileStream::mTime(time_t& t) const {
		// TODO
		FAIL;
	}

	//******************************************************************************
	//LimitedFileStream
	//******************************************************************************
	LimitedFileStream::LimitedFileStream(const char* filename, int offset, int len)
		: FileStream(filename), mStartPos(offset), mEndPos(offset + len)
	{
		if(!_open()) {
			mOpenResult = KErrGeneral;
		}
	}

	//******************************************************************************
	//WriteFileStream
	//******************************************************************************

	WriteFileStream::WriteFileStream(const char* filename, bool append, bool exist)
		: FileStream(filename, true, append, exist) {}

	bool WriteFileStream::write(const void* src, int size) {
		TEST(isOpen());
		TPtrC8 desc(CBP src, size);
		TEST_SYMBIAN(mFile.Write(desc));
		return true;
	}
	bool WriteFileStream::truncate(int size) {
		// TODO
		FAIL;
	}

}
