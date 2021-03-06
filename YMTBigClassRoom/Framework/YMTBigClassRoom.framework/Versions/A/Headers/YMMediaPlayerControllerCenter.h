//
//  YMMediaPlayerControllerCenter.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import "YMAVModels.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMMediaPlayerControllerCenter : NSObject


/**
 获取播放器view
 @return 播放器View
 */
- (UIView *)getAVPlayerView;

/**
 获取当前播放的url
 @return 音视频url链接
 */
- (NSString *)getPlayUrl;


/**
 播放音视频
 @param model 音视频模型
 @param fatherView 父视图
 @param needInitialize 是否只需要初始化
 */
- (void)playAVModel:(YMAVControl*)model withFatherView:(UIView *)fatherView needInitialize:(BOOL)needInitialize;


/**
 拖动到指定时间进行播放
 @param seekTime 时间点
 */
- (void)seekTimePlayWithTime:(float)seekTime;


/**
 播放音视频
 */
- (void)play;

/**
 暂停音视频
 */
- (void)pause;


/**
 关闭播放器
 */
- (void)closePlayer;

@end

NS_ASSUME_NONNULL_END
