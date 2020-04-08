//
//  HorizontalTwoLabelsView.h
//  YiMiApp
//
//  Created by 关雷 on 15/10/19.
//  Copyright © 2015年 xieyan. All rights reserved.
//
/**
 *Example:    
    
    leftLable  rightLable
 
    商品详情：   内容。。。。。。。。。
               。。。。。。。。。。。
    金额：      000000
 */
#import <UIKit/UIKit.h>
#define RightLableWidth self.frame.size.width / 3 * 2
#define RightLableOriginX self.frame.size.width / 3
@interface HorizontalTwoLabelsView : UIView
@property (nonatomic, strong) UILabel *leftLable;
@property (nonatomic, strong) UILabel *rightLable;

/**
 *  设置lable的背景颜色
 *
 *  @param backGroundColor UIColor
 */
- (void)setLablesBackGroundColor:(UIColor *)backGroundColor;

/**
 *  设置leftLable的字体大小
 *
 *  @param fontFloat fontFloat
 */
- (void)setLeftLableFont:(CGFloat)fontFloat;

/**
 *  设置rightLable的字体大小，获取行高时的字体大小是16.0f
 *
 *  @param fontFloat fontFloat
 */
- (void)setRightLableFont:(CGFloat)fontFloat;

/**
 *  根据内容重新布局RightLable
 */
- (void)layoutRightLable;
@end
