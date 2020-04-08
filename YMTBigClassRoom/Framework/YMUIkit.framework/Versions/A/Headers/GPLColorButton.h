//
//  GPLColorButton.h
//  TestButton
//
//  Created by 顾鹏凌 on 2017/6/7.
//  Copyright © 2017年 顾鹏凌. All rights reserved.
//  自定义的笔颜色和线宽按钮

#import <UIKit/UIKit.h>

@interface GPLColorButton : UIButton

/** 选中时边框颜色 */
@property (nonatomic, strong) UIColor * lineColor;
/** 圆心颜色 */
@property (nonatomic, assign) CGFloat lineWidth;

/** 中间颜色 */
@property (nonatomic, strong) UIColor * fillColor;
/** 边框与圆距离 */
@property (nonatomic, assign) CGFloat space;

/** 实心圆颜色 */
@property (nonatomic, strong) UIColor * smallFillColor;
/** 实心圆半径 */
@property (nonatomic, assign) CGFloat smallCircleR;



@end
