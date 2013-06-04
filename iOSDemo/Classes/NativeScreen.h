//
//  ViewController.h
//  iOSDemo
//
//  Created by Bogdan Iusco on 6/4/13.
//
//

#import <UIKit/UIKit.h>

@protocol NativeScreenDelegate <NSObject>

@required
-(void)showMoSyncScreen;

@end

@interface NativeScreen : UIViewController
@property(nonatomic, assign) id<NativeScreenDelegate> delegate;

-(IBAction)btnClicked:(id)sender;

@end
