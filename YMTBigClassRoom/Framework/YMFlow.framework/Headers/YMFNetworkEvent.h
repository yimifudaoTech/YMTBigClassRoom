//
//  YMFNetworkEvent.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 caoshaokun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "YMFNetworkDelegate.h"

@interface YMFNetworkEvent : NSObject<YMFNetworkDelegate> {
    NSMapTable *tasks;
    NSMapTable *controllers;
    NSMapTable *pushrecvers;
}

@property (nonatomic, weak) id<YMFlowDelegate> flowCallback;

@end
