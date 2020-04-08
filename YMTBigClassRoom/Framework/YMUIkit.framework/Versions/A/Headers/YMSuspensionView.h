//
//  YMSuspensionView.h
//  YMUILib
//
//  Created by juwanli on 2019/9/23.
//  Copyright © 2019 YiMi. All rights reserved.
//

/**
 虚拟Home键：
 如果对按钮风格没有变化，直接设置给出的属性值。
 如果要做定制化的按钮，直接设置homeBtn。
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMSuspensionViewType) {
    YMSuspensionViewTypeNone = 0,  //根据左右距离的一半自动居左居右
    YMSuspensionViewTypeLeft,      //居左
    YMSuspensionViewTypeRight,     //居右
    YMSuspensionViewTypeAll,       //所有位置
};

typedef void(^SuspensionViewTapBlock)(void);

@interface YMSuspensionView : UIView

/**
 初始化靠屏幕右边边距
 */
@property (nonatomic, assign) CGFloat initialMarginRight;

/**
 初始化靠屏幕底部边距
 */
@property (nonatomic, assign) CGFloat initialMarginBottom;

/**
 home按键的尺寸
 */
@property (nonatomic, assign) CGSize buttonSize;


/**
 按钮的图片
 */
@property (nonatomic, strong) NSString *btnImageName;

/**
 按钮的文字
 */
@property (nonatomic, strong) NSString *btnTitle;

/**
 home键
 */
@property (nonatomic, strong) UIButton *homeBtn;


/**
 在view上显示
 
 @param view 视图
 */
- (void)showWithView:(UIView *)view;

/**
 在vc上显示
 
 @param vc 控制器
 */
- (void)showWithVC:(UIViewController *)vc;

/**
 隐藏
 */
- (void)hide;

/**
 初始化函数
 
 @param tapHome 点击home键的事件
 @return 实例
 */
- (instancetype)initWithType:(YMSuspensionViewType)type tapAction:(SuspensionViewTapBlock)tapHome;

/**
 初始化函数
 
 @param tapHome 点击home键的事件
 @return 实例
 */
+ (instancetype)suspensionViewWithType:(YMSuspensionViewType)type tapAction:(SuspensionViewTapBlock)tapHome;

/**
 初始化函数
 
 @param imgName 按钮图片
 @param tapHome 点击home键的事件
 @return 实例
 */
+ (instancetype)suspensionViewWithType:(YMSuspensionViewType)type imageName:(NSString *)imgName tapAction:(SuspensionViewTapBlock)tapHome;

/**
 初始化函数
 
 @param rMargin 右边距
 @param bMargin 下边距
 @param btnSize 按钮的大小
 @param imgName 按钮图片
 @param tapHome 点击home键的事件
 @return 实例
 */
+ (instancetype)suspensionViewWithRightMargin:(CGFloat)rMargin
                              bottomMargin:(CGFloat)bMargin
                                buttonSize:(CGSize)btnSize
                                 imageName:(NSString *)imgName
                                 type:(YMSuspensionViewType)type
                                 tapAction:(SuspensionViewTapBlock)tapHome;

@end

NS_ASSUME_NONNULL_END
