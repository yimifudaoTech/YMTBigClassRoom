//
//  YMXlogManager.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/17.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMXlogManager : NSObject

+ (YMXlogManager *)shareXlogInstance;

/**
 启动日志
 */
- (void)startXlog;

/**
 关闭日志，在程序退出时调用
 */
- (void)closeXlog;

/**
 设置日志最大的保存期限，超过后将被清除 默认是10天
 */
- (void)setMaxAliveDuration;

/**
 异步将缓存日志写入文件
 */
- (void)flush;

/**
 同步将缓存日志写入文件
 */
- (void)flushSync;

/**
 日志信息写入文件
 @param logLevel        日志级别
 @param tagName         TAG
 @param fileName        文件名称
 @param lineNumber      行数
 @param funcName        函数
 @param message         日志信息
 */
+ (void)initLogWithLevel:(YMLogLevel)logLevel tagName:(const char *)tagName fileName:(const char *)fileName lineNumber:(int)lineNumber funcName:(const char *)funcName message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
