//
//  YMToolBarConfig.h
//

#ifndef YMToolBarConfig_h
#define YMToolBarConfig_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define kRubberViewFrame     (CGRectMake(0.f, 0.f, 210.f, 120.f))
#define kBrushViewFrame      (CGRectMake(0.f, 0.f, 200.f, 210.f))
#define kBubbleContentInsets (UIEdgeInsetsMake(0.f, 0.f, -10.f, 5.f))

#define kFF6633Color [UIColor colorWithRed:255/255.f green:102/255.f blue:51/255.f alpha:1.0]
#define k666666Color [UIColor colorWithRed:102/255.f green:102/255.f blue:102/255.f alpha:1.0]
#define kF6F6F6Color [UIColor colorWithRed:246/255.f green:246/255.f blue:246/255.f alpha:1.0]
#define kFFF9F6Color [UIColor colorWithRed:255/255.f green:249/255.f blue:246/255.f alpha:1.0]
#define kF3F3F3Color [UIColor colorWithRed:243/255.f green:243/255.f blue:243/255.f alpha:1.0]
#define kEEEEEEColor [UIColor colorWithRed:238/255.f green:238/255.f blue:238/255.f alpha:1.0]
#define kCCCCCCColor [UIColor colorWithRed:204/255.f green:204/255.f blue:204/255.f alpha:1.0]

// 画笔事件
static NSString * const kSelectBurshResponderEvent = @"kSelectBurshResponderEvent";
static NSString * const kSliderValueChangedKey = @"kSliderValueChangedKey";

// 橡皮擦事件
static NSString * const kRubberEventRevokeKey = @"kRubberEventRevokeKey";
static NSString * const kRubberEventAllCleanKey = @"kRubberEventAllCleanKey";

// 画笔事件信息
static NSString *const kPenEventBrushInfoKey = @"kPenEventBrushInfoKey";
static NSString *const kPenEventColorInfoKey = @"kPenEventColorInfoKey";

static NSString * const kRubberCleanEventKey = @"kRubberCleanEventKey";
static NSString * const kRubberRevokeEventKey = @"kRubberRevokeEventKey";

// 底部工具栏画笔和橡皮擦信息key
static NSString *const kDrawPenLineWidthInfoKey = @"kDrawPenLineWidthKey";
static NSString *const kDrawEraseLineWidthInfoKey = @"kDrawEraseLineWidthKey";


// 底部橡皮擦view表征数据key
static NSString* const kSDSCRubberViewCleanAllKey = @"kSDSCRubberViewCleanAllKey";
static NSString* const kSDSCRubberViewRevokeKey = @"kSDSCRubberViewRevokeKey";




#endif /* YMToolBarConfig_h */

