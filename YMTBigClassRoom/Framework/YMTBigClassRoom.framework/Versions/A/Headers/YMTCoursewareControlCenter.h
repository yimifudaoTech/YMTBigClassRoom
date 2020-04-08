//
//  YMTCoursewareControlCenter.h
//  student
//
//  Created by SendomZhang on 12/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YMTCloudClassroom/YMTSCServerHeader.h>
#import <YMTCloudClassroom/YMTCoursewareInfo.h>
#import "YMWhiteBoardControlCenter.h"

/// 课件相关操作
@interface YMTCoursewareControlCenter : NSObject

@property (nonatomic, strong) YMWhiteBoardControlCenter * _Nonnull whiteBoardControlCenter;

@property (nonatomic, copy) void(^ _Nonnull pageChangeBlock)(NSInteger pageCount, NSInteger pageIndex);

// 展示答题板
@property (nonatomic,copy) void(^ _Nullable showAnswerBoardBlock)(void);

- (void)showCourseWare:(YMTCoursewareInfo * _Nonnull)courseWareInfo totalCount:(NSInteger)totalCount;

- (void)updateCourseWareFrame;

#pragma mark - 翻页操作
/// 跳到课件第几页
- (void)gotoPage:(NSInteger)page;

- (void)addPage;

- (void)deletePage;

#pragma mark - 滑动，放大操作
- (void)scrollToOffset:(CGFloat)offset;

- (void)setCoursewareZoomEnable:(BOOL)enable;

/// 播放动画
/// @param courseWareId 课件ID
/// @param pageNo 课件页码
/// @param step 动画步骤
- (void)playAnimation:(NSString * _Nullable)courseWareId withPageNo:(NSInteger)pageNo withAnimationStep:(NSInteger)step;
/**
 H5结构化课件-课堂练习
 @param content 指令信息
 */
- (void)sendDataToCourseware:(NSDictionary *_Nullable)content;

#pragma mark - 属性方法

/// 课件视图
- (UIView * _Nonnull)getCourseView;

- (NSString * _Nonnull)getKeyDocId;

/// 获取当前课件的总页数
- (NSInteger)getTotalPage;

/// 获取当前课件是第几页
- (NSUInteger)getCurrentPage;

/// 是否正在同步
- (void)syncing:(BOOL)status;

/// 更新视图
- (void)update;

- (void)destory;

@end

