//
//  YMWhiteBoardProtocol.h
//  student
//
//  Created by mystarains on 2019/7/15.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMWhiteBoardDelegate.h"
#import "YMWhiteBoardEnum.h"
#import "YMDrawTrailModel.h"
#import "YMDrawTool.h"
#import "YMBoardPageInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YMWhiteBoardProtocol <NSObject>

@required

/** 白板模块代理 */
@property (nonatomic, weak) id<YMWhiteBoardDelegate> delegate;

/** 设置白板id */
- (void)setBoardId:(NSString *)boardId;
/** 获取白板id */
- (NSString *)getBoardId;
/** 白板模块容器/缩放滚动视图 */
- (UIView *)getZoomScrollView;
/** 交互是否开启 */
- (void)setZoomLayerUserInteractionEnabled:(BOOL)enable;
/** 缩放功能是否开启 */
- (void)setZoomScrollEnabled:(BOOL)enable;
/** 单指移动功能是否开启*/
- (void)setTapMoveEnabled:(BOOL)enable;
/** 设置白板缩放偏移*/
- (void)setWhiteBoardScale:(CGFloat)zoomScale offset:(CGPoint)offset;
/** 设置白板缩放*/
- (void)setWhiteBoardScale:(CGFloat)zoomScale;
/** 获取白板缩放*/
- (CGFloat)getWhiteBoardScale;
/** 设置白板contentSize*/
- (void)setWhiteBoardContentSize:(CGSize)contentSize;
/** 获取白板缩放*/
- (CGSize)getWhiteBoardContentSize;
/** 向后翻页动画 */
- (void)showPageTurnBackwardAnimation;
/** 向前翻页动画 */
- (void)showPageTurnForwardAnimation;
/** 设置画笔颜色 */
- (void)setLineColor:(UIColor * _Nonnull)lineColor;
/** 获取当前画笔颜色 */
- (UIColor * _Nonnull)lineColor;
/** 设置画笔宽度 */
- (void)setLineWidth:(CGFloat)lineWidth;
/** 获取当前画笔宽度 */
- (CGFloat)lineWidth;
/** 设置画图类型 */
- (void)setToolType:(YMDrawToolType)toolType;
/** 获取当前画图类型 */
- (YMDrawToolType)toolType;
/** 设置白板偏移点 */
- (void)setScrollOffset:(CGPoint)scrollOffset;
/** 获取白板偏移点 */
- (CGPoint)scrollOffset;

- (void)setBoardDataSource:(YMBoardPageInfo *)pageInfo;

- (void)drawLayerAddObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;

- (void)drawLayerRemoveObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;

/** 设置白板是否可交互 */
- (void)setDrawLayerUserInteractionEnabled:(BOOL)enable;

- (void)hideDrawLayer:(BOOL)isHiden;

/**
 *  根据点集绘图
 *
 *  @param model   点集模型
 */
- (void)drawTrail:(YMDrawTrailModel*)model;

/**
 *  根据点集绘椭圆
 *
 *  @param model   点集模型
 */
- (void)drawEllipseTrail:(YMDrawGraphModel *)model;

/**
 *  根据点集绘多边形
 *
 *  @param model   点集模型
 */
- (void)drawPolygonTrail:(YMDrawGraphModel *)model;


/// 绘制图片
/// @param model 图片模型
- (void)drawImage:(YMDrawImageModel *)model;


- (void)updateImage:(UIImage *)drawImage loadStatus:(NSString *)statusText loading:(BOOL)loading itemId:(NSString *)itemId;

/**
 *  清空当前白板
 */
- (void)clearWhiteBoard;
/**
 *  重新刷新白板
 */
- (void)setNeedsDisplay;
/**
 *  手写板事件
 */
- (void)handleTouchEvent:(int)event point:(CGPoint)point previous:(CGPoint)previous;

/**
 设置比例点
 */
- (void)setCurrentRatePoint:(CGPoint)currentRatePoint;
///**
// 设置教鞭类型
// */
- (void)setCursorType:(WhiteBoardCursorViewType)cursorType;

/**
 删除图形图片
 
 @param itemId itemId description
 */
- (void)deleGraph:(NSString *)itemId deleteBySelf:(BOOL)flag;

//接入手写板新增逻辑
- (void)handleTouchEvent:(CGPoint)point previous:(CGPoint)previous;
- (void)handlePendoSuspendedEvent:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
