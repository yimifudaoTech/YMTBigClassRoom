//
//  YMBigClassViewForGroupRoom.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2016/11/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMCourseWareLayer.h"
#import <YMBaseLib/NSString+Empty.h>
#import <YMUIkit/UIView+Geometry.h>
#import <YMUIkit/UIColor+Create.h>

@interface YMNativeCourseWare : UIView

@property (nonatomic, assign) CGFloat coursewareAspectRatio;

- (void)setHidden:(BOOL)hidden;

- (void)showImageCourseware:(NSString *)imageUrl;

@end
