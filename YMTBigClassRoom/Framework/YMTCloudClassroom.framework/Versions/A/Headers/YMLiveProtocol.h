//
//  YMLiveProtocol.h
//  YiMiLib
//
//  Created by Caffrey on 2019/4/18.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMLiveProtocol_h
#define YMLiveProtocol_h

#import <UIKit/UIKit.h>
#import "YMLiveEnum.h"
#import "YMLiveMacros.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^YMLiveCallbackBlock)(YMLiveChannel channel, id _Nullable result, NSError * _Nullable error);

#pragma mark - YMLiveDelegate
@protocol YMLiveDelegate <NSObject>
@optional
/**
 userid对应的成员的进房通知
 @param userId 用户标识
 */
- (void)onUserEnter:(NSString *)userId channel:(YMLiveChannel)channel;


/**
 直播场景下，当本地用户在加入频道后调用 setClientRole 切换角色时会触发此回调，即主播切换为观众时，或观众切换为主播时。

 @param oldRole 切换前的角色
 @param newRole 切换后的角色
 */
- (void)onClientRoleChanged:(YMLiveUserType)oldRole newRole:(YMLiveUserType)newRole;

/**
 userid对应的成员的退房通知
 @param userId 用户标识
 @param reason 离开原因代码
 */
- (void)onUserExit:(NSString *)userId reason:(NSInteger)reason channel:(YMLiveChannel)channel;

/**
 远端首帧视频画面到达
 
 @param userId 用户 ID
 @param width  画面宽度
 @param height 画面高度
 @param channel 渠道
 */
- (void)onFirstRemoteVideoFrame:(NSString *)userId
                          width:(int)width
                         height:(int)height
                        channel:(YMLiveChannel)channel;

/**
 远端首帧音频数据到达
 包含本地音频首帧和远端音频首帧，使用userId区分
 
 @param userId 用户 ID
 @param channel 渠道
 */
- (void)onFirstRemoteAudioFrame:(NSString *)userId
                        channel:(YMLiveChannel)channel;

/**
 本地首帧视频画面到达
 注意：不是所有通道都有此回调
 
 @param width  画面宽度
 @param height 画面高度
 @param channel 渠道
 */
- (void)onFirstLocalVideoFrameWithWidth:(int)width
                                 height:(int)height
                                channel:(YMLiveChannel)channel;

/**
 本地音频数据到达
 注意：不是所有通道都有此回调
 
 @param channel 渠道
 */
- (void)onFirstLocalAudioFrameWithChannel:(YMLiveChannel)channel;

/**
 返回当前用户的音视频统计信息。两秒一次。
 统计信息Dictionary里可能包含key：
     quality:   网络质量
     upLoss:    上行丢包
     downLoss:  下行丢包
     delay:     延时
     aoBitrate: 音频比特率
     voBitrate: 视频比特率
     voLost:    视频频丢包
     aoLost:    音频丢包
     frameRate: 帧率
 
 上述信息并不一定全部都有，不同通道内容可能不通。
 
 @param statistics 统计信息
 */
- (void)onStatistics:(NSDictionary *)statistics channel:(YMLiveChannel)channel;

/**
 userId 对应的成员语音音量
 userVolumes 包含 @{@"userId":@"userVolume"}
 
 通过调用 enableAudioVolumeEvaluation:smooth: 来开关这个回调
 @param userVolumes  每位发言者的语音音量，取值范围 0~100
 @param totalVolume  总的语音音量, 取值范围 0~100
 */
- (void)onUserVoiceVolume:(NSDictionary *)userVolumes
              totalVolume:(NSInteger)totalVolume
                  channel:(YMLiveChannel)channel;

@end


#pragma mark - YMLiveProtocol
@protocol YMLiveProtocol <NSObject>

@required

@property (nonatomic, weak) id<YMLiveDelegate> delegate;

/**
 进入房间
 
 @param appId 渠道的appid
 @param rid 房间号
 @param uid 用户id
 @param userType 用户类型
 @param params 其他参数；各渠道传不同的内容
 @param callback 回调
 */
- (void)enterRoom:(NSString *)appId
           roomId:(NSString *)rid
           userId:(NSString *)uid
         userType:(YMLiveUserType)userType
           params:(NSDictionary *)params
         callback:(YMLiveCallbackBlock)callback;

- (void)setClientRole:(YMLiveUserType)userType;

/**
 离开房间
 
 @param callback 回调
 */
- (void)leaveRoom:(nullable YMLiveCallbackBlock)callback;

/**
 切换摄像头
 
 @param callback 回调
 */
- (void)switchCamera:(nullable YMLiveCallbackBlock)callback;

/**
 开启/关闭 视频
 
 @param enable 开启/关闭
 @param callback 回调
 */
- (void)enableVideo:(BOOL)enable callback:(nullable YMLiveCallbackBlock)callback;


/// 开启/关闭 本地视频
/// @param enable YES 开启，NO关闭
/// @param callback 回调
- (void)enableLocalVideo:(BOOL)enable callback:(nullable YMLiveCallbackBlock)callback;
/**
 是否屏蔽本地视频

 @param mute YES:屏蔽；NO:开启
 */
- (void)muteLocalVideo:(BOOL)mute;

/**
 开启/关闭 声音
 
 @param enable 开启/关闭
 @param callback 回调
 */
- (void)enableAudio:(BOOL)enable callback:(nullable YMLiveCallbackBlock)callback;

/**
 是否屏蔽本地音频

 @param mute YES:屏蔽；NO:开启
 */
- (void)muteLocalAudio:(BOOL)mute;


/// 开启/关闭本地音频
/// @param enable YES 开启，NO 关闭
/// @param callback 回调
- (void)enableLocalAudio:(BOOL)enable callback:(nullable YMLiveCallbackBlock)callback;
/**
 开启/关闭 美颜
 
 @param enable 开启/关闭
 @param callback 回调
 */
- (void)enableBeauty:(BOOL)enable callback:(nullable YMLiveCallbackBlock)callback;

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

/**
 销毁
 */
- (void)destory;

@optional

/**
 设置当前渠道的日志路径，日志文件就会存放在这个路径下，不通的通道日志文件可能是不相同的。
 注意：并不是所有通道设置这个都会生效，具体看各个通道的情况。
 
 @param logPath 路径
 */
- (void)setLogPath:(NSString *)logPath;

/**
 启用音量大小提示
 开启后会在 [YMLiveDelegate onUserVoiceVolume:totalVolume:channel:] 回调中获取到 SDK 对音量大小值的评估。
 注意：并不是所有通道设置这个都会有回调，具体看各个通道的情况。
 
 @param interval     报告间隔单位为 ms，最小间隔20ms，如果小于等于0则会关闭回调，建议设置为大于200ms
 @param smoothLevel  灵敏度，[0,10]，数字越大，波动越灵敏，建议设置值3
 */
- (void)enableAudioVolumeEvaluation:(NSUInteger)interval smooth:(NSInteger)smoothLevel;


/// 启动音视频通道测试
/// @param appId 通道测试appID
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

#endif /* YMLiveProtocol_h */
