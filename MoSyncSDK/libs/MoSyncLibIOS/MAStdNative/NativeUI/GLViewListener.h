/*
Copyright (C) 2011 MoSync AB

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License,
version 2, as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

/*! \addtogroup NativeUILib
 *  @{
 */

/**
 *  @defgroup NativeUILib Native UI Library
 *  @{
 */

/**
 * @file GLViewListener.h
 * @author Bogdan Iusco
 *
 * \brief Listener for GLView events.
 */

#ifndef NATIVEUI_GL_VIEW_LISTENER_H_
#define NATIVEUI_GL_VIEW_LISTENER_H_

namespace NativeUI
{
    // Forward declaration.
    class GLView;

    /**
     * \brief Listener for GLView events.
     */
    class GLViewListener
    {
    public:
        /**
         * This method is called when the OpenGL view has been initialized
         * and is ready for setup.
         * @param glView The OpenGL view object that generated the event.
         */
        virtual void glViewReady(GLView* glView) = 0;
    };

} // namespace NativeUI

#endif /* NATIVEUI_GL_VIEW_LISTENER_H_ */

/*! @} */
