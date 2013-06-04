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
 * \file Screen.cpp
 * \brief A full screen container for widgets.
 * \author Patrick Broman and Niklas Nummelin
 */

#include "Screen.h"
#include "Engine.h"
//#include <conprint.h>

namespace MAUI {

	Screen* Screen::sCurrentScreen = NULL;
	
	Screen::Screen() : mMain(0), mFocusedWidget(0) {
		hide();
		MAExtent scrSize = maGetScrSize();
		mScreenWidth = EXTENT_X(scrSize);
		mScreenHeight = EXTENT_Y(scrSize);
	}
	
	void Screen::show() {
		//printf("showing screen!\n");
		
		if(!mMain) {
			return;
		}

		if(sCurrentScreen) sCurrentScreen->hide();
		sCurrentScreen = this;
		Engine::getSingleton().setMain(mMain);
		mMain->setEnabled(true);
		//mMain->setDirty(true);
		mMain->requestRepaint();

		//printf("Requesting UI update...!\n");
		// TODO: Document why this line has been commented out.
		//Engine::getSingleton().requestUIUpdate();
		Environment::getEnvironment().addKeyListener(this);
		Environment::getEnvironment().addPointerListener(this);
	}
	
	void Screen::setMain(Widget* main) {
		this->mMain = main;
		if(sCurrentScreen == this)
			Engine::getSingleton().setMain(main);
		if(!mMain) return;
		mMain->setPosition(0,0);
		mMain->setWidth(mScreenWidth);
		mMain->setHeight(mScreenHeight);
		if(sCurrentScreen != this) {
			mMain->setEnabled(false);
		}

		//MAUI_LOG("setMain widget: %x", mMain);
		// TODO: Document why this line has been commented out.
		//setFocusedWidget(mMain);
	}


	Widget* Screen::getMain() {
		return mMain;
	}

	void Screen::hide() {
		//printf("hiding screen!\n");
		Environment& env = Environment::getEnvironment();
		if(env.isKeyListener(this)) {
			env.removeKeyListener(this);
		}
		if(env.isPointerListener(this)) {
			env.removePointerListener(this);
		}
		if(mMain) {
			mMain->setEnabled(false);
			Engine::getSingleton().setMain(NULL);
		}
		setFocusedWidget(NULL);
		if(sCurrentScreen == this)
			sCurrentScreen = NULL;
	}

	Screen::~Screen() {
		// TODO: Document why this code has been commented out.
		/*if(this == sCurrentScreen)
			Environment::getEnvironment().removeKeyListener(this); */
	}

	Screen* Screen::getCurrentScreen() {
		return sCurrentScreen;
	}

	Widget* getFocusableWidget(Widget *w) {
		if(w->isFocusable()) {
			return w;
		}

		const Vector<Widget*>& children = w->getChildren();
		for(int i = 0; i < children.size(); i++) {
			if(children[i]->isFocusable()) {
				return children[i];
			} 
			else {
				Widget* c = getFocusableWidget(children[i]);
				if(c) {
					return c;
				}
			}
		}
		return NULL;
	}

	void Screen::setFocusedWidget(Widget *w) {
		Widget *focus = w;
		if(mFocusedWidget) {
			mFocusedWidget->setFocused(false);
		}
		if(focus && !focus->isFocusable()) {
			focus = getFocusableWidget(focus);
		}
		mFocusedWidget = focus;

		if(mFocusedWidget) {
			mFocusedWidget->setFocused(true);
		}
		//MAUI_LOG("setFocusedWidget widget %x", focus);
	}

	Widget* Screen::getFocusedWidget() {
		return mFocusedWidget;
	}

	// TODO: don't forget to add support for overlays in these functions.
	void Screen::keyPressEvent(int keyCode, int nativeCode) {
		if(!mFocusedWidget) {
			mFocusedWidget = getFocusableWidget(mMain);
			mFocusedWidget->setFocused(true);
			//return;
		}

		if(mFocusedWidget) {
			InputPolicy* ip = mFocusedWidget->getInputPolicy();
			if(ip) {
				ip->keyPressed(keyCode, nativeCode);
			} 
			else {
				mFocusedWidget->keyPressed(keyCode, nativeCode);
			}
		}
	}
	
	void Screen::keyReleaseEvent(int keyCode, int nativeCode) {
		if(mFocusedWidget) {
			InputPolicy* ip = mFocusedWidget->getInputPolicy();
			if(ip) {
				ip->keyReleased(keyCode, nativeCode);
			} 
			else {
				mFocusedWidget->keyReleased(keyCode, nativeCode);
			}
		}
	}
	
	void Screen::pointerPressEvent(MAPoint2d point) {
		// If a key has been pressed previously focus has been gained, 
		// this should be removed now.
		setFocusedWidget(NULL); 
		Point p;
		Widget* root = Engine::getSingleton().currentOverlay(p);
		Widget* newFocus;
		if(root) {
			newFocus = root->focusableWidgetAt(point.x, point.y);
			if(!newFocus) {
				OverlayListener::OutsideResponse res =
					Engine::getSingleton().fireOverlayEvent(point.x, point.y);
				switch(res) {
					case OverlayListener::eBreak:
						return;
					case OverlayListener::eProceed:
						root = NULL;
				}
			}
		}
		if(!root) {
			root = mMain;
			newFocus = root->focusableWidgetAt(point.x, point.y);
		}

		if(newFocus) {
			setFocusedWidget(newFocus);
			InputPolicy* ip = mFocusedWidget->getInputPolicy();
			if(ip) {
				if(!ip->pointerPressed(point, 0)) {
					setFocusedWidget(NULL);
				}
			} 
			else {
				if(!newFocus->pointerPressed(point, 0)) {
					setFocusedWidget(NULL);
				}
			}
		}

	}
	
	void Screen::pointerReleaseEvent(MAPoint2d point) {
		bool keepFocus = false;
		if(mFocusedWidget) {
			InputPolicy* ip = mFocusedWidget->getInputPolicy();
			if(ip) {
				keepFocus = ip->pointerReleased(point, 0);
			} 
			else {
				mFocusedWidget->pointerPressed(point, 0);
			}
		}

		if(!keepFocus)
			setFocusedWidget(NULL);
	}
	
	void Screen::pointerMoveEvent(MAPoint2d point) {
		if(mFocusedWidget) {
			InputPolicy* ip = mFocusedWidget->getInputPolicy();
			if(ip) {
				if(!ip->pointerMoved(point, 0)) {
					setFocusedWidget(NULL);
				}
			} else {
				if(!mFocusedWidget->pointerMoved(point, 0)) {
					setFocusedWidget(NULL);
				}
			}
		}
	}
}
