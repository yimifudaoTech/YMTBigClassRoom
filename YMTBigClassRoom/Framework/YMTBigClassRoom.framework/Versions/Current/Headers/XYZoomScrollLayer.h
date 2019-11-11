//
//  XYZoomScrollLayer.h
//  YiMiApp
//
//  Created by xieyan on 16/6/27.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>



@class XYZoomScrollLayer;
/**
 必须设置这两个属性才能正常使用放大
 self.zoomScrollLayer.minimumZoomScale = 1.0;
 self.zoomScrollLayer.maximumZoomScale = 5.0;
 */
// 协议
@protocol XYZoomScrollDelegate <NSObject>

@optional
- (void)zoomScrollView:(XYZoomScrollLayer *)zoomScrollView transferImageScale:(CGFloat)zoomScale offsetX:(CGFloat)offsetX offsetY:(CGFloat)offsetY;

@end

//@interface XYZoomScrollModel : NSObject
//@property (assign, nonatomic) CGFloat zoomScale;
//@end

@interface XYZoomScrollLayer : UIScrollView <UIScrollViewDelegate>

/** 代理 */
@property (nonatomic, weak) id <XYZoomScrollDelegate> zoomDelegate;


@property (strong, nonatomic) void(^zoomBlock)(CGFloat zoomScale,CGFloat offsetX,CGFloat offsetY);

/** 缩放层监听滚动block */
@property (nonatomic, copy) void (^XYZoomScrollLayerDidScroll)(UIScrollView *scrollView);

/** 缩放功能是否开启 */
@property (nonatomic, assign) BOOL enabled;
/** 单指移动功能是否开启*/
@property (nonatomic, assign) BOOL tapMoveEnabled;

/** 容器View */
@property (nonatomic, strong, readonly) UIView *contentView;
@property (nonatomic, strong, readonly) UIView *transformedContentView;

@property (nonatomic, strong) UIImage *imageData;

-(void)update;

/** 还原原状态 */
- (void)resetNormalTransfer;
/** 刷新课件图片状态(使具有缩放,平移功能) */
-(void)transferImageScale:(CGFloat)zoomScale offsetX:(CGFloat)offsetX offsetY:(CGFloat)offsetY;



#pragma mark -- 翻页动画
/**
 *  向后翻页动画
 */
-(void)pageTurnBackward;
/**
 *  向前翻页动画
 */
-(void)pageTurnForward;
@end
