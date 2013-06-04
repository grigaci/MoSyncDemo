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
* \file RelativeLayout.h 
* \brief Relative layout of child widgets.
* \author Niklas Nummelin
*/

#ifndef _SE_MSAB_MAUI_RELATIVE_LAYOUT_H_
#define _SE_MSAB_MAUI_RELATIVE_LAYOUT_H_

#include "Widget.h"

namespace MAUI {

	/** 
	 * \brief Relative layout of child widgets.
	 *
	 * This widget is a container that layouts its children
	 * using a relative layout policy.
	 *
	 * TODO: This class does not seem to be implemented yet.
	 */
	class RelativeLayout : public Widget {
	public:
		/**
		 * Constructor.
		 * \param x Left coordinate of layout container.
		 * \param y Top coordinate of layout container.
		 * \param width Width of layout container.
		 * \param height Height of layout container.
		 */
		RelativeLayout(int x=0, int y=0, int width=0, int height=0);

		/**
		 * \retgurn true if this layout container is transparent,
		 * false if not.
		 */
		virtual bool isTransparent() const;
		
	protected:
		/**
		 * TODO: Comment purpose of this method.
		 */
		virtual void drawWidget();
	};
}

#endif /* _SE_MSAB_MAUI_RELATIVE_LAYOUT_H_ */
