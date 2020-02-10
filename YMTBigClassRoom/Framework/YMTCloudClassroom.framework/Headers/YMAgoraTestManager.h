//
//  AgoraInfoManager.h
//  YiMiApp
//
//  Created by 周志强 on 2016/10/11.
//  Copyright © 2016年 xieyan. All rights reserved.
//  声网音视频管理工具类   创建的时候3个View 分别绑定一个tag == self.userId  然后根据当前是什么客户端去显示隐藏相应的View.

#import <Foundation/Foundation.h>
#import <AgoraRtcEngineKit/AgoraRtcEngineKit.h>

#define YimiFudaoNewVerdorKey @"6bdd1aedee814f1fade7ef5e42578ff7"

// 聊天类型,音频 / 视频
typedef NS_ENUM(NSInteger, AGDChatType) {
    AGDChatTypeVideo,
    AGDChatTypeAudio,
    AGDChatTypeDefault = AGDChatTypeVideo // 默认视频
};

typedef void(^AgoraJoinedBlock)(NSUInteger uid);//加入房间回调
typedef void(^AgoraOfflineBlock)(NSUInteger uid);//离开房间

@interface YMAgoraTestManager : NSObject <AgoraRtcEngineDelegate>

/** 引擎 */
@property (nonatomic, strong) AgoraRtcEngineKit *agoraKit;
@property (nonatomic, copy) NSString *agoraChannelKey;

/** 房间id */
@property (nonatomic, copy) NSString *roomId;
/** 用户id */
@property (nonatomic, assign) NSInteger userId;
/** 聊天类型 音频/视频 */
@property (nonatomic, assign) AGDChatType type;
/** 进入频道成功回调 */
@property (copy, nonatomic) AgoraJoinedBlock    agoraJoinedBlock;
/** 用户离线回调 */
@property (copy, nonatomic) AgoraOfflineBlock   agoraOfflineBlock;
/** 检测摄像头 */
@property (assign, nonatomic) BOOL isCheckCamera;
/** 语音检测block */
@property (nonatomic, copy) void (^voiceTestBlock)(NSInteger totalVolume);
/** 网络检测block */
@property (nonatomic, copy) void (^netTestBlock)(int quality);
/** 语音质量信息上报block */
@property (nonatomic, copy) void (^audioReportBlock)(NSMutableDictionary *infoDic);

/** 初始化房间参数 */
- (void)initAgoraRoom:(NSString*)room userId:(NSInteger)userId;

/** 切换角色 0:主播 1:观众*/
- (void)changeLiverRoler:(NSInteger)roler;

/**
 启用说话者音量提示
 @param interval <=0: 禁用音量提示功能 >0: 提示间隔，单位为毫秒。建议设置到大于200毫秒
 @param smooth 平滑系数。默认可以设置为3
 
 [_agoraMgr enableAudioVolumeIndication:300 smooth:3];
 */
- (void)enableAudioVolumeIndication:(NSInteger)interval smooth:(NSInteger)smooth;

/** 启动语音通话测试 */
- (void)startEchoTest:(void(^)(NSString* channel, NSUInteger uid, NSInteger elapsed))successBlock;

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

/** 设置本地视频渲染 */
- (void)setupLocalVideoWithUid:(NSInteger)uid withView:(UIView *)view;

/** 设置远程视频渲染 */
- (void)setupRemoteVideoWithUid:(NSInteger)uid withView:(UIView *)view;

/** 清理 */
- (void)destory;

@end
