//
//  YMLogConfig.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/17.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMLogConfig : NSObject

// 日志策略
@property (nonatomic,assign,getter=getLogStrategyType)YMLogStrategyType strategyType;
// 日志级别
@property (nonatomic,assign,getter=getLogLevel)YMLogLevel logLevel;
// 日志的TAG
@property (nonatomic,copy,getter=getTag)NSString * tag;
// log文件路径
@property (nonatomic,copy,getter=getLogFilePath)NSString * logFilePath;
// 日志存活时长
@property (nonatomic,assign,getter=getLogMaxAliveDuration)u_int64_t aliveTime;

@end

NS_ASSUME_NONNULL_END
