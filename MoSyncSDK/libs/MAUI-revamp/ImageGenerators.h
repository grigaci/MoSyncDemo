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

/** 
* \file ImageGenerators.h
* \brief Utility class that generates linear and circular gradients.
* \author Patrick Broman and Niklas Nummelin
*/

#ifndef _SE_MSAB_MAUI_IMAGE_GENERATORS_H_
#define _SE_MSAB_MAUI_IMAGE_GENERATORS_H_

#include <ma.h>
#include <MAUtil/Geometry.h>

namespace MAUI {
	using namespace MAUtil;

/** 
 * \brief Utility class that generates linear and circular gradients.
 */
class ImageGenerators {
public:
	/**
	 * Available alpha modes.
	 */
	enum AlphaMode {
		AM_NOALPHA,
		AM_WRITEALPHA,
		AM_USEALPHA
	};

	/**
	 * TODO: Document method.
	 * \param image TODO: Document param.
	 * \param start TODO: Document param.
	 * \param end TODO: Document param.
	 * \param startColor TODO: Document param.
	 * \param endColor TODO: Document param.
	 * \param alphaMode TODO: Document param.
	 */
	static void linearGradient(
		MAHandle image, 
		Point start, 
		Point end, 
		int startColor, 
		int endColor, 
		ImageGenerators::AlphaMode alphaMode=AM_WRITEALPHA);
		
	/**
	 * TODO: Document method.
	 * \param image TODO: Document param.
	 * \param origo TODO: Document param.
	 * \param radius TODO: Document param.
	 * \param origoColor TODO: Document param.
	 * \param circleColor TODO: Document param.
	 * \param alphaMode TODO: Document param.
	 */
	static void circularGradient(
		MAHandle image, 
		Point origo, 
		int radius, 
		int origoColor, 
		int circleColor, 
		ImageGenerators::AlphaMode alphaMode=AM_WRITEALPHA);
};

} // namespace MAUI

#endif /* _SE_MSAB_MAUI_IMAGE_GENERATORS_H_ */
