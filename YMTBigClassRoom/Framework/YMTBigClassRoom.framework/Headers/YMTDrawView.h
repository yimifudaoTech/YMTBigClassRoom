//
//  YMTDrawView.h
//  DrawView
//
//  Created by 顾鹏凌 on 2017/7/4.
//  Copyright © 2017年 顾鹏凌. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSInteger, YMTDrawViewType) {
    YMTDrawViewTypeNormal,
    YMTDrawViewTypeLine,     // 实线
    YMTDrawViewTypeDashLine, // 虚线
    YMTDrawViewTypeTriangle, // 三角形
    YMTDrawViewTypeSquare,   // 正方形
    YMTDrawViewTypeCircle,
    YMTDrawViewTypeEllipse,
    YMTDrawViewTypeTuoCircle,  // 椭圆
    YMTDrawViewTypeImage,   // 绘制图片
};


/** 得出椭圆的数据 */
typedef struct {
    CGFloat rectx;
    CGFloat recty;
    CGFloat rectWidth;
    CGFloat rectHeight;
    CGFloat angle;
} TuoEllipseStruct;
CG_INLINE TuoEllipseStruct TuoEllipseStructMake(CGFloat rectx, CGFloat recty, CGFloat rectWidth,CGFloat rectHeight,CGFloat angle) {
    TuoEllipseStruct myStruce;
    myStruce.rectx = rectx;
    myStruce.recty = recty;
    myStruce.rectWidth = rectWidth;
    myStruce.rectHeight=rectHeight;
    myStruce.angle = angle;
    return myStruce;
}

/** 得出界限值 */
typedef struct {
    CGFloat smallx;
    CGFloat smally;
    CGFloat bigx;
    CGFloat bigy;
} AllLimitStruct;
CG_INLINE AllLimitStruct AllLimitStructMake(CGFloat smallx, CGFloat smally, CGFloat bigx,CGFloat bigy) {
    AllLimitStruct myStruce;
    myStruce.smallx = smallx;
    myStruce.smally = smally;
    myStruce.bigx = bigx;
    myStruce.bigy = bigy;
    return myStruce;
}


typedef void (^YMTDrawViewDoneBlock)(YMTDrawViewType type,NSArray *points,TuoEllipseStruct tuoEllipse);
typedef void (^YMTDrawViewCloseBlock)(YMTDrawViewType type);


@interface YMTDrawLine : UIView

@property (nonatomic, strong) UIColor *strokeColor;

@end

@interface YMTDrawView : UIView
@property (nonatomic, assign) YMTDrawViewType drawType;
@property (nonatomic, assign) CGPoint selectPoint;
@property (nonatomic, strong) UIImage *image;//要绘制的图片
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, copy) YMTDrawViewDoneBlock doneBlock;
@property (nonatomic, copy) YMTDrawViewCloseBlock closeBlock;
- (void)addDoneBtnEvent:(YMTDrawViewDoneBlock)done closeEvent:(YMTDrawViewCloseBlock)close;

@end
