//
//  XYZCursorView.h
//  YiMiApp
//
//  Created by xieyan on 16/4/27.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XYZView.h"

typedef NS_ENUM(NSInteger,XYZCursorViewType) {
    XYZCursorViewType_None = 0,
    XYZCursorViewType_OneToOne,
    XYZCursorViewType_SmallClass,
    XYZCursorViewType_BigClass
};

@interface XYZCursorView : XYZView

//比例点
@property (nonatomic,assign) CGPoint currentRatePoint;
//实际点
@property (nonatomic,assign) CGPoint currentPoint;
@property (nonatomic,assign) BOOL isAutoHide;
@property (nonatomic,assign) XYZCursorViewType cursorType;
@property (nonatomic,copy) void(^point)(CGFloat pointX,CGFloat pointY);
@property (nonatomic,copy) void(^hiddenBlock)(BOOL hidden);
// 手写板
- (void)handleTouchEvent:(CGPoint)point previous:(CGPoint)previous;
- (void)handlePendoSuspendedEvent:(CGPoint)point;

@end
