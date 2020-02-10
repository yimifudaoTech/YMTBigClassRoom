//
//  GPLSCServerSafeTool.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/11/16.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YMTSCServerSafeTool : NSObject

/**
 data 转 hex

 @param data data数据包
 @return hex字符串
 */
+ (NSString *)hexStringForData:(NSData *)data;
/**
 hex 转 data

 @param hexString hex字符串
 @return data数据包
 */
+ (NSData *)dataForHexString:(NSString *)hexString;

/**
 加密

 @param data 明文数据
 @param useAES 是否使用aes
 @return 加密后的数据
 */
+ (NSData *)encryptWithKnowData:(NSData *)data useAES:(BOOL)useAES;

/**
 解密

 @param data 加密数据
 @param useAES 是否使用aes
 @return 明文数据
 */
+ (NSData *)decryptWithUnknowData:(NSData *)data useAES:(BOOL)useAES;

@end
