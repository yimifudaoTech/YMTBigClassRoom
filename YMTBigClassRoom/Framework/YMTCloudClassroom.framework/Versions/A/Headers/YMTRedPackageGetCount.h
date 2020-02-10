//
//  YMTRedPackageGetCount.h
//  AFNetworking
//
//  Created by SendomZhang on 5/9/2019.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^YMTRedPackageGetCountHandle)(int count);

@interface YMTRedPackageGetCount : NSObject

/// 获取红包策略回调
@property (nonatomic, copy, readwrite) YMTRedPackageGetCountHandle getCountHandle;

- (void)getRedPackageCount:(NSDictionary *)content;

@end

NS_ASSUME_NONNULL_END
