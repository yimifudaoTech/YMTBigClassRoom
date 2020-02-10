//
//  SDSmallClassRoomBaseView.h
//  student
//
//  Created by Caffrey on 2019/5/29.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMBaseCousewareView.h"
#import <YMTCloudClassroom/YMTH5Courseware.h>

NS_ASSUME_NONNULL_BEGIN
/// 课件组件与白板
@interface YMTCoursewareView : YMBaseCousewareView
/** 课堂ID */
@property(nonatomic, copy) NSString *lessonId;
/** 当前正在同步数据 */
@property(nonatomic, assign, getter=isSyncing) BOOL syncing;
/** 接收到JS发送提交答案信息 回调Block */
@property(nonatomic,copy) void(^receiveDataFromCourseware)(NSString * jsonData);
#pragma mark - 翻页操作
/// 切换页码
- (void)gotoPage:(NSInteger)page;

/// 加页
- (void)addPage;

/// 删除页
- (void)deletePage;

#pragma mark - 滑动，放大操作
- (void)scrollToOffset:(CGFloat)offset;

/// 播放动画
/// @param step 动画步骤
- (void)playAnimation:(NSInteger)step;

/**
 H5结构化课件-课堂练习
 @param content 指令信息
 */
- (void)sendDataToCourseware:(NSDictionary *)content;

/**
 设置课件是否可以交互
 @param enabled 交互状态
 */
- (void)setCoursewareUserInteractionEnabled:(BOOL)enabled;

- (CGRect)getCoursewareViewFrame;

- (void)destory;

@end

NS_ASSUME_NONNULL_END
