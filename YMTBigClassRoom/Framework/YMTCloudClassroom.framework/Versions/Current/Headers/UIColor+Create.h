//
//  UIColor+Create.h
//  YiMiApp
//
//  Created by xieyan on 15/10/28.
//  Copyright © 2015年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#define ColorHex(__HEX__) [UIColor hexStringColor:__HEX__]

@interface UIColor (UIColor_Create)

- (NSString *)hexString;
+(instancetype)hexStringColor:(NSString*)hexColor;
+ (instancetype)randomColor;

@end
