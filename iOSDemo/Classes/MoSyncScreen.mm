/* Copyright (C) 2013 MoSync AB
 
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

#define BUTTON_WIDTH_PERCENTAGE 1.6
#define BUTTON_HEIGHT_PERCENTAGE 10.0
#define BUTTON_X_COORD 2
#define BUTTON_Y_COORD 2
#define BUTTON_TEXT "Show native screen"

#import "MoSyncScreen.h"

#import "NativeUI/Base/MoSyncUI.h"
#import "NativeUI/Screens/ScreenWidget.h"
#import "NativeUI/Syscalls/MoSyncUISyscalls.h"
#import "NativeUI/Widgets/ButtonWidget.h"

@interface MoSyncScreen()

@property(nonatomic, retain) ScreenWidget* screenWidget;

@end


@implementation MoSyncScreen

@synthesize screenHandle;
@synthesize screenWidget = _screenWidget;
@synthesize delegate;

-(id)init {
	self = [super init];
	if (self) {
		[self createScreenWidget];
	}
	return self;
}

-(void)createScreenWidget {
	self.screenHandle = maWidgetCreate(MAW_SCREEN);

	// Create and add layout.
	int layoutHandle = maWidgetCreate(MAW_RELATIVE_LAYOUT);
	maWidgetAddChild(self.screenHandle, layoutHandle);

	// Calculate button size and position.
	MAExtent screenSize = maGetScrSize();
	float screenWidth = EXTENT_X(screenSize);
	float screenHeight = EXTENT_Y(screenSize);
	int buttonWidth = screenWidth / BUTTON_WIDTH_PERCENTAGE;
	int buttonHeight = screenHeight / BUTTON_HEIGHT_PERCENTAGE;
	int xPos = (screenWidth - buttonWidth) / BUTTON_X_COORD;
	int yPos = screenHeight - (BUTTON_Y_COORD * buttonHeight);

	// Create and add button.
	int buttonHandle = maWidgetCreate(MAW_BUTTON);
	maWidgetSetProperty(buttonHandle,
						MAW_WIDGET_WIDTH,
						[[NSString stringWithFormat:@"%d", buttonWidth] UTF8String]);
	maWidgetSetProperty(buttonHandle,
						MAW_WIDGET_HEIGHT,
						[[NSString stringWithFormat:@"%d", buttonHeight] UTF8String]);
	
	maWidgetSetProperty(buttonHandle,
						MAW_WIDGET_TOP,
						[[NSString stringWithFormat:@"%d", yPos] UTF8String]);
	maWidgetSetProperty(buttonHandle,
						MAW_WIDGET_LEFT,
						[[NSString stringWithFormat:@"%d", xPos] UTF8String]);
	maWidgetSetProperty(buttonHandle,
						MAW_BUTTON_TEXT,
						BUTTON_TEXT);
	maWidgetAddChild(layoutHandle, buttonHandle);

	// Listen for touch up events.
	MoSyncUI* mosyncUI = getMoSyncUI();
	ButtonWidget* buttonWidget = (ButtonWidget*)[mosyncUI getWidget:buttonHandle];
	UIButton* nativeButton = (UIButton*)buttonWidget.view;
    [nativeButton addTarget:self
					 action:@selector(btnClicked)
		   forControlEvents:UIControlEventTouchUpInside];
}

-(void)btnClicked {
	[self.delegate showNativeScreen];
}

-(void)dealloc {
	maWidgetDestroy(screenHandle);
	[_screenWidget release];
	[super dealloc];
}

@end
