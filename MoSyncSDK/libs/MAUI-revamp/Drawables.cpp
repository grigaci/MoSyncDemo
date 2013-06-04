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

/** 
* \file Drawables.cpp
* \brief Common types of Drawable.
* \author Fredrik Eldh
*/

#include "Drawables.h"
#include <MAUtil/Graphics.h>

void MAUI::ImageDrawable::draw(int left, int top, int width, int height) {
	Gfx_drawImage(mImage, left, top);
}

void MAUI::ColorDrawable::draw(int left, int top, int width, int height) {
	maSetColor(mColor);
	Gfx_fillRect(left, top, width, height);
}
