//
//  MoSyncScreen.h
//  iOSDemo
//
//  Created by Bogdan Iusco on 6/4/13.
//
//

#import <Foundation/Foundation.h>

#include "helpers/cpp_defs.h"

@protocol MoSyncScreenDelegate <NSObject>
@required

-(void)showNativeScreen;
@end

@interface MoSyncScreen : NSObject

@property(nonatomic, assign) MAHandle screenHandle;
@property(nonatomic, assign) id<MoSyncScreenDelegate> delegate;

@end
