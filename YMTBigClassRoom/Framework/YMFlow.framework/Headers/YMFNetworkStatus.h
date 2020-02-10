//
//  YMFTaskNetworkStatus.m
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Tencet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMFNetworkStatusDelegate.h"

@interface YMFNetworkStatus : NSObject {
	__weak id<YMFNetworkStatusDelegate> m_delNetworkStatus;
}

+ (YMFNetworkStatus*)sharedInstance;

- (void)start:(id<YMFNetworkStatusDelegate>)delNetworkStatus;
- (void)stop;
- (void)ChangeReach;

@end
