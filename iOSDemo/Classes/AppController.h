//
//  AppController.h
//  iOSDemo
//
//  Created by Bogdan Iusco on 6/4/13.
//
//

#import <Foundation/Foundation.h>

#import "NativeScreen.h"
#import "MoSyncScreen.h"

@interface AppController : NSObject <NativeScreenDelegate, MoSyncScreenDelegate>


@end
