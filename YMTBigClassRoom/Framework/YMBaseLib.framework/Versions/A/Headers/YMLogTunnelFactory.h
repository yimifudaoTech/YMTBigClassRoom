//
//  YMLogTunnelFactory.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/12.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLogLevel.h"
#import "YMLogTunnelProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class YMLogTunnel,YMFileLogTunnel,YMSystemTerminalLogTunnel,YMBuglyLogTunnel,YMAppTerminalLogTunnel;

@interface YMLogTunnelFactory : NSObject

/**
 获取日志通道
 @return 日志通道
 */
- (id<YMLogTunnelProtocol>)getFileLogTunnel;
- (id<YMLogTunnelProtocol>)getSystemTerminalLogTunnel;
- (id<YMLogTunnelProtocol>)getBuglyLogTunnel;
- (id<YMLogTunnelProtocol>)getAppTerminalLogTunnel;
- (id<YMLogTunnelProtocol>)getXlogTunnel;

/**
 根据日志级别获取对应的通道集合
 @param logLevel 日志级别
 @return 日志通道集合
 */
- (NSMutableArray <id<YMLogTunnelProtocol>> *)getLogTunnelsWithLogLevel:(YMLogLevel)logLevel;


/// 获取所有通道集合
- (NSMutableArray <id<YMLogTunnelProtocol>> *)getAllLogTunnels;

@end

NS_ASSUME_NONNULL_END
