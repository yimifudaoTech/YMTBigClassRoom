//
//  YMPlayView.h
//
//  Created by 顾鹏凌 on 2016/12/14.
//  Copyright © 2016年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import <ZFPlayer/ZFPlayer.h>
#import <ZFPlayer/UIView+CustomControlView.h>

typedef void (^PlayerChanged)(NSInteger changed);

@interface YMPlayView : UIView <ZFPlayerControlViewDelagate>

/** 视频model */
/** 设置playerLayer的填充模式 */
@property (nonatomic, assign) ZFPlayerLayerGravity playerLayerGravity;
/** 是否有下载功能(默认是关闭) */
@property (nonatomic, assign)BOOL hasDownload;
/** 是否开启预览图 */
@property (nonatomic, assign)BOOL hasPreviewView;
/** 设置代理 */
@property (nonatomic, weak)id<ZFPlayerDelegate> delegate;
/** 是否被用户暂停 */
@property (nonatomic, assign, readonly)BOOL isPauseByUser;
/** 播发器的几种状态 */
@property (nonatomic, assign, readonly)ZFPlayerState state;
/** 静音（默认为NO）*/
@property (nonatomic, assign)BOOL mute;
/** 当cell划出屏幕的时候停止播放（默认为NO） */
@property (nonatomic, assign)BOOL stopPlayWhileCellNotVisable;
/** 当cell播放视频由全屏变为小屏时候，是否回到中间位置(默认YES) */
@property (nonatomic, assign)BOOL cellPlayerOnCenter;
/** 当前播放时间进度 */
@property (nonatomic, assign)NSInteger nowPlayTime;
/** 是否是老师端 */
@property (nonatomic, assign)BOOL isTeacher;
/** 当前播放的url */
@property (nonatomic, strong, readonly)NSString *playUrl;
/** 播放速度 */
@property (nonatomic, assign)CGFloat rate;


/**
 *  单例，用于列表cell上多个视频
 *
 *  @return ZFPlayer
 */
+ (instancetype)sharedPlayerView;

/** 滑动进度拖动完成 */
@property (nonatomic, copy) PlayerChanged sliderChanged;
@property (nonatomic, copy) PlayerChanged playChanged;
@property (nonatomic, copy) PlayerChanged closeChanged;
- (void)addPlayerSilderChange:(PlayerChanged)changeCallBack playChang:(PlayerChanged)playCallBack closeChange:(PlayerChanged)closeCallBack;

/**
 *  指定播放的控制层和模型
 *  控制层传nil，默认使用ZFPlayerControlView(如自定义可传自定义的控制层)
 */
- (void)playerControlView:(UIView *)controlView playerModel:(ZFPlayerModel *)playerModel;

/**
 *  自动播放，默认不自动播放
 */
- (void)autoPlayTheVideo;

/**
 *  重置player
 */
- (void)resetPlayer;

/**
 *  在当前页面，设置新的视频时候调用此方法
 */
- (void)resetToPlayNewVideo:(ZFPlayerModel *)playerModel;

/**
 *  播放
 */
- (void)play;

/**
 *  从xx秒开始播放视频跳转
 *
 *  @param dragedSeconds 视频跳转的秒数
 */
- (void)seekToTime:(NSInteger)dragedSeconds completionHandler:(void (^)(BOOL finished))completionHandler;

/**
 *  暂停
 */
- (void)pause;

/**
 *  关闭播放器
 */
- (void)closePlayer;
@end
