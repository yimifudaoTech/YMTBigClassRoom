//
//  YMWhiteBoardControl.h
//  YMWhiteBoardSDK
//
//  Created by mystarains on 2019/7/16.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMWhiteBoardView.h"
#import "YMWhiteBoardDelegate.h"
#import "YMBoardPageInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMWhiteBoardControl : NSObject

@property (nonatomic, strong) YMWhiteBoardView *whiteBoardView;

@property (nonatomic, copy) NSString *boardId;
@property (nonatomic, assign) BOOL userInteractionEnabled;
@property (nonatomic, weak) id<YMWhiteBoardDelegate> delegate;

@property (nonatomic, strong) YMBoardPageInfo *boardPageInfo;
@property (nonatomic, strong) UIColor *lineColor;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) YMDrawToolType toolType;

@property(nonatomic, assign) CGPoint scrollOffset;
@property(nonatomic, assign) float realHeight;


@property (nonatomic, assign) CGPoint currentRatePoint;//比例点
@property (nonatomic, assign) WhiteBoardCursorViewType cursorType;

/**
 *  根据点集绘图
 *
 *  @param model   点集模型
 */
- (void)drawTrail:(YMDrawTrailModel*)model;

/**
 *  根据点集绘椭圆
 *
 *  @param model   椭圆模型
 */
- (void)drawEllipseTrail:(YMDrawGraphModel *)model;

/**
 *  根据点集绘多边形
 *
 *  @param model   多边形模型
 */
- (void)drawPolygonTrail:(YMDrawGraphModel *)model;

/**
 *  绘制图片
 *
 *  @param model   图片模型
 */
- (void)drawImage:(YMDrawImageModel *)model;

/**
 *  更新图片
 *
 @param drawImage 图片数据
 @param itemId    唯一标识ID
 */
- (void)updateImage:(UIImage *)drawImage loadStatus:(NSString *)statusText loading:(BOOL)loading itemId:(NSString *)itemId;

/**
 *  清空画笔
 */
- (void)clearBoard;

/**
 *  根据偏移量重新绘制
 */
- (void)setNeedsDisplay;

/**
 删除图形图片
 
 @param itemId itemId description
 */
- (void)deleGraph:(NSString *)itemId deleteBySelf:(BOOL)flag;

- (void)handleTouchEvent:(CGPoint)point previous:(CGPoint)previous;
- (void)handlePendoSuspendedEvent:(CGPoint)point;
/**
 *  手绘板事件
 */
- (void)handleTouchEvent:(int)event point:(CGPoint)point previous:(CGPoint)previous;

- (void)captureImage:(void(^)(UIImage *image))callback;

@end

NS_ASSUME_NONNULL_END
