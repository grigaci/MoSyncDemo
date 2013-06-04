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
* \file Image.h 
* \brief Image widget, with position, size, and autosizing control.
* \author Patrick Broman and Niklas Nummelin
*/

#ifndef _SE_MSAB_MAUI_IMAGE_H_
#define _SE_MSAB_MAUI_IMAGE_H_

#include "Widget.h"
#include <ma.h>

namespace MAUI {

	/** 
     * \brief Image widget, with position, size, and autosizing control.
	 *
	 * Image is a widget used to put plain images in a graphical user
	 * interface. Pass the resource handle to the widget and it will 
	 * display that image.
	 * 
	 * The widget doesn't draw its background by default, 
	 * use setDrawBackground(true) to enable it.
	 */
	class Image : public Widget {
	public:

		/** 
		 * Constructor.
		 * \param x the horizontal position of the Image relative to its 
		 *  parent's top left padded corner.
		 * \param y the vertical position of the Image relative to its 
		 *  parent's top left padded corner
		 * \param width the width of the Image.
		 * \param height the height of the Image.
		 * \param parent pointer to the parent widget. Passing anything else
		 *  than NULL causes the Image to be added to the parent's children.
		 * \param autoSizeX If true, the widget will be resized in the 
		 *  x-axis to the image size.
		 * \param autoSizeY If true, the widget will be resized in the 
		 *  y-axis to the image size.
		 * \param res A handle to the image resource containing the image data.
		 */
		Image(
			int x=0, 
			int y=0, 
			int width=0, 
			int height=0,
			MAHandle res=0, 
			bool autoSizeX=true, 
			bool autoSizeY=true);

		/**
		 * Set the image resource of the image widget.
		 * \param imageHandle Handle to the image resource.
		 */
		void setResource(MAHandle imageHandle);

		/**
		 * Get the image resource of the image widget.
		 * \return Handle to the image resource.
		 */
		MAHandle getResource() const;

		/** 
		 * Returns the transparency of the widget.
		 * \return true if transparent, false if opaque.
		 */
		bool isTransparent() const;

	protected:
		/** 
		 * Render the image widget.
		 */
		void drawWidget();

		/**
		 * Handle to the image the widget displays.
		 */
		MAHandle mResource;
		
		/**
		 * If true, the widget will scale the image horizontally to fit
		 * within its bounds.
		 */
		bool mAutoSizeX;
		
		/**
		 * If true, the widget will scale the image vertically to fit
		 * within its bounds.
		 */
		bool mAutoSizeY;
		
		/**
		 * Width of widget.
		 */
		int mImageWidth;
		
		/**
		 * Height of widget.
		 */
		int mImageHeight;
	};
}

#endif /* _SE_MSAB_MAUI_IMAGE_H_ */
