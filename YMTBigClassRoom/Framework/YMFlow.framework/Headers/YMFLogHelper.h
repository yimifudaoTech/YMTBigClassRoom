//
//  YMFLogHelper.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2016年 caoshaokun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, YMFLogLevel) {
    YMFLogLevelAll = 0,
    YMFLogLevelVerbose = 0,
    YMFLogLevelDebug,    // Detailed information on the flow through the system.
    YMFLogLevelInfo,     // Interesting runtime events (startup/shutdown), should be conservative and keep to a minimum.
    YMFLogLevelWarn,     // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    YMFLogLevelError,    // Other runtime errors or unexpected conditions.
    YMFLogLevelFatal,    // Severe errors that cause premature termination.
    YMFLogLevelNone,     // Special level used to disable all log messages.
};

@interface YMFLogHelper : NSObject

/** 开启日志，文件在默认目录 */
+ (void)startXlog;
/** 开启日志，使用指定目录 */
+ (void)startXlogWithPath:(NSString *)logPath;
/** 关闭日志 */
+ (void)closeXlog;
/** 日志保留的最长期限 */
+ (void)setXlogMaxAliveDuration:(u_int64_t)aliveTime;
/** 异步将缓存日志r写入文件 */
+ (void)flush;
/** 同步将缓存日志写入文件 */
+ (void)flushSync;
/**
 记录日志

 @param logLevel 日志等级
 @param moduleName 日志所属模块
 @param fileName 当前输出日志的代码文件名
 @param lineNumber 当前输出日志的代码的行号
 @param funcName 当前输出日志所在的方法名
 @param message 日志内容
 */
+ (void)logWithLevel:(YMFLogLevel)logLevel moduleName:(const char*)moduleName fileName:(const char*)fileName lineNumber:(int)lineNumber funcName:(const char*)funcName message:(NSString *)message;

/**
 记录日志

 @param logLevel 日志等级
 @param moduleName 日志所属模块
 @param fileName 当前输出日志的代码文件名
 @param lineNumber 当前输出日志的代码的行号
 @param funcName 当前输出日志所在的方法名
 @param format 格式化的日志内容
 */
+ (void)logWithLevel:(YMFLogLevel)logLevel moduleName:(const char*)moduleName fileName:(const char*)fileName lineNumber:(int)lineNumber funcName:(const char*)funcName format:(NSString *)format, ...;

+ (BOOL)shouldLog:(YMFLogLevel)level;

/** 默认的日志文件目录 */
+ (NSString *)defaultLogFilePath;

@end

#define YMFLogInternal(level, module, file, line, func, prefix, format, ...) \
do { \
    if ([YMFLogHelper shouldLog:level]) { \
        NSString *aMessage = [NSString stringWithFormat:@"%@%@", prefix, [NSString stringWithFormat:format, ##__VA_ARGS__, nil]]; \
        [YMFLogHelper logWithLevel:level moduleName:module fileName:file lineNumber:line funcName:func message:aMessage]; \
    } \
} while(0)

#define YMFlogFilePath [YMFLogHelper logFilePath]
