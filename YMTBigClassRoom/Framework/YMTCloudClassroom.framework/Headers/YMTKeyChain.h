//
//  YMTKeyChain.h
//  YiMiLib
//
//  Created by mac on 2018/12/13.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString * saveIDFAToKeyChain = @"DIFASAVETOCHAIN";
@interface YMTKeyChain : NSObject

#pragma mark 储存
+ (void)save:(NSString *)service data:(id)data;

#pragma mark 读取
+ (id)loadKeyChain:(NSString *)service;

#pragma mark 删除
+ (void)deleteYMKeyChain:(NSString *)service;




@end
