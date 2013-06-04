/* Copyright (C) 2010 MoSync AB

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

#include "wchar.h"

// TODO: shorten these function by using loops.
int mbtowc(wchar_t* dst, const char* src, size_t count) {
	if(count < 1)
		return -1;
	if((src[0] & 0x80) == 0) {	// 1 byte
		*dst = *src;
		return *dst == 0 ? 0 : 1;
	} else if((src[0] & 0xE0) == 0xC0) {	// 2 bytes
		if(count < 2)
			return -1;
		if((src[1] & 0xC0) != 0x80)
			return -1;
		*dst = ((((wchar_t)src[0]) & 0x1F) << 6) | (((wchar_t)src[1]) & 0x3F);
		return *dst == 0 ? 0 : 2;
	} else if((src[0] & 0xF0) == 0xE0) {	// 3 bytes
		if(count < 3)
			return -1;
		if((src[1] & 0xC0) != 0x80)
			return -1;
		if((src[2] & 0xC0) != 0x80)
			return -1;
		*dst = ((((wchar_t)src[0]) & 0x0F) << 12) | ((((wchar_t)src[1]) & 0x1F) << 6) |
			(((wchar_t)src[2]) & 0x3F);
		return *dst == 0 ? 0 : 3;

		// if we use UCS-2, we can't deal with Unicode characters outside the Basic Multilingual Plane.
#if MB_CUR_MAX > 3
	} else if((src[0] & 0xF8) == 0xF0) {	// 4 bytes
		if(count < 4)
			return -1;
		if((src[1] & 0xC0) != 0x80)
			return -1;
		if((src[2] & 0xC0) != 0x80)
			return -1;
		if((src[3] & 0xC0) != 0x80)
			return -1;
		*dst = ((((wchar_t)src[0]) & 0x03) << 18) | ((((wchar_t)src[1]) & 0x0F) << 12) |
			((((wchar_t)src[2]) & 0x1F) << 6) | (((wchar_t)src[3]) & 0x3F);
		return *dst == 0 ? 0 : 4;
#endif	//MB_CUR_MAX
	}
	return -1;
}

int wctomb(char* dst, wchar_t src) {
	if(src <= 0x7F) {
		*dst = (char)src;
		return src == 0 ? 0 : 1;
	} else if(src <= 0x7FF) {
		dst[1] = 0x80 | (src & 0x3F);
		dst[0] = 0xC0 | ((src & 0x7E0) >> 6);
		return 2;
	} else {
#if MB_CUR_MAX > 3
		if(src <= 0xFFFF)
#endif
		{
			dst[2] = 0x80 | (src & 0x3F);
			dst[1] = 0x80 | ((src & 0x0FE0) >> 6);
			dst[0] = 0xE0 | ((src & 0xF000) >> 12);
			return 3;
		}
#if MB_CUR_MAX > 3
		else if(src <= 0x10FFFF) {
			dst[3] = 0x80 | (src & 0x3F);
			dst[2] = 0x80 | ((src & 0x0FE0) >> 6);
			dst[1] = 0x80 | ((src & 0x03F000) >> 12);
			dst[0] = 0xF0 | ((src & 0x3C0000) >> 18);
			return 4;
		}
#endif
	}
#if MB_CUR_MAX > 3
	return -1;
#endif
}

size_t mbstowcs(wchar_t* dst, const char* src, size_t count) {
	size_t wpos = 0;
	const char* srcp = src;
	if(dst == NULL) {
		wchar_t wc;
		int res;
		do {
			res = mbtowc(&wc, srcp, 4);
			if(res < 0)
				return res;
			wpos++;
			srcp += res;
		} while(res > 0);
	} else while(wpos < count) {
		int res = mbtowc(dst + wpos, srcp, 4);
		if(res < 0)
			return res;
		if(res == 0) {
			break;
		}
		wpos++;
		srcp += res;
	}
	return wpos;
}

size_t wcstombs(char* dst, const wchar_t* src, size_t count) {
	size_t dpos = 0;
	const wchar_t* srcp = src;
	if(dst == NULL) {
		char mb[MB_CUR_MAX];
		int res;
		do {
			res = wctomb(mb, *srcp);
			if(res < 0)
				return res;
			dpos += res;
			srcp++;
		} while(res > 0);
		dpos++;	// terminating NULL.
	} else {
		// write directly to dst while enough space remains.
		while(dpos + MB_CUR_MAX < count) {
			int res = wctomb(dst + dpos, *srcp);
			if(res < 0)
				return res;
			if(res == 0)
				return dpos;
			srcp++;
			dpos += res;
		}
		// slower method when very little space remains.
		while(dpos < count) {
			char buf[MB_CUR_MAX];
			int bytes = wctomb(buf, *srcp);
			int remain, num_to_copy;
			if(bytes < 0)
				return bytes;
			remain = count - dpos;
			num_to_copy = (remain > bytes ? bytes : remain);
			for(int i=0; i<num_to_copy; ++i)
				dst[dpos++] = buf[i];

			if (*srcp == 0)
				return dpos;
			++srcp;
		}
	}
	return dpos;
}
