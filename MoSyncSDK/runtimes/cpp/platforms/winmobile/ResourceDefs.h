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

#ifndef _RESOURCE_DEFS_H_
#define _RESOURCE_DEFS_H_

#include <windows.h>
#include "../../base/Stream.h"
#include "Image.h"

#define TYPES(m)\
	m(RT_BINARY, Base::Stream, delete)\
	m(RT_PLACEHOLDER, void, NUL)\
	m(RT_LABEL, Label, delete) \
	m(RT_IMAGE, Image, delete)\
	m(RT_FLUX, void, NUL)\

#endif // _RESOURCE_DEFS_H_
