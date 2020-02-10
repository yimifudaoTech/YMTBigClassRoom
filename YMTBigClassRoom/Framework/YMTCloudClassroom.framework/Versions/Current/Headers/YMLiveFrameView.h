//
//  YMLiveFrameView.h
//  student
//
//  Created by peanut on 2018/11/29.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMLiveChildViewProtocol.h"

@interface YMLiveFrameView : UIScrollView <YMLiveChildViewProtocol>

/**
 根据uid获取渲染视频的本地图层
 */
- (UIView *)canvasViewForUid:(NSUInteger)uid;

/**
 根据uid获取对应的子视图
 */
- (id<YMLiveChildViewProtocol>)childViewForUid:(NSUInteger)uid;

/**
 用户加入添加视图
 */
- (void)addChildFrameViewForUid:(NSUInteger)uid userRole:(YMLiveRoleType)roleType;

/**
 用户离开移除视图
 */
- (void)removeChildFrameViewForUid:(NSUInteger)uid;

/**
 用户离开保留位置
 */
- (void)resetChildViewForUid:(NSUInteger)uid;

@end
