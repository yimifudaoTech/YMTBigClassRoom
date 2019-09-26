//
//  ZQPlayerSDVideoView.h
//  YiMiApp
//
//  Created by 周志强 on 2016/12/15.
//  Copyright © 2016年 YiMi. All rights reserved.
//  自定义学生端 视频播放器控制层 他的代理是播放器View zfplayerView.

#import <UIKit/UIKit.h>
//#import <ZFPlayer/ZFPlayer.h>
#import "ASValueTrackingSlider.h"

typedef void(^ChangeResolutionBlock)(UIButton *button);
typedef void(^SliderTapBlock)(CGFloat value);

@interface ZQPlayerSDVideoView : UIView

/** 全屏按钮点击block */
@property (nonatomic, copy) void(^fullBtnClickBlock)(BOOL isFullScreen);

@end
