//
//  JRCalendarScrollView.h
//  Test
//
//  Created by mac on 2019/4/29.
//  Copyright © 2019年 mac. All rights reserved.
//  单纯的日历scrollView

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,JRCalendarMotionViewType) {
    JRCalendarMotionViewTypeInitialize,
    JRCalendarMotionViewTypeClick,
    JRCalendarMotionViewTypeLeft,
    JRCalendarMotionViewTypeRight,
};

typedef void(^PassDateBlock)(NSDate *date, JRCalendarMotionViewType motionViewType);// 点击日期或是否滑动block
@interface JRCalendarScrollView : UIScrollView

/** 日期传递与被滑动block */
@property (nonatomic, copy) PassDateBlock passDateBlock;

/** 当前月的日期 */
@property (nonatomic, strong) NSDate *currentMonthDate;

/** 当前选中的cell的日期（eg：7、19、31） */
@property (nonatomic, assign) NSInteger currentDateNumber;

/** 是否单行显示 */
@property (nonatomic, assign) BOOL isShowSingle;

/** 当前月有小圆点标记的dateString数组 */
@property (nonatomic, strong) NSMutableArray<NSString *> *pointsArray;

/** 刷新collectionView */
- (void)reloadCollectionViews;

/** 向左滑 */
- (void)calendarToTheLeft;

/** 向右滑 */
- (void)calendarToTheRight;

/** 回到今天 */
- (void)refreshToCurrentDate;

/** 回到已选中日期 */
- (void)refreshToSelectedDate;

@end
