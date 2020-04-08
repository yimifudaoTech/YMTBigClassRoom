//
//  YMLogLevel.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/12.
//  Copyright © 2019 YiMi. All rights reserved.
//

// 日志级别和日志策略
#ifndef YMLogLevel_h
#define YMLogLevel_h

// 日志级别
typedef NS_ENUM(NSInteger, YMLogLevel) {
    YMLogLevelAll = 0,
    YMLogLevelVerbose = 0,
    YMLogLevelDebug,    // Detailed information on the flow through the system.
    YMLogLevelInfo,     // Interesting runtime events (startup/shutdown), should be conservative and keep to a minimum.
    YMLogLevelWarn,     // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    YMLogLevelError,    // Other runtime errors or unexpected conditions.
    YMLogLevelFatal,    // Severe errors that cause premature termination.
    YMLogLevelNone,     // Special level used to disable all log messages.
    YMLogLevelAssert,   // Debug模式下调试弹出自定义View日志
};

// 日志策略
typedef NS_ENUM(NSInteger, YMLogStrategyType) {
    YMLogStrategyDefaultType,
};

#endif /* YMLogLevel_h */
