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

#define TRANSITION_TIME_MS 500
#define TRANSITION_TIME_S 0.5

#define XIB_FILE_IPHONE @"NativeScreen_iPhone"
#define XIB_FILE_IPAD @"NativeScreen_iPad"

#import "AppController.h"

#import "NativeUI/Base/MoSyncUI.h"
#import "NativeUI/Screens/ScreenWidget.h"
#import "NativeUI/Syscalls/MoSyncUISyscalls.h"

@interface AppController()

@property(nonatomic, readonly, retain) UIWindow* window;
@property(nonatomic, readonly, retain) NativeScreen* nativeScreen;
@property(nonatomic, readonly, retain) MoSyncScreen* mosyncScreen;

@end

@implementation AppController

@synthesize window = _window;
@synthesize nativeScreen = _nativeScreen;
@synthesize mosyncScreen = _mosyncScreen;

#pragma mark NativeScreenDelegate
-(void)showMoSyncScreen {
	maWidgetScreenShowWithTransition(self.mosyncScreen.screenHandle,
									 MAW_TRANSITION_TYPE_FLIP_FROM_LEFT,
									 TRANSITION_TIME_MS);
}

#pragma mark MoSyncScreenDelegate
-(void)showNativeScreen {

	// Animation block.
    void (^doAnimationBlock)(void) = ^(void) {
		self.window.rootViewController = self.nativeScreen;
    };

    [UIView transitionWithView:self.window
                      duration:TRANSITION_TIME_S
                       options:UIViewAnimationOptionTransitionFlipFromRight
                    animations:doAnimationBlock
					completion:nil];
}

-(UIWindow*)window {
	if (!_window) {
		_window = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] retain];
	}
	return _window;
}

-(NativeScreen*)nativeScreen {
	if (!_nativeScreen) {
		NSString* nibFileName;
		if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
			nibFileName = XIB_FILE_IPHONE;
		} else {
			nibFileName = XIB_FILE_IPAD;
		}

		_nativeScreen = [[NativeScreen alloc] initWithNibName:nibFileName bundle:nil];
		_nativeScreen.delegate = self;
	}
	return _nativeScreen;
}

-(MoSyncScreen*)mosyncScreen {
	if (!_mosyncScreen) {
		_mosyncScreen = [[MoSyncScreen alloc] init];
		_mosyncScreen.delegate = self;
	}
	return _mosyncScreen;
}

-(void)dealloc {
	[_window release];
	[_nativeScreen release];
	[_mosyncScreen release];

	[super dealloc];
}
@end
