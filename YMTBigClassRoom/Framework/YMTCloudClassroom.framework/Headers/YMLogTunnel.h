//
//  YMLogTunnel.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/12.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMXlogManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMLogTunnel : NSObject

/**
 输出日志
 @param logLevel      日志级别
 @param tag           TAG
 @param fileName      文件名称
 @param lineNumber    行数
 @param funcName      函数
 @param message       日志信息
 */
- (void)outPutLogLevel:(YMLogLevel)logLevel tag:(NSString *)tag fileName:(const char *)fileName lineNumber:(int)lineNumber funcName:(const char *)funcName message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
