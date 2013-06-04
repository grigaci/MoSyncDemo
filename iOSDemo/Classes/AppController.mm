//
//  AppController.mm
//  iOSDemo
//
//  Created by Bogdan Iusco on 6/4/13.
//
//

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
									 500);
//	maWidgetScreenShow(self.mosyncScreen.screenHandle);
}

#pragma mark MoSyncScreenDelegate
-(void)showNativeScreen {
//	self.window.rootViewController = self.nativeScreen;
	
    // after animation block
    void (^handleTransitionDoneBlock)(BOOL) = ^(BOOL isTransFinished) {
        if ( isTransFinished ) {
            // If needed in the future.
        }
    };

    // animation block
    void (^doAnimationBlock)(void) = ^(void) {
		self.window.rootViewController = self.nativeScreen;
    };

    [UIView transitionWithView:self.window
                      duration:0.5
                       options:UIViewAnimationOptionTransitionFlipFromRight
                    animations:doAnimationBlock completion:handleTransitionDoneBlock];
}


-(UIWindow*)window {
	if (!_window) {
		_window = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] retain];
	}
	return _window;
}

-(NativeScreen*)nativeScreen {
	if (!_nativeScreen) {
		_nativeScreen = [[NativeScreen alloc] initWithNibName:@"NativeScreen" bundle:nil];
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
