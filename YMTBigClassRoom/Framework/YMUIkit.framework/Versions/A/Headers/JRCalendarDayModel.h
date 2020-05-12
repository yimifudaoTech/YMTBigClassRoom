//
//  JRCalendarDayModel.h
//  Test
//
//  Created by mac on 2019/4/30.
//  Copyright © 2019年 mac. All rights reserved.
//  每一天对应的model

#import <Foundation/Foundation.h>

@interface JRCalendarDayModel : NSObject

/** 阳历日期 */
@property (nonatomic, strong) NSString *solarDateString;

/** 农历日期 */
@property (nonatomic, strong) NSString *lunarDateString;

@end
