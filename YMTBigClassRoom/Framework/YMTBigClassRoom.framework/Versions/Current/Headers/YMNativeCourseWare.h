//
//  YMBigClassViewForGroupRoom.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2016/11/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMCourseWareLayer.h"
#import "NSString+Empty.h"
#import "UIView+Geometry.h"
#import "UIColor+Create.h"

@interface YMNativeCourseWare : UIView

@property(nonatomic, assign) BOOL is16_9version;

- (void)setHidden:(BOOL)hidden;

- (void)showImageCourseware:(NSString *)imageUrl;

@end
