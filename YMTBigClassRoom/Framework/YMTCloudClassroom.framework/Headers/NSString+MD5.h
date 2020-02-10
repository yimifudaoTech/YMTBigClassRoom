//
//  NSString+MD5Encrypt.h
//  Smile
//
//  Created by 周 敏 on 12-11-24.
//  Copyright (c) 2012年 BOX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (MD5)
/** 小写md5*/
- (NSString *)md5String;
/** 大写MD5*/
- (NSString *)md5Encrypt;

/** 特殊字符处理 */
+ (NSString *)urlEncodedString:(NSString *)str;

@end
