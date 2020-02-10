//
//  YMPingbackSDK.h
//  YMPingbackSDK
//
//  Created by yimi on 2019/5/27.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMPBProtocol.h"
#import "YMQOSToolMacros.h"

@interface YMPingbackSDK : NSObject<YMPBProtocol>

+ (instancetype)sharedInstance;

+ (void)destroyInstance;
@end
