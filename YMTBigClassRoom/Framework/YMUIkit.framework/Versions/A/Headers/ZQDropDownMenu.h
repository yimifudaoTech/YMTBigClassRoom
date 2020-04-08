//
//  ZQDropDownMenu.h
//  
//
//  Created by 周志强 on 15/10/11.
//  Copyright (c) 2015年. All rights reserved.
//

#import <UIKit/UIKit.h>

static NSString * const keyNotify_ZQDropDownMenuDismiss = @"ZQDropDownMenuDismiss";

@interface ZQDropDownMenu : UIView
/**
 *  将来用来显示具体内容的容器
 */
@property (nonatomic, weak) UIImageView *containerView;

+ (instancetype)menu;

/**
 *  显示
 */
- (void)showFrom:(UIView *)from withSuperView:(UIView *)superView;
/**
 *  销毁
 */
- (void)dismiss;


/**
 刷新内容view 的frame
 */
- (void)refreshBGFrame:(UIView *)content;
/**
 *  内容
 */
@property (nonatomic, strong) UIView *content;
/**
 *  内容控制器
 */
@property (nonatomic, strong) UIViewController *contentController;
@end
