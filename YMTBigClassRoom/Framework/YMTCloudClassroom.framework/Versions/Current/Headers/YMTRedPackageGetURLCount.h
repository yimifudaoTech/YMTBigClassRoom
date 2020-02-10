//
//  YMTRedPackageGetURLCount.h
//  AFNetworking
//
//  Created by SendomZhang on 5/9/2019.
//

#import "YMTRedPackageGetCount.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMTRedPackageGetURLCount : YMTRedPackageGetCount<NSURLSessionDelegate>

/// 拉去红包地址
@property (nonatomic, strong, readwrite) NSString *url;

@end

NS_ASSUME_NONNULL_END
