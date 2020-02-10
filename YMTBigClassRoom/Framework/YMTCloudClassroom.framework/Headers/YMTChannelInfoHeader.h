//
//  ChannelInfoHeader.h
//  YiMiApp
//
//  Created by 周志强 on 2016/10/11.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#ifndef ChannelInfoHeader_h
#define ChannelInfoHeader_h


typedef NS_ENUM(NSInteger,YMResponseErrorType){
    YMResponseErrorType_API = 1,
    YMResponseErrorType_NETWORK,
};


typedef NS_ENUM(NSInteger, SocketSenderEventType) {
    SocketSenderEventType_Disconnect,       // socket断开连接
    SocketSenderEventType_ConnectTimeout,   // socket连接超时
    SocketSenderEventType_Connect,          // socket连接成功
    SocketSenderEventType_DataReceived,     // 收到消息
    SocketSenderEventType_Reconnecting,     // 重新连接中
    SocketSenderEventType_ReportConnectIP,  // 上报连接成功的ip
};
typedef void (^SocketSendCallBack)(SocketSenderEventType type, id data);
typedef void (^SocketSendDataResultCallBack)(BOOL result, id data);


typedef void (^SocketDataCallBack)(BOOL finished,NSInteger tag, id data);
typedef void (^ChannelOnlyDataCallBack)(id data);

typedef void (^ChannelDataCallBack)(int code, id data);
typedef void (^ChannelLessonDataCallBack)(int code, id data, YMResponseErrorType type);
typedef void (^ChannelDataOtherCallBack)(int code, id data,id otherData);
typedef void (^ChannelFail)(int code, NSString * msg);
typedef void (^ChannelSuccess)(int code, NSString * msg);
typedef void (^PlayerChanged)(NSInteger changed);

#endif /* ChannelInfoHeader_h */
