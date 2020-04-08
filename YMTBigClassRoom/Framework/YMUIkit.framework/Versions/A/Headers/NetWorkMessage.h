//
//  NetWorkMessage.h
//  YiMiApp
//
//  Created by xieyan on 15/11/30.
//  Copyright © 2015年 xieyan. All rights reserved.
//

#import <Foundation/Foundation.h>
#define kNoNetMessage @"网络不给力哦"
@interface NetWorkMessage : NSObject
+(void)netfailed;
+(void)netfailedTextTip;
+(void)returnFailed:(NSString*)msg;
@end
