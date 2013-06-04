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
 * @file TabScreenListener.h
 * @author Bogdan Iusco
 *
 * \brief Listener for TabScreen events.
 */

#ifndef NATIVEUI_TAB_SCREEN_LISTENER_H_
#define NATIVEUI_TAB_SCREEN_LISTENER_H_

namespace NativeUI
{
    // Forward declaration.
    class TabScreen;

    /**
     * \brief Interface for tab screen event listeners.
     */
    class TabScreenListener
    {
    public:
        /**
         * This method is called when a tab screen has changed to a new tab.
         * @param tabScreen The tab screen object that generated the event.
         * @param tabScreenIndex The index of the new tab.
         */
        virtual void tabScreenTabChanged(
            TabScreen* tabScreen,
            const int tabScreenIndex) = 0;
    };

} // namespace NativeUI

#endif /* NATIVEUI_TAB_SCREEN_LISTENER_H_ */

/*! @} */
