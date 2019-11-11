//
//  ZQPlayerVideoView.h
//  YiMiApp
//
//  Created by 周志强 on 2016/12/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//  自定义老师端视频播放器控制层 他的代理是播放器View zfplayerView.

//#import <ZFPlayer/ZFPlayer.h>
#import <ZFPlayer/ASValueTrackingSlider.h>

typedef void(^ChangeResolutionBlock)(UIButton *button);
typedef void(^SliderTapBlock)(CGFloat value);

@interface ZQPlayerVideoView : UIView

/** 全屏按钮点击block */
@property (nonatomic, copy) void(^fullBtnClickBlock)(BOOL isFullScreen);

@end
