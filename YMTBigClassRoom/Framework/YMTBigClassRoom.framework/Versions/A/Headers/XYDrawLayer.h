//
//  XYDrawLayer.h
//  YiMiApp
//
//  Created by xieyan on 16/6/27.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XYZDrawTool.h"

//#import "XYZDrawTrailModel.h"

typedef NS_ENUM(NSUInteger, XYZDrawEvent) {
    XYZDrawEvent_Began = 0,
    XYZDrawEvent_Move,
    XYZDrawEvent_End
};

@interface XYZDrawTrailModel : NSObject
@property (assign, nonatomic) CGFloat width;
// 线宽类型 0 1 2 代表小 中 大
@property (copy, nonatomic) NSString *widthType;

@property (strong, nonatomic) UIColor *color;//color为空代表橡皮
@property (strong, nonatomic) NSMutableArray<NSValue*> *pointArray;
@property (strong, nonatomic) NSString *offsetY;

@property (strong, nonatomic) NSString *orderNum;
@property (strong, nonatomic) NSString *user;

@end


@protocol XYDrawLayerDelegate <NSObject>
@optional
/**
 *  画图
 *
 */
- (void)draw_Trail:(XYZDrawTrailModel*)model;
/**
 *  截屏
 *
 */
- (void)draw_ScreenshotRect:(CGRect)rect;
@end

@interface XYDrawLayer : UIView
@property (nonatomic, assign) BOOL isUserTapShot;
@property (weak,nonatomic) id<XYDrawLayerDelegate>delegate;
@property (strong,nonatomic) NSMutableDictionary *dataSource;
@property (nonatomic , strong) NSMutableDictionary *dicAllDataSource;

@property (nonatomic, strong) UIColor *lineColor;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) XYZDrawToolType toolType;

@property(nonatomic, assign) CGPoint  scrollOffset;
@property(nonatomic, assign) float  realHeight;

/**
 是否重置layer
 */
@property(nonatomic, assign) BOOL isResetting;

/**
 拼接需要绘制的点到数据源
 */
- (id<XYZDrawTool>)appendTrailModel:(XYZDrawTrailModel *)model groupId:(NSString *)groupId needRemember:(BOOL)needRemember;

/**
 *  根据点集绘图
 *
 *  @param model   点集模型
 */
- (void)draw_Trail:(XYZDrawTrailModel*)model groupId:(NSString*)groupId;

/**
 *  根据点集绘椭圆
 *
 *  @param model   点集模型
 */
- (void)draw_TuoCircleTrail:(NSDictionary *)dicArr groupId:(NSString*)groupId;

/**
 *  根据点集绘多边形
 *
 *  @param model   点集模型
 */
- (void)draw_PolygonTrail:(NSDictionary *)dicArr groupId:(NSString*)groupId;

/**
 *  反撤销
 *
 */
-(void)draw_redo_groupId:(NSString *)groupId;

/**
 *  撤销
 *
 */
-(void)draw_undo_groupId:(NSString *)groupId;
/**
 *  清空画笔
 */
-(void)draw_clear_groupId:(NSString*)groupId;

/**
 *  向后翻页动画
 */
-(void)pageTurnBackward;
/**
 *  向前翻页动画
 */
-(void)pageTurnForward;

- (void)setNeedsDisplayWithOffset:(CGPoint)offset realHeight:(float)realHeight;

- (void)handleTouchEvent:(int)event point:(CGPoint)point previous:(CGPoint)previous;


/**
 撤销指定的画笔轨迹
 */
- (void)revokeSpecifiedTrail:(NSString *)groupId;

/**
 撤销指定的所有轨迹
 */
- (void)cleanSpecifiedTrail:(NSString *)groupId;

/**
 指定笔迹是否存在
 */
- (BOOL)existSpecifiedTrail:(NSString *)groupId;

@end
