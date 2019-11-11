//
//  HSSliderView.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/15.
//  Copyright © 2018年 peanut. All rights reserved.
//
// 自定义滑杆
#import <UIKit/UIKit.h>

@interface HSSliderView : UIView

@property (nonatomic) CGFloat minValue;
@property (nonatomic) CGFloat maxValue;
@property (nonatomic) CGFloat value;

@property (nonatomic,strong) UIColor *maximumColor;
@property (nonatomic,strong) UIColor *minimumColor;

@end
