//
//  YMFlowTask.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 有效
 */
static const int YMF_VALID = 0;

/**
 * 无效/error
 */
static const int YMF_INVALID = -1;

/**
 * the cmd id for sending msg from client to server.
 *
 * 注意：来自于server的push消息的cmdId也为1001, 但是push消息的taskId永远为0,
 * 客户端发送的消息的TaskID不为0.
 */
static const int YMF_CMD_ID_MSG = 1001;

/**
 * 1002 未定义，备用
 */
static const int YMF_CMD_ID_ = 1002;

/**
 * 流量统计
 */
static const int YMF_CMD_ID_PUSH_TRAFFIC = 1003;

/**
 * CGI请求历史
 */
static const int YMF_CMD_ID_PUSH_CGI_HISTORY = 1004;

/**
 * 信令探测
 */
static const int YMF_CMD_ID_PUSH_SIGNAL_DETECT = 1005;

/**
 * 链接信息
 */
static const int YMF_CMD_ID_PUSH_CONNECT_INFO = 1006;

typedef enum : int32_t {
    YMFTaskChannelType_ShortConn = 1,
    YMFTaskChannelType_LongConn = 2,
    YMFTaskChannelType_All = 3
} YMFTaskChannelType;

@interface YMFlowTask : NSObject

- (id)init;

- (id)initAll:(YMFTaskChannelType)channelType andCmdId:(uint32_t)cmdId andCGIUri:(NSString*)cgiUri andHost:(NSString*)host;

@property(nonatomic, assign) uint32_t taskid;
@property(nonatomic, assign) YMFTaskChannelType channelType;
@property(nonatomic, assign) uint32_t cmdid;
@property(nonatomic, copy) NSString *cgi;
@property(nonatomic, copy) NSString *host;

/** request 内容 */
@property (nonatomic, copy) NSString *request;
/** response 内容 */
@property (nonatomic, copy) NSString *response;
/** 任务错误类型 */
@property(nonatomic, assign) int errType;
/** 任务错误码 */
@property(nonatomic, assign) int errCode;

@end
