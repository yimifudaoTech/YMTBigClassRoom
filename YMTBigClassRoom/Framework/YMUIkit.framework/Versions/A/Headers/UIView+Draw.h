//
//  UIView+Draw.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2016/11/18.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Draw)
- (void)setViewRadius:(float)radius color:(UIColor *)color width:(float)width;

// 创建渐变图层和圆角
- (void)setGradientLayerWithFrame:(CGRect)frame beginHexColor:(NSString *)beginHexColor endHexColor:(NSString *)endHexColor cornerRadius:(CGFloat)cornerRadius;

@end
