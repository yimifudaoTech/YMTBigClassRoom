//
//  ProgressNetwork.h
//  YiMiApp
//
//  Created by xieyan on 15/9/15.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ProgressNetwork : NSObject
+(void)ShowOnView:(UIView*)theview text:(NSString*)text;
+(void)ShowOnView:(UIView*)theview text:(NSString*)text hideAfterDelay:(long) delay;

/**
 一定记得放在主线程
 */
+(id)ShowReturnOnView:(UIView*)theview text:(NSString*)text;
// 显示HUB 后面还可以点击.
+(void)ShowOnViewNoFullScreen:(UIView*)theview text:(NSString*)text;

+(void)ShowOnView:(UIView*)theview;
+(void)HideOnView:(UIView*)theview;

+(void)HideAllOnView:(UIView*)theview;

@end





