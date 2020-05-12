//
//  JRCalendarView.h
//  Test
//
//  Created by mac on 2019/5/6.
//  Copyright © 2019年 mac. All rights reserved.

#import <UIKit/UIKit.h>
#import "JRCalendarScrollView.h"
#import "CalendarMacroHeader.h"

@protocol JRCalendarDelegate <NSObject>

/** 获得点击的日期与滑动状态 */
- (void)calendarDidSelectedWithDate:(NSDate *)date motionViewType:(JRCalendarMotionViewType )motionViewType;

/** 获得日历是否被收起 */
- (void)calendarDidSelectedPutAway:(BOOL )isPutAway;

@end
@interface JRCalendarView : UIView

/** 代理属性 */
@property (nonatomic, weak) id<JRCalendarDelegate> calendarDelegate;

/** 日历view */
@property (nonatomic, strong) JRCalendarScrollView *calendarScrollView;

/** 日历下方自定义view */
@property (nonatomic, strong) UIView *customView;

/**
 *  单纯的日历（日历头+日历）
 *  frame:          日历头+日历+自定义view的frame  ( kScreenWidth*6/7+kCalendarHeaderViewHeight )
 */
- (instancetype)initWithFrame:(CGRect)frame;

/**
 *  日历下方带自定义view
 *  frame：         日历头+日历+自定义view的frame
 *  calendarHeight：日历头+日历的高度（一般传 kScreenWidth*6/7+kCalendarHeaderViewHeight）
 *  isShowSingle：  初始化后是否单行显示
 */
- (instancetype)initWithFrame:(CGRect)frame withCalendarHeight:(CGFloat)calendarHeight withShowSingle:(BOOL)isShowSingle;

/**
 *  日历向左滑动
 */
- (void)slideToTheLeft;

/**
 *  日历向右滑动
 */
- (void)slideToTheRight;

/**
 *  日历向上滑动
 */
- (void)slideToTheTop;

/**
 *  日历向下滑动
 */
- (void)slideToThedDown;

/**
 *  回到今天点击方法
 */
- (void)refreshToCurrentDate;

@end
