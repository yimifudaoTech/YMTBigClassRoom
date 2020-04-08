//
//  UIImage+ScreenShot.h
//  YiMiApp
//
//  Created by 王建伟 on 16/3/22.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (ScreenShot)
/**
 *  从屏幕上按比例截取原图
 *
 *  @param image      要截取的图片
 *  @param rect       要截取图片在屏幕上的实际比例
 *  @param screenRect 屏幕的大小
 *
 *  @return 获取到截取到的原图
 */
+(UIImage *)getHighImageFromImage:(UIImage *)image ImageShotRect:(CGRect)rect ScreenRect:(CGRect)screenRect;
/**
 *  按图片大小来缩放屏幕截取原图
 *
 *  @param image          要截取的图片
 *  @param rect           要截取图片在屏幕上的实际比例
 *  @param courseViewRect courseView的大小
 *  @param screenRect     屏幕的大小
 *
 *  @return 获取到截取到的原图
 */
+(UIImage *)getHighImageFromImage:(UIImage *)image ImageShotRect:(CGRect)rect courseViewRect:(CGRect)courseViewRect ScreenRect:(CGRect)screenRect;



+(UIImage *)getScreenShotImageFrom:(UIView*)courseLayer screenRect:(CGRect)rect;
@end
