//
//  HSBubbleView.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/14.
//  Copyright © 2018年 peanut. All rights reserved.
//
// 气泡框
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, BubbleDirection) {
    BubbleDirection_Top = 0,
    BubbleDirection_Bottom,
    BubbleDirection_Left,
    BubbleDirection_Right
};

typedef NS_ENUM(NSInteger,BubblePosition) {
    BubblePosition_Center = 0,
    BubblePosition_LeftBottom,
    BubblePosition_RightTop
};

@interface HSBubbleView : UIView

// 凸点的位置（0-1）
@property (nonatomic, assign) CGFloat bubblePosition;
// 凸点的宽度
@property (nonatomic, assign) CGFloat bubbleWidth;

@property (nonatomic, copy) void(^removeBlockEvent)(UIView *contentView);


+ (HSBubbleView *)showBubbleViewTo:(UIView *)to relation:(UIView *)with direction:(BubbleDirection)direction position:(BubblePosition)position;

- (void)setContentView:(UIView *)view;

@end
