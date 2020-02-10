//
//  YMTIMModule.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/11/16.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTSCHttpRequests.h"
#import "YMTSCEntityDatas.h"

#import "YMTSCServerHeader.h"

@class YMTIMModule;

typedef NS_ENUM(NSInteger,GPLSCServerConnectResult) {
    GPLSCServerConnectResultSuccess,    // 链接成功
    GPLSCServerConnectResultFail,       // 链接失败
    GPLSCServerConnectResultEnd,        // 链接结束
    GPLSCServerConnectResultRepeat      // 重新链接
};

@protocol YMTIMModuleDelegate <NSObject>

@required
/**
 获取服务端消息
 
 @param serverManager 管理类
 @param context 消息管理模型。所有数据
 @param isRealTime 实时/同步 消息
 */
- (void)YMTIMModule:(YMTIMModule *)serverManager
            context:(YMTSCSendMsgEntity *)context
         isRealTime:(BOOL)isRealTime;

/**
 发送的消息服务端已收到
 
 @param serverManager 管理类
 @param context 服务端收到的消息
 */
- (void)YMTIMModule:(YMTIMModule *)serverManager
    realSendContext:(YMTSCSendMsgEntity *)context;

/**
 同步回调

 @param serverManager 管理类
 @param isSyncDone 是否同步完成
 */
- (void)YMTIMModule:(YMTIMModule *)serverManager
         isSyncDone:(BOOL)isSyncDone;

@optional

/**
 连接状态变化

 @param serverManager 管理类
 @param connectModel 当前IP
 @param connectResult 连接状态
 */
- (void)YMTIMModule:(YMTIMModule *)serverManager
       connectModel:(YMTSCServerIpModel *)connectModel
      connectResult:(GPLSCServerConnectResult)connectResult;

/**
 重连IP上报
 
 @param serverManager 管理类
 @param connectModel 重连IP
 */
- (void)YMTIMModule:(YMTIMModule *)serverManager
    reportReconnectIp:(YMTSCServerIpModel *)connectModel;

@end

@interface YMTIMModule : NSObject

@property(nonatomic, weak) id<YMTIMModuleDelegate> delegate;


/// 初始化IM模块
/// @param lessonId 课程ID
/// @param mainIP 主IP
/// @param dnsIPs 备选IP列表
/// @param token 用来做用户校验
- (instancetype)initWithLessonId:(NSString *)lessonId
                          mainIP:(YMTSCServerIpModel *)mainIP
                          dnsIPs:(NSArray<YMTSCServerIpModel *> *)dnsIPs
                           token:(NSString *)token;


/// 初始化IM模块
/// @param lessonId  课程ID
/// @param uid 用户ID
/// @param mainIP 主IP
/// @param dnsIPs 备选IP列表
/// @param token 用来做用户校验
- (instancetype)initWithLessonId:(NSString *)lessonId
                             uid:(NSString *)uid
                          mainIP:(YMTSCServerIpModel *)mainIP
                          dnsIPs:(NSArray<YMTSCServerIpModel *> *)dnsIPs
                           token:(NSString *)token;


/// 同步历史消息
/// @param completionBlock 历史消息同步回调
- (void)asyncHistoryDataWithComplete:(void (^)(BOOL isSuccess))completionBlock;


/// 重置连接，会清空发送和接收缓存数据
/// @param isEndConnect  是否结束连接标志位
- (void)resetConnect:(BOOL)isEndConnect;


/// 发送指令
/// @param commandContent 指令内容
/// @param type 指令类别
- (void)sendCommand:(NSDictionary *)commandContent type:(YMTSCCommandConvertType)type;

/// 断开连接
- (void)disconnect;

/// 获取当前IP
- (NSString *)getCurrentIp;
@end
