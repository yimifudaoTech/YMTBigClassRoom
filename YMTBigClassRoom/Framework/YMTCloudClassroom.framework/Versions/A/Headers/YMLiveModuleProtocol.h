//
//  YMLiveModuleProtocol.h
//  YMLiveSDK
//
//  Created by mystarains on 2019/8/9.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLiveFrameContentView.h"
#import "YMLiveEnum.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YMLiveModuleDataSource <NSObject>

@required

- (UIView *)canvasForUid:(NSUInteger)uid;

@end

@protocol YMLiveModuleDelegate <NSObject>

@optional

- (void)onUserEnter:(NSUInteger)uid;
- (void)onUserLeave:(NSUInteger)uid;
- (void)onUserTimeout:(NSUInteger)uid;
- (void)receiveRemoteFirstFrame:(NSUInteger)uid;
- (void)receiveLocalFirstFrame;
- (void)reportSpeakers:(NSDictionary *)speakers totalVolume:(NSInteger)totalVolume;
- (void)onEnterRoomFailure:(NSInteger)errorCode;
- (void)onAudioQuality:(NSDictionary *)audioQuality;
- (void)onClientRoleChanged:(YMLiveUserType)oldRole newRole:(YMLiveUserType)newRole;

@end

@protocol YMLiveModuleProtocol <NSObject>


/// 设置当前通道
/// @param channel  通道名
- (void)setLiveChannel:(YMLiveChannel)channel;

/// 获取音视频区域整体view
- (YMLiveFrameContentView *)getAudioVeideoView;

/**
 设置本地视频渲染视图
 
 @param uid 用户id
 @param view 视图
 */
- (void)setupLocalVideoWithUid:(NSString *)uid withView:(UIView *)view;

/**
 设置远程视频渲染视图
 
 @param uid 用户id
 @param view 视图
 */
- (void)setupRemoteVideoWithUid:(NSString *)uid withView:(UIView *)view;

#pragma mark -- 控制器
/**
 销毁控制器
 */
- (void)destoryManager;

#pragma mark -- 进出房间
/**
 进入房间
 @param appId 渠道的appid
 @param roomId 房间号
 @param userId 用户id
 @param userType 用户类型
 @param params 其他参数；各渠道传不同的内容（key/value）
 声网 需要字段 key:token
 腾讯V2需要字段 key:userSig record_id uc_biz_type
 
 */
- (void)enterRoom:(NSString *)appId
           roomId:(NSString *)roomId
           userId:(NSString *)userId
         userType:(YMLiveUserType)userType
           params:(NSDictionary *)params;

- (void)setClientRole:(YMLiveUserType)userType;

/**
 离开房间
 */
- (void)leaveRoom;

/**
 启用音量大小提示
 开启后会在 [YMLiveDelegate onUserVoiceVolume:totalVolume:channel:] 回调中获取到 SDK 对音量大小值的评估。
 注意：并不是所有通道设置这个都会有回调，具体看各个通道的情况。
 
 @param interval     报告间隔单位为 ms，最小间隔20ms，如果小于等于0则会关闭回调，建议设置为大于200ms
 @param smoothLevel  灵敏度，[0,10]，数字越大，波动越灵敏，建议设置值3
 */
- (void)enableAudioVolumeEvaluation:(NSUInteger)interval smooth:(NSInteger)smoothLevel;

#pragma mark -- 音频控制
/**
 是否开启音频模块
 @param enable 开启/关闭
 */
- (void)enableAudio:(BOOL)enable;

/**
 是否推送音频流
 @param enable 开启/关闭
 */
- (void)enableAudioPush:(BOOL)enable;


/// 是否开启本地音频
/// @param enable YES 开启， NO 关闭
- (void)enableLocalAudio:(BOOL)enable;

#pragma mark -- 视频控制
/**
 开启视频模块
 @param enable 开启/关闭
 */
- (void)enableVideo:(BOOL)enable;

/**
 是否发送本地视频流
 @param enable 开启/关闭
 */
- (void)enableLocalVideoPush:(BOOL)enable;


/// 是否开启本地视频
/// @param enable YES 开启， NO 关闭
- (void)enableLocalVideo:(BOOL)enable;
/**
 开启/关闭 美颜
 @param enable 开启/关闭
 */
- (void)enableBeauty:(BOOL)enable;


/// 启动音视频测试
/// @param appId 音视频测试的appID
- (void)startLiveTest:(NSString *)appId;

/** 启动语音通话测试 */
- (void)startEchoTest:(void(^)(NSString *channel, NSUInteger uid, NSInteger elapsed))successBlock;

/** 终止语音通话测试 */
- (void)stopEchoTest;

/** 启用网络测试 */
- (void)enableLastmileTest;

/** 禁用网络测试 */
- (void)disableLastmileTest;

/** 启用本地视频测试 */
- (void)startLocalVideoTestWithView:(UIView *)showView;

/** 关闭本地视频测试 */
- (void)stopLocalVideoTestWithView:(UIView *)showView;


@end

NS_ASSUME_NONNULL_END
