//
//  YMPingbackSDK.h
//  YMPingbackSDK
//
//  Created by yimi on 2019/5/27.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMPBProtocol.h"

@interface YMPingbackSDK : NSObject

+ (id<YMPBProtocol>_Nonnull)sharedInstance:(NSString *_Nonnull)instanceKey;

+ (void)destroyInstance:(NSString *_Nonnull)instanceKey;

+ (id<YMPBProtocol>_Nonnull)defaultInstance;

+ (void)destroyDefaultInstance;

@end
