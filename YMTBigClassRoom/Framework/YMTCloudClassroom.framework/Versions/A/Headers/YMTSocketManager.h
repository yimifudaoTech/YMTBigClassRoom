//
//  GPLSocketManager.h
//  YiMiApp
//
//  Created by Han on 2016/10/19.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTChannelInfoHeader.h"

@interface YMTSocketManager : NSObject

/**
 开始连接服务器
 
 @param mainIP 主IP
 @param dnsIPs dns列表
 @param port 端口
 @param callBack 回调
 */
- (void)startConnectWithMainIP:(NSString*)mainIP
                        dnsIPs:(NSArray *)dnsIPs
                        onPort:(int)port
                      callBack:(SocketSendCallBack)callBack;

/**
 发送数据
 
 @param data 数据原型
 */
- (void)sendData:(NSString *)data callBack:(SocketSendDataResultCallBack)callBack;

/**
 断开连接
 */
- (void)disconnect;

@end
