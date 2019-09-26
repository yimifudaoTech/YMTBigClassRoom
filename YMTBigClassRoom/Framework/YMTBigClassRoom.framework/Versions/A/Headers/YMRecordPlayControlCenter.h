//
//  YMRecordPlayControlCenter.h
//  student
//
//  Created by mystarains on 2019/8/20.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMRecordPlayProtocol.h"
#import "YMRecordPlayDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMRecordPlayControlCenter : NSObject

@property (nonatomic, weak) id<YMRecordPlayDelegate> delegate;

/**
 获取录播播放视图
 
 @return UIView
 */
- (UIView *)getRecordPlayerView;

/**
 * 设置轨迹数据
 * @param filePath 轨迹文件路径
 * @param mp3PathList 音频文件路径
 * */
- (void)setRecordFile:(NSURL *)filePath mp3PathList:(NSArray *)mp3PathList;

/**
 * 设置播放课程ID
 * @param lessonId
 */
- (void)setLessonId:(NSString *)lessonId;

/**
 * 设置播放倍速 1X 2X 3X 5X
 * @param speed
 */
- (void)setPlaySpeed:(CGFloat)speed;

/**
 * 获取播放倍速 1X 2X 3X 5X
 * @return speed
 */
- (CGFloat)getPlaySpeed;

/**
 * 设置 playerView 播放或者暂停
 * @param play
 */
- (void)setPlayerViewPlay:(BOOL)play;

/**
 * 设置 playerView 标题
 * @param play
 */
- (void)setPlayerViewTitle:(NSString *)title;

/**
 * 开始播放
 * */

- (void)play;

/**
 * 停止播放
 * */
- (void)stop;

/**
 * 暂停
 * */
- (void)pause;

/**
 * 拖动到某个位置
 * @param rate 拖动比例 0~1
 * */
- (void)seekTime:(CGFloat)rate;

/**
 * 获取总时长
 * @return speed
 * */
- (NSInteger)getRecordTotalTime;

@end

NS_ASSUME_NONNULL_END
