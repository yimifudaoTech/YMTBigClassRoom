//
//  HSCirleView.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/21.
//  Copyright © 2018年 peanut. All rights reserved.
//
// 画笔/橡皮擦顶部显示选中信息view

#import <UIKit/UIKit.h>

@interface HSCirleView : UIView

@property (nonatomic,strong) UIColor *outCircleStrokeColor;
@property (nonatomic,strong) UIColor *outCircleFillColor;

@property (nonatomic,strong) UIColor *innerCicleStrokeCOlor;
@property (nonatomic,strong) UIColor *innerCircleFillColor;

@property (nonatomic,assign) CGFloat innerCircleMinRatio;

@end
