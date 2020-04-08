//
//  YMLog.h
//  YMLogLib
//
//  Created by juwanli on 2019/8/29.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMXlogManager.h"

NS_ASSUME_NONNULL_BEGIN

@class YMLogConfig,YMLogStrategy;

@interface YMLog : NSObject

+ (YMLog *)shareLogInstance;


/// 开启日志
- (void)startLog;


/// 关闭日志
- (void)closeLog;

/**
 初始化日志配置
 @param config 配置 包括：日志级别、TAG、日志文件路径、日志保留天数、策略
 @param strategy 日志策略
 */
- (void)initYMlogWithConfig:(YMLogConfig *)config logStrategy:(YMLogStrategy *)strategy;

/**
 日志的输出
 @param logLevel    日志级别
 @param tag         TAG
 @param fileName    文件名称
 @param lineNumber  行数
 @param funcName    函数
 @param message     日志信息
 */
- (void)printYMlogLevel:(YMLogLevel)logLevel logTag:(NSString *)tag fileName:(const char *)fileName lineNumber:(int)lineNumber funcName:(const char *)funcName logMessage:(NSString *)message;


/// 显示应用内控制台
- (void)showAppTerminal;
/**
 获取日志文件
 */
- (void)getYMlogFileCompleteBlock:(void(^)(BOOL success, NSString * filePath, NSString * fileName))completeBlock;

- (void)shareYMLogFile:(UIView *)parentView;

@end

#define YMPrintLogInternal(level, tag, file, line, func, prefix, format, ...) \
do { \
    NSString * aMessage = [NSString stringWithFormat:@"%@%@", prefix, [NSString stringWithFormat:format, ##__VA_ARGS__, nil]]; \
    [[YMLog shareLogInstance] printYMlogLevel:level logTag:tag fileName:file lineNumber: line funcName:func logMessage:aMessage];\
} while(0)

NS_ASSUME_NONNULL_END
