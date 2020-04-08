//
//  CXVaildation.h
//  YiMiApp
//
//  Created by 钱浩 on 15/11/10.
//  Copyright © 2015年 xieyan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "sys/utsname.h"
@interface CXVaildation : NSObject
+ (BOOL)validateMobile:(NSString *)mobileNum;
+ (BOOL)validateEmail:(NSString *)email;
+(BOOL)validUserName:(NSString* )userName;
+(BOOL)validUserPassword:(NSString*)userPassword;
+(NSString *)getgetDeviceName;
@end
