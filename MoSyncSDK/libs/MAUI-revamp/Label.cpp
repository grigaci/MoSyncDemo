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
* \file Label.cpp
* \brief Text label widget with alignment control.
* \author Patrick Broman and Niklas Nummelin
*/

#include <ma.h>
#include "Label.h"
#include "Font.h"
#include "Engine.h"
#include <mastdlib.h>
#include <conprint.h>

#include <mavsprintf.h>

#define LLOG(...) //printf

#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a):(b))
#endif

namespace MAUI {

	/**
	 * TODO: Document function.
	 * \param output TODO: Document param.
	 * \param font TODO: Document param.
	 * \param text TODO: Document param.
	 * \param bounds TODO: Document param.
	 */
	static void cutText(
		String& output, 
		Font* font, 
		const String& text, 
		Rect bounds)
	{
		output.clear();
		const Charset& cs = font->getCharset();
		const unsigned char *str = (const unsigned char*)text.c_str();
		int w = bounds.width;
		int x = bounds.x;
		int i = 0;
		while(*str) {
			const CharDescriptor& cd = cs.chars[*str];
			if(x+cd.xAdvance>w) {
				int numDots = 3;
				if(i<3) numDots = i;
				output.resize(i-numDots);
				memcpy(&output[0], text.c_str(), i-numDots);
				output.append("...", numDots);
				return;
			} 
			else {
				i++;
			}
			x+=cd.xAdvance;
			str++;
		}
		output = text;
	}

	// TODO: Document why this is ifdefed away or delete.
	#if 0
	static int brightenColor(int c, int ammount) {
		int retc;
		unsigned char* col = (unsigned char *)&c;
		unsigned char* retCol = (unsigned char *)&retc;

		int r = MIN(((int)col[0])+ammount, 255);
		int g = MIN(((int)col[1])+ammount, 255);
		int b = MIN(((int)col[2])+ammount, 255);

		retCol[0] = (char)r;
		retCol[1] = (char)g;
		retCol[2] = (char)b;
		retCol[3] = col[3];
		return retc;
	}
	#endif

	Label::Label(int x, int y, int width, int height, const String &caption) :
		Widget(x, y, width, height),
		// TODO: Document why this is commented out or delete.
	//	mMustCalcStrSize(true),
		mCaption(""),
		mAutoSizeX(false),
		mAutoSizeY(false),
		mMultiLine(false),
		mHorizontalAlignment(HA_LEFT),
		mVerticalAlignment(VA_TOP)
	{
		// TODO: Document why this is commented out or delete.
		/*if(!font)
		{
			this->mFont = Engine::getSingleton().getDefaultFont();
		} else {
			this->mFont = font;
		} */

		setCaption(caption);
		// TODO: Document why this is commented out or delete.
		//this->setBackgroundColor(backColor);
		//calcStrSize();
	}

	void Label::calcStrSize() {
		Rect tempRect = Rect(0, 0, mPaddedBounds.width, mPaddedBounds.height);
		if(!mFont) {
			mStrSize = EXTENT(0,0);
		} 
		else {
			if(mAutoSizeX) {
				mStrSize = mFont->getStringDimensions(mCaption.c_str());
			}
			else {
				if(mMultiLine) {
					mStrSize = mFont->getBoundedStringDimensions(
						mCaption.c_str(), tempRect);
				} 
				else {
					cutText(mCuttedCaption, mFont, mCaption, tempRect);
					mStrSize = mFont->getStringDimensions(
						mCuttedCaption.c_str());
				}
			}
		}
		mStrWidth  = EXTENT_X(mStrSize);
		mStrHeight = EXTENT_Y(mStrSize);

		if(mAutoSizeX) {
			resize(mStrWidth + mPaddingLeft + mPaddingRight, mBounds.height);
		}
		if(mAutoSizeY) {
			resize(mBounds.width,  mStrHeight + mPaddingTop + mPaddingBottom);
		}
	}

	void Label::setMultiLine(bool b) {
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		requestUpdate();
		mMultiLine = b;
	}

	bool Label::isMultiLine() {
		return mMultiLine;
	}

	// TODO: Document why this is commented out or delete.
	/*
	void Label::setPaddingLeft(int l) {
		Widget::setPaddingLeft(l);
		//calcStrSize();
		requestUpdate();
	}

	void Label::setPaddingTop(int t) {
		Widget::setPaddingTop(t);
		//calcStrSize();
		requestUpdate();
	}

	void Label::setPaddingRight(int r) {
		Widget::setPaddingRight(r);
		//calcStrSize();
		requestUpdate();
	}

	void Label::setPaddingBottom(int b) {
		Widget::setPaddingBottom(b);
		//calcStrSize();
		requestUpdate();
	}
	*/

	void Label::resize(int width, int height) {
		Widget::setWidth(width);
		Widget::setHeight(height);
	}

	// TODO: Document why this is commented out or delete.
	/*
	void Label::setWidth(int width) {
		Widget::setWidth(width);
		requestUpdate();
	}

	void Label::setHeight(int height) {
		Widget::setHeight(height);
		requestUpdate();
	}
	*/

	void Label::getTextStart(int *x, int *y) {
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		if(!mAutoSizeX) {
			switch(mHorizontalAlignment) {
				case HA_LEFT: 
					*x = 0; 
					break;
				case HA_CENTER: 
					*x = (mPaddedBounds.width)/2 - (mStrWidth/2);
					break;
				case HA_RIGHT: 
					*x = (mPaddedBounds.width) - (mStrWidth); 
					break;
			}
		}

		if(!mAutoSizeY) {
			switch(mVerticalAlignment) {
				case VA_TOP: 
					*y = 0; 
					break;
				case VA_CENTER: 
					*y = (mPaddedBounds.height)/2 - (mStrHeight/2); 
					break;
				case VA_BOTTOM: 
					*y = (mPaddedBounds.height) - (mStrHeight); 
					break;
			}
		}
	}

	void Label::updateInternal() {
		calcStrSize();
	}

	void Label::drawWidget() {
		const char* wStr = mCaption.c_str();
		int textX=0, textY=0;
		getTextStart(&textX, &textY);
		if(mFont) {
			if(mMultiLine) {
				Rect tempRect = Rect(0, 0, mPaddedBounds.width, mPaddedBounds.height);
				mFont->drawBoundedString(wStr, textX, textY, tempRect);
			} 
			else {
				if(mAutoSizeX) {
					mFont->drawString(wStr, textX, textY);
				}
				else {
					mFont->drawString(mCuttedCaption.c_str(), textX, textY);
				}
			}
		}
		else {
			MAUI_LOG("MISSING A FONT!!!");
		}
	}

	void Label::setHorizontalAlignment(Label::HorizontalAlignment alignment) {
		this->mHorizontalAlignment = alignment;
		requestRepaint();
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		requestUpdate();
	}

	Label::HorizontalAlignment Label::getHorizontalAlignment() const {
		return mHorizontalAlignment;
	}

	void Label::setVerticalAlignment(Label::VerticalAlignment alignment) {
		this->mVerticalAlignment = alignment;
		requestRepaint();
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		requestUpdate();
	}

	Label::VerticalAlignment Label::getVerticalAlignment() const {
		return mVerticalAlignment;
	}

	void Label::setAutoSizeX(bool f) {
		this->mAutoSizeX = f;
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		requestUpdate();
		requestRepaint();
	}

	void Label::setAutoSizeY(bool f) {
		this->mAutoSizeY = f;
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		requestUpdate();
		requestRepaint();
	}

	bool Label::getAutoSizeX() const {
		return mAutoSizeX;
	}

	bool Label::getAutoSizeY() const {
		return mAutoSizeY;
	}

	void Label::setCaption(const String& mCaption) {
		this->mCaption = mCaption;
		requestRepaint();
		// TODO: Document why this is commented out or delete.
		//calcStrSize();
		requestUpdate();
	}

	const String& Label::getCaption() const {
		return mCaption;
	}

	bool Label::isTransparent() const {
		return true;
	}

	void Label::restyle() {
		//MAUI_LOG("***** restyle called!!!");
		//MAUI_LOG("Label's style: 0x%x", getStyle());
		if(getStyle() == NULL)
			setStyle(Engine::getSingleton().getDefaultStyle("Label"));

		const LabelStyle* style = (const LabelStyle*)getStyle();
		mFont = style->getSafe<FontProperty>("font");

		requestUpdate();

		Widget::restyle();

		requestRepaint();
	}

	LabelStyle::LabelStyle(
		FontProperty* font,
		int paddingLeft,
		int paddingRight,
		int paddingTop,
		int paddingBottom,
		DrawableProperty* backgroundSkinFocused,
		DrawableProperty* backgroundSkinUnfocused) : 
			Style(
				paddingLeft, 
				paddingRight, 
				paddingTop, 
				paddingBottom,
				backgroundSkinFocused, 
				backgroundSkinUnfocused)
	{
		this->mProperties["font"] = font;
	}
}
