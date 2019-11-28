//
//  YMSDKConfig.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/10/29.
//

#import <Foundation/Foundation.h>
#import "YMClassRoomConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMSDKConfig : NSObject

@property (nonatomic, copy)NSString *appId;
@property (nonatomic, copy)NSString *appKey;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
