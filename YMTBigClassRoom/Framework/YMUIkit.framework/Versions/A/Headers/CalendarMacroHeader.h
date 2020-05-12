//
//  GeneralMacroHeader.h
//  Test
//
//  Created by mac on 2019/5/7.
//  Copyright © 2019年 mac. All rights reserved.
//

#ifndef CalendarMacroHeader_h
#define CalendarMacroHeader_h
#import "UIColor+Create.h"
#import "Macro_System.h"

// 日历头的高度
#define kCalendarHeaderViewHeight 30

// 日历头 文字的颜色
#define Color_Text_CalendarHeaderView_Label ColorHex(@"A4A4A4")
// 上月||下月 文字的颜色
#define Color_Text_PreviousOrNextMonth ColorHex(@"AAA8A8")
// 当前月 选中的日期 文字的颜色
#define Color_Text_CurrentMonth_Selected ColorHex(@"FFFFFF")
// 当前月 未选中日期 文字的颜色
#define Color_Text_CurrentMonth_UnSelected ColorHex(@"000000")
// 当前月 有课程日期 文字的颜色
#define Color_Text_CurrentMonth_getCourse ColorHex(@"FF5500")

// 日历头背景色
#define Color_CalendarHeaderView_Bg ColorHex(@"F8F8F8")
// collectionView 的背景色
#define Color_collectionView_Bg ColorHex(@"F8F8F8")
// currentSelectView 当前有课的边框颜色
#define Color_currentSelectView_Border_courseDay ColorHex(@"FF5500")
// currentSelectView 当前日期的背景色
#define Color_currentSelectView_Border_CurrentDay ColorHex(@"80cdff")
// currentSelectView 选中时的背景色
#define Color_currentSelectView_Bg_Selected ColorHex(@"FF5500")
// currentSelectView 今天选中时的背景色
#define Color_currentSelectView_todayBg_Selected ColorHex(@"FFFFFF")

// 日历头 label的字体大小
#define Font_CalendarHeaderLabel IS_IPAD ? [UIFont systemFontOfSize:16]:[UIFont systemFontOfSize:11]
// 阳历label的字体大小
#define Font_solarDateLabel IS_IPAD ?[UIFont systemFontOfSize:16]:[UIFont systemFontOfSize:13]
// 农历label的字体大小
#define Font_lunarDateLabel IS_IPAD ?[UIFont systemFontOfSize:12]:[UIFont systemFontOfSize:10]



#endif /* CalendarMacroHeader_h */
