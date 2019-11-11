//
//  GPLAVPlayerManager.h
//  YiMiApp
//
//  Created by 周志强 on 2016/12/7.
//  Copyright © 2016年 xieyan. All rights reserved.
//  音视频播放器管理工具类 

#import <UIKit/UIKit.h>
//#import "ZQSingleton.h"
#import "HttpDataModels.h"
//#import <ZFPlayer/ZFPlayer.h>
#import "GPLPlayView.h"
#import "ZQPlayerAudioView.h"

typedef enum : NSUInteger {
    GPLAVPlayerManagerAVTypeAudio, // 播放音频url
    GPLAVPlayerManagerAVTypeVideo  // 播放视频url
    
} GPLAVPlayerManagerAVType;

typedef void (^PlayerChanged)(NSInteger changed);

@interface GPLAVPlayerManager : UIView
@property (nonatomic, strong) MediaModel *mediaModel;//记录当前media
/** 播放网络音视频url类型 */
@property (nonatomic, assign) GPLAVPlayerManagerAVType AVType;
/** 播放器状态 */
@property (nonatomic, strong, readonly)NSString *playerStateStr;
/** 播放器状态 */
@property (nonatomic, assign, readonly)ZFPlayerState playerState;
/** 记录音频的frame */
@property (nonatomic, assign) CGRect lastAudioRect;
/** 当前播放时间进度 */
@property (nonatomic, assign) NSInteger nowPlayTime;
/** 播放速度 */
@property (nonatomic, assign) CGFloat speed;

/**
 *  当前播放的url
 */
- (NSString *)playUrl;

/**
 *  添加滑动进度条 播放暂停 关闭 回调  callBack 播放时间 播放／暂停 关闭
 */
- (void)addPlayerSilderChange:(PlayerChanged)changeCallBack playChang:(PlayerChanged)playCallBack closeChange:(PlayerChanged)closeCallBack;

/**
 *  播放视频方法
 */
- (void)palyWithAVModel:(AVControl*)model andIsTeacher:(BOOL)isTeacher;

/**
 *  切换声源
 */
- (void)resetPlayWithModel:(AVControl *)model andAVType:(GPLAVPlayerManagerAVType)AVType;

/**
 *  跳入指定位置进行播放
 */
- (void)seekTimePlayWithTime:(float)seekTime;

/**
 *  播放
 */
- (void)play;

/**
 *  暂停
 */
- (void)pause;

/**
 *  关闭播放器
 */
- (void)close;


@end
