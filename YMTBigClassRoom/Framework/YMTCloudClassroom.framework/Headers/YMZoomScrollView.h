//
//  YMZoomScrollView.h
//  YMWhiteBoardSDK
//
//  Created by mystarains on 2019/7/17.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMWhiteBoardDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YMZoomScrollView;
/**
 必须设置这两个属性才能正常使用放大
 self.zoomScrollLayer.minimumZoomScale = 1.0;
 self.zoomScrollLayer.maximumZoomScale = 5.0;
 */

@interface YMZoomScrollView : UIScrollView <UIScrollViewDelegate>

/** 代理 */
@property (nonatomic, weak) id <YMWhiteBoardDelegate> zoomDelegate;

/** 缩放功能是否开启 */
@property (nonatomic, assign) BOOL zoomScrollEnabled;
/** 单指移动功能是否开启*/
@property (nonatomic, assign) BOOL tapMoveEnabled;

/** 容器View */
@property (nonatomic, strong, readonly) UIView *transformedContentView;

- (void)setWhiteBoardScale:(CGFloat)zoomScale offset:(CGPoint)offset;

#pragma mark -- 翻页动画
/**
 *  向后翻页动画
 */
-(void)showPageTurnBackwardAnimation;
/**
 *  向前翻页动画
 */
-(void)showPageTurnForwardAnimation;

@end

NS_ASSUME_NONNULL_END
