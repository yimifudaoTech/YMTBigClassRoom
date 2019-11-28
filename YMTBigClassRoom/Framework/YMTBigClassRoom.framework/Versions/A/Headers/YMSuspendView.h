//
//  YMSuspendView.h
//  student
//
//  Created by juwanli on 2019/10/8.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMSuspendViewType) {
    YMSuspendTimerViewTypeNone = 0,  //根据左右距离的一半自动居左局右
    YMSuspendTimerViewTypeLeft,      //居左
    YMSuspendTimerViewTypeRight,     //居右
    YMSuspendTimerViewTypeAll,       //所有位置
};

@interface YMSuspendView : UIView
@property (nonatomic,assign)YMSuspendViewType type;
@property (nonatomic,copy) void (^tapBlock)(void);
@property (nonatomic, copy) void (^multiTapBlock)(void);

/**
 在UIWindow上显示浮动窗口
 @param type 可以移动的位置枚举
 */
+ (instancetype)showWithTypeOnWindow:(YMSuspendViewType)type;

/**
 在UIWindow上显示浮动窗口,支持点击回调
 @param type 自动吸边的位置枚举
 @param tapBlock 点击回调block
 */
+ (instancetype)showWithTypeOnWindow:(YMSuspendViewType)type tapBlock:(void (^)(void))tapBlock;


/**
 在父View上显示浮动窗口
 @param type 自动吸边的位置枚举
 @param parentView 父View
 */
+ (instancetype)showWithTypeOnParentView:(YMSuspendViewType)type parentView:(UIView *)parentView;


/**
 在父View上显示浮动窗口，支持点击回调
 @param type 自动吸边的位置枚举
 @param parentView 父View
 @param tapBlock 点击回调
 */
+ (instancetype)showWithTypeOnParentView:(YMSuspendViewType)type parentView:(UIView *)parentView tapBlock:(void (^)(void))tapBlock;


/**
 窗口是否允许拖动

 @param isEnable YES 能够拖动，NO 不能拖动
 */
- (void)enableDrag:(BOOL)isEnable;

/**
 移除
 */
- (void)remove;

@end

NS_ASSUME_NONNULL_END
