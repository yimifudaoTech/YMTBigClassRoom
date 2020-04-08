//
//  YMLogTunnelProtocol.h
//  YMBaseLib
//
//  Created by yimi on 2020/3/16.
//

#ifndef YMLogTunnelProtocol_h
#define YMLogTunnelProtocol_h

#import "YMLogLevel.h"

@protocol YMLogTunnelProtocol <NSObject>

@optional
/// 开启日志通道
- (void)startLogTunnel;

@optional
/// 关闭日志通道
- (void)closeLogTunnel;

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


#endif /* YMLogTunnelProtocol_h */
