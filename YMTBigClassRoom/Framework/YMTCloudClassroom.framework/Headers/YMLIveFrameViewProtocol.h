//
//  YMLIveFrameViewProtocol.h
//  YMTCloudClassroom
//
//  Created by mac on 2019/10/24.
//

#ifndef YMLIveFrameViewProtocol_h
#define YMLIveFrameViewProtocol_h

#import "YMLiveChildViewProtocol.h"

@protocol YMLIveFrameViewProtocol <NSObject>

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


#endif /* YMLIveFrameViewProtocol_h */
