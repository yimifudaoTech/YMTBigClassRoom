//
//  LogUtil.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2016年 caoshaokun. All rights reserved.
//

#import "YMFLogHelper.h"

#define __FILENAME__ (strrchr(__FILE__,'/')+1)

/**
 *  Module Logging
 */
#define YMFLOG_ERROR(module, format, ...) YMFLogInternal(YMFLogLevelError, module, __FILENAME__, __LINE__, __FUNCTION__, @"Error:", format, ##__VA_ARGS__)
#define YMFLOG_WARNING(module, format, ...) YMFLogInternal(YMFLogLevelWarn, module, __FILENAME__, __LINE__, __FUNCTION__, @"Warning:", format, ##__VA_ARGS__)
#define YMFLOG_INFO(module, format, ...) YMFLogInternal(YMFLogLevelInfo, module, __FILENAME__, __LINE__, __FUNCTION__, @"Info:", format, ##__VA_ARGS__)
#define YMFLOG_DEBUG(module, format, ...) YMFLogInternal(YMFLogLevelDebug, module, __FILENAME__, __LINE__, __FUNCTION__, @"Debug:", format, ##__VA_ARGS__)

static const char *kYMFlowTAG = "YMFlow";
