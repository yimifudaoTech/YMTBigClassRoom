//
//  HSSmallClassRoomConfig.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/23.
//  Copyright © 2018年 peanut. All rights reserved.
//

#ifndef HSSmallClassRoomConfig_h
#define HSSmallClassRoomConfig_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define kRubberViewFrame     (CGRectMake(0.f, 0.f, 210.f, 120.f))
#define kBrushViewFrame      (CGRectMake(0.f, 0.f, 200.f, 210.f))
#define kRosterViewFrame     (CGRectMake(0.f, 0.f, 402.f, 400.f))
#define kRFeedBackViewFrame  (CGRectMake(0.f, 0.f, 202.f, 320.f))
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

// 底部工具栏透传信息key
static NSString *const kBottomToolBarColorKey = @"kBottomToolBarColorKey";
static NSString *const kBottomToolBarLineWidthKey = @"kBottomToolBarLineWidthKey";
static NSString *const kBottomToolBarLineTypeKey = @"kBottomToolBarLineTypeKey";

// 底部工具栏表征数据按钮状态key
static NSString *const kBottonToolBarPenButtonKey = @"kBottonToolBarPenButtonKey";
static NSString *const kBottomToolBarEraseButtonKey = @"kBottonToolBarPenButtonKey";
static NSString *const kBottomToolBarRosterButtonKey = @"kBottomToolBarRosterButtonKey";

// 底部花名册表征数据key
static NSString* const kSDSCRosterViewUpdownKey = @"kSDSCRosterViewUpdownKey";
static NSString* const kSDSCRosterViewAuthKey = @"kSDSCRosterViewAuthKey";
static NSString* const kSDSCRosterViewAudioKey = @"kSDSCRosterViewAudioKey";
static NSString* const kSDSCRosterViewVideoKey = @"kSDSCRosterViewVideoKey";
static NSString* const kSDSCRosterViewNameKey = @"kSDSCRosterViewNameKey";
static NSString* const kSDSCRosterViewMedalKey = @"kSDSCRosterViewMedalKey";

// 底部橡皮擦view表征数据key
static NSString* const kSDSCRubberViewCleanAllKey = @"kSDSCRubberViewCleanAllKey";
static NSString* const kSDSCRubberViewRevokeKey = @"kSDSCRubberViewRevokeKey";

// 底部视图表征数据key
static NSString *const kSDSCUserRoleKey         = @"kSDSCuserRoleKey";
static NSString *const kSDSCUserMicVolumeKey    = @"kSDSCUserMicVolumeKey";
static NSString *const kSDSCUserMicStatusKey    = @"kSDSCUserMicStatusKey";
static NSString *const kSDSCUserNameKey         = @"kSDSCUserNameKey";
static NSString *const kSDSCUserCameraStatusKey = @"kSDSCUserCameraStatusKey";

typedef NS_ENUM(NSUInteger, SDSCuserRoleType) {
    SDSCuserRoleType_Stu = 5,
    SDSCuserRoleType_Tea = 10
};

typedef NS_ENUM(NSUInteger, SDSCUserMicState) {
    SDSCUserMicState_Authon = 3, // 打开
    SDSCUserMicState_Authoff = 6, // 关闭
    SDSCUserMicState_Invalid = 9 // 无效，一般是设备原因
};

typedef NS_ENUM(NSUInteger, SDSCUserCameraState) {
    SDSCUserCameraState_Invalid = 4,  // 未进入
    SDSCUserCameraState_Loading = 8,  // 等待视频
    SDSCUserCameraState_Joined  = 12, // 加入完成
    SDSCUserCameraState_Authoff = 16  // 禁止授权
};

typedef NS_ENUM(NSInteger, DrawLineType) {
    DrawLineType_None = 0,
    DrawLineType_Pen,
    DrawLineType_Erase
};

typedef NS_ENUM(NSInteger,SDSCRosterViewState) {
    SDSCRosterViewState_On = 7,
    SDSCRosterViewState_Off = 14,
    SDSCRosterViewState_Unkonw = 21,
};

#endif /* HSSmallClassRoomConfig_h */

