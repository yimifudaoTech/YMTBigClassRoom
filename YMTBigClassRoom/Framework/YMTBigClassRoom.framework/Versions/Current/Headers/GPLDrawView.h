//
//  GPLDrawView.h
//  DrawView
//
//  Created by 顾鹏凌 on 2017/7/4.
//  Copyright © 2017年 顾鹏凌. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSInteger, GPLDrawViewType) {
    GPLDrawViewTypeNormal,
    GPLDrawViewTypeLine,     // 实线
    GPLDrawViewTypeDashLine, // 虚线
    GPLDrawViewTypeTriangle, // 三角形
    GPLDrawViewTypeSquare,   // 正方形
    GPLDrawViewTypeCircle,
    GPLDrawViewTypeEllipse,
    GPLDrawViewTypeTuoCircle,  // 椭圆
    GPLDrawViewTypeImage,   // 绘制图片
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


typedef void (^GPLDrawViewDoneBlock)(GPLDrawViewType type,NSArray *points,TuoEllipseStruct tuoEllipse);
typedef void (^GPLDrawViewCloseBlock)(GPLDrawViewType type);


@interface GPLDrawLine : UIView

@property (nonatomic, strong) UIColor *strokeColor;

@end

@interface GPLDrawView : UIView
@property (nonatomic, assign) GPLDrawViewType drawType;
@property (nonatomic, strong) UIImage *image;//要绘制的图片
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, copy) GPLDrawViewDoneBlock doneBlock;
@property (nonatomic, copy) GPLDrawViewCloseBlock closeBlock;
- (void)addDoneBtnEvent:(GPLDrawViewDoneBlock)done closeEvent:(GPLDrawViewCloseBlock)close;

@end
