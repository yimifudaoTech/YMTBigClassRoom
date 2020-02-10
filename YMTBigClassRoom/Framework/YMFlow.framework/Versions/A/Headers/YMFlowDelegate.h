//
//  YMFlowStatusDelegate.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//

#ifndef YMFlowDelegate_h
#define YMFlowDelegate_h

typedef NS_ENUM(NSInteger, YMFlowStatus) {
    YMFlowStatusUnkown = -1,
    YMFlowStatusUnavailable = 0,
    YMFlowStatusGateWayFailed = 1,
    YMFlowStatusServerFailed = 2,
    YMFlowStatusConnecting = 3,
    YMFlowStatusConnected = 4,
    YMFlowStatusServerDown = 5
};

typedef NS_ENUM(NSInteger, YMFlowErrCmdType) {
    YMFlowErrCmdTypeOK = 0,
    YMFlowErrCmdTypeFalse = 1,
    YMFlowErrCmdTypeDial = 2,
    YMFlowErrCmdTypeDns = 3,
    YMFlowErrCmdTypeSocket = 4,
    YMFlowErrCmdTypeHttp = 5,
    YMFlowErrCmdTypeNetMsgXP = 6,
    YMFlowErrCmdTypeEnDecode = 7,
    YMFlowErrCmdTypeServer = 8,
    YMFlowErrCmdTypeLocal = 9,
    YMFlowErrCmdTypeCanceld = 10,
};

typedef NS_ENUM(NSUInteger, YMFlowLongConnectStatus) {
    YMFlowLongConnectStatusIdle = 0,
    YMFlowLongConnectStatusConnecting = 1,
    YMFlowLongConnectStatusConnected = 2,
    YMFlowLongConnectStatusDisconnected = 3,
    YMFlowLongConnectStatusConnectFailed = 4,
};

@protocol YMFlowDelegate <NSObject>

@optional
/**
 网络层向上层反馈网络连接状态

 @param status 综合状态，即长连+短连的状态
 @param longConnStatus 长连状态
 */
- (void)onConnectionStatusChange:(YMFlowStatus)status longConnStatus:(YMFlowStatus)longConnStatus;


@required
/**
 网络层向上层反馈长连接状态
 如果只监控长连接状态，建议实现此方法

 @param status 长连接状态
 */
- (void)onLongLinkStatusChange:(YMFlowLongConnectStatus)status;


/**
 网络层向上反馈网络错误状态
 
 @param errType 错误类型
 @param errCode 错误码
 @param ip IP地址
 @param port 端口
 */
- (void)onNetworkError:(YMFlowErrCmdType)errType errCode:(int)errCode ip:(NSString *)ip port:(int)port;


/**
 网络层需要Dns

 @param host 域名
 @return host对应的dns
 */
- (NSArray *)onNewDns:(NSString *)host;


/**
 发生Socket连接时，实时上报新连接的 IP/Port

 @param ip ip地址
 @param port 端口
 */
- (void)onLongLinkIPPortReport:(NSString *)ip prot:(int)port;

@end

#endif /* YMFlowDelegate_h */
