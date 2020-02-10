//
//  YMTAudioVideoControlCenter.h
//  student
//
//  Created by mystarains on 2019/8/9.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YMTCloudClassroom/YMLiveModule.h>

#import <YMTCloudClassroom/YMTLiveFrameView.h>
#import <YMTCloudClassroom/YMLiveFrameView.h>
#import <YMTCloudClassroom/YMLIveFrameViewProtocol.h>
#import "YMRoomModel.h"
#import "YMUserAuthManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMTAudioVideoControlCenter : NSObject

@property (nonatomic,weak) id<YMLiveModuleDelegate> delegate;
@property (nonatomic, strong) id<YMLIveFrameViewProtocol> liveView;
@property (nonatomic, strong) YMRoomModel *roomModel;
@property (nonatomic, assign) YMLiveUserType currentUserType;
@property (nonatomic, assign) BOOL isInRoom;
@property (nonatomic, strong) YMUserAuthManager *userAuthManager;


- (id<YMLIveFrameViewProtocol>)getAudioVeideoView;

/**
 刷新某个子view的状态
 */
- (void)refreshFrameChildViewWithUid:(NSUInteger)uid config:(NSDictionary *)config;

- (void)refreshChildViewForUserEnter:(NSInteger)uid userRole:(YMLiveRoleType)roleType;

- (void)refreshChildViewForUserLeave:(NSUInteger)uid;

- (void)refreshRemoteUserChildViews;

/**
 设置本地视频渲染视图
 
 @param uid 用户id
 */
- (void)setupLocalVideoWithUid:(NSString *)uid;

/**
 设置远程视频渲染视图
 
 @param uid 用户id
 @param roleType 用户类型
 */
- (void)setupRemoteVideoWithUid:(NSString *)uid withUserRole:(YMRoleType)roleType;

#pragma mark -- 控制器
/**
 销毁控制器
 */
- (void)destoryManager;

#pragma mark -- 进出房间
/**
 进入房间
*/
- (void)enterRoom;

//设置用户角色为主播
- (void)setClientRole:(YMLiveUserType)userType;

/**
 离开房间
 @param channel 音视频渠道
 */
- (void)leaveRoom:(YMLiveChannel)channel;

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

- (void)enableAudioVolumeEvaluation:(NSUInteger)interval smooth:(NSInteger)smoothLevel;

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

/**
 开启/关闭 美颜
 @param enable 开启/关闭
 */
- (void)enableBeauty:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
