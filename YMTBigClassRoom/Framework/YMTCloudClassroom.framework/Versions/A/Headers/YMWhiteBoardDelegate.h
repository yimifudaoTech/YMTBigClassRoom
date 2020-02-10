//
//  YMWhiteBoardDelegate.h
//  teacher
//
//  Created by mystarains on 2019/7/22.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YMDrawGraphModel.h"

NS_ASSUME_NONNULL_BEGIN

@class YMDrawTrailModel;

@protocol YMWhiteBoardDelegate <NSObject>

/**
 回调控制中心 zoomScrollLayerDidScale，白板Ctrl实现：发送缩放指令
 @param zoomScale 缩放系数
 @param offset 偏移点
 */
@optional
- (void)zoomScrollView:(UIScrollView *)scrollView didScale:(CGFloat)zoomScale offset:(CGPoint)offset;

/**
 回调控制中心 zoomScrollLayerDidScroll，白板Ctrl实现：发送滑动指令
 @param scrollView 滚动视图
 */
@optional
- (void)zoomScrollLayerDidScroll:(UIScrollView *)scrollView;

/**
 回调控制中心 cursorPointDidMoved，白板Ctrl实现：发送教鞭指令
 @param point 位移点
 */
@optional
- (void)cursorPointDidMoved:(CGPoint)point;

/**
 轨迹
 @param model 轨迹模型
 */
- (void)trailDidDraw:(YMDrawTrailModel*)model fromBoard:(NSString *)boardId;
/**
 截图
 @param rect 截图选择区域
 */
@optional
- (void)screenshotDidselectedRect:(CGRect)rect;


/**
 移动图形位置
 @param newGraph 更新后的图形数据
 */
- (void)updateGraph:(YMDrawGraphModel *)newGraph fromBoard:(NSString *)boardId;

/**
删除item
 
 @param itemId 图形id
 @param boardId 白板id
 */
- (void)deleteGraph:(NSString *)itemId withGraphType:(YMDrawGraphType)graphType fromBoard:(NSString *)boardId;

/**
 重新加载图片
 
 @param url 图片url
 @param itemId 图片id
 @param boardId 板id
 */
- (void)reloadImage:(UIImage *)drawImage imageUrl:(NSString *)url itemId:(NSString *)itemId fromBoard:(NSString *)boardId;

@end

NS_ASSUME_NONNULL_END
