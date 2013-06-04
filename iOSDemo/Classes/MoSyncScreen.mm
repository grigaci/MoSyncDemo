//
//  MoSyncScreen.mm
//  iOSDemo
//
//  Created by Bogdan Iusco on 6/4/13.
//
//

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
	self.screenHandle = maWidgetCreate("Screen");

	// Create and add layout.
	int layoutHandle = maWidgetCreate("RelativeLayout");
	maWidgetAddChild(self.screenHandle, layoutHandle);

	// Calculate button sizes.
	MAExtent screenSize = maGetScrSize();
	float screenWidth = EXTENT_X(screenSize);
	float screenHeight = EXTENT_Y(screenSize);
	int buttonWidth = screenWidth / 1.6;
	int buttonHeight = screenHeight / 10.0;
	int xPos = (screenWidth - buttonWidth) / 2;
	int yPos = screenHeight - (2 * buttonHeight);

	// Create and add button.
	int buttonHandle = maWidgetCreate("Button");
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
						MAW_BUTTON_TEXT, "Show native screen");
	maWidgetAddChild(layoutHandle, buttonHandle);

	// Listen for touch down events.
	MoSyncUI* mosyncUI = getMoSyncUI();
	ButtonWidget* buttonWidget = (ButtonWidget*)[mosyncUI getWidget:buttonHandle];
	UIButton* nativeButton = (UIButton*)buttonWidget.view;
    [nativeButton addTarget:self action:@selector(btnClicked) forControlEvents:UIControlEventTouchDown];
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
