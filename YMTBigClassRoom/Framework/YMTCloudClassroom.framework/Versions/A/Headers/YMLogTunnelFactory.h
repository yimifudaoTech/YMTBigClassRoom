//
//  YMLogTunnelFactory.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/12.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLogTunnel.h"

NS_ASSUME_NONNULL_BEGIN

@class YMLogTunnel,YMFileLogTunnel,YMSystemTerminalLogTunnel,YMBuglyLogTunnel,YMAppTerminalLogTunnel;

@interface YMLogTunnelFactory : NSObject

/**
 获取日志通道
 @return 日志通道
 */
- (YMFileLogTunnel *)getFileLogTunnel;
- (YMSystemTerminalLogTunnel *)getSystemTerminalLogTunnel;
- (YMBuglyLogTunnel *)getBuglyLogTunnel;
- (YMAppTerminalLogTunnel *)getAppTerminalLogTunnel;

/**
 根据日志级别获取对应的通道集合
 @param logLevel 日志级别
 @return 日志通道集合
 */
- (NSMutableArray <YMLogTunnel *> *)getLogTunnelsWithLogLevel:(YMLogLevel)logLevel;

@end

NS_ASSUME_NONNULL_END
