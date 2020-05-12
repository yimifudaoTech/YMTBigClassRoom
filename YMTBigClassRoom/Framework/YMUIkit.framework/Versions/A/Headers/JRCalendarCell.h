//
//  JRCalendarCell.h
//  Test
//
//  Created by mac on 2019/4/29.
//  Copyright © 2019年 mac. All rights reserved.
//  日历collectionViewCell

#import <UIKit/UIKit.h>
@class JRCalendarDayModel;

@interface JRCalendarCell : UICollectionViewCell

/** 阳历日期label（eg：1、2、3日） */
@property (nonatomic, strong) UILabel *solarDateLabel;

/** 农历日期label（eg：初一、初二、初三） */
@property (nonatomic, strong) UILabel *lunarDateLabel;

/** 当前选中日期的蒙版view（标记选中） */
@property (nonatomic, strong) UILabel *currentSelectView;

/** 小圆点 */
@property (nonatomic, strong) UIView *pointView;

/** JRCalendarDayModel（获取阳历、农历string） */
@property (nonatomic, strong) JRCalendarDayModel *dayModel;


@end
