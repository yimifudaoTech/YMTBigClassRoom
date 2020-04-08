//
//  YMTTopBar.h
//  APro
//
//  Created by 黄鹏飞 on 2019/9/11.
//  Copyright © 2019 com.hpf. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, YMClassState) {
    YMClassStateFreedom,            //自由模式（未开始上课）
    YMClassStateStarted,            //开始上课（上课中）
    YMClassStateInterruption,       //课程中断（老师退出）
    YMClassStateEnd,                //课程结束
};

NS_ASSUME_NONNULL_BEGIN

typedef void(^YMTTopBarExitHandle)(void);

#define ISIPAD UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad ? 1 : 0

@protocol  YMTTopBarDelegate <NSObject>

- (void)exitTopBarDelegate;

@optional
- (void)topBarOnTap:(id)sender;

@end

typedef NS_ENUM(NSInteger,YMTTopBarType) {
    YMTTopBarTypeOneToOne,      // 一对一
    YMTTopBarTypeSmallClass,    // 小组课
    YMTTopBarTypeBigClass,      // 大班课
};

@interface YMTTopBar : UIView

@property (nonatomic, weak) id<YMTTopBarDelegate> delegate;
    
/// exit handle
@property (nonatomic, copy, readwrite) YMTTopBarExitHandle exitHandle;
@property (nonatomic, assign, readwrite) YMTTopBarType topBarType;
@property (nonatomic, assign, readwrite) NSInteger classNumber;
    
- (void)setupWithTitle:(NSString *)title state:(YMClassState)state cupNum:(NSString *)cupNum score:(NSString *)score;

- (void)setupPingIP:(NSString *)pingIP;

- (void)invalidateTimer;

@end

NS_ASSUME_NONNULL_END
