//
//  YMHttpSessionManager.h
//  YMTCloudClassroom
//
//  Created by 巨万里 on 2020/3/2.
//

#import <Foundation/Foundation.h>
#import <YMBaseLib/YMTHTTPSessionManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMHttpSessionManager : NSObject

+ (instancetype)shareManager;

- (YMTHTTPSessionManager *)getHTTPSessionManager;

@end

NS_ASSUME_NONNULL_END
