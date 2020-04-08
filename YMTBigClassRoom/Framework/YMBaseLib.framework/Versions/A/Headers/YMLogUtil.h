//
//  YMLogUtil.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/17.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLog.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMLogUtil : NSObject

@end

/**
 *  TAG Logging
 */
#define __FILENAME__ (strrchr(__FILE__,'/')+1)

#define YMLOG_DEBUG(tag, format, ...)   YMPrintLogInternal(YMLogLevelDebug, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Debug:", format, ##__VA_ARGS__)

#define YMLOG_INFO(tag, format, ...)    YMPrintLogInternal(YMLogLevelInfo, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Info:", format, ##__VA_ARGS__)

#define YMLOG_WARNING(tag, format, ...) YMPrintLogInternal(YMLogLevelWarn, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Warn:", format, ##__VA_ARGS__)

#define YMLOG_ERROR(tag, format, ...)   YMPrintLogInternal(YMLogLevelError, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Warn:", format, ##__VA_ARGS__)
// 自定义弹窗log
#define YMLOG_ASSERT(tag, format, ...)  YMPrintLogInternal(YMLogLevelAssert, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Assert:", format, ##__VA_ARGS__)

#define YMLOG_ALL(tag, format, ...)     YMPrintLogInternal(YMLogLevelAll, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Warn:", format, ##__VA_ARGS__)

#define YMLOG_VERBOSE(tag, format, ...) YMPrintLogInternal(YMLogLevelVerbose, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Verbose:", format, ##__VA_ARGS__)

#define YMLOG_FATAL(tag, format, ...)   YMPrintLogInternal(YMLogLevelFatal, tag, __FILENAME__, __LINE__, __FUNCTION__, @"Fatal:", format, ##__VA_ARGS__)

#define YMLOG_NONE(tag, format, ...)    YMPrintLogInternal(YMLogLevelNone, tag, __FILENAME__, __LINE__, __FUNCTION__, @"None:", format, ##__VA_ARGS__)

NS_ASSUME_NONNULL_END
