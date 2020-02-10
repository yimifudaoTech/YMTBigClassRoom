//
//  NSString+Emoji.h
//  EduClass
//
//  Created by lyy on 2018/5/4.
//  Copyright © 2018年 talkcloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Emoji)
/**
 *  将十六进制的编码转为emoji字符
 */
+ (NSString *)ymEmojiWithIntCode:(int)intCode;

/**
 *  将十六进制的编码转为emoji字符
 */
+ (NSString *)ymEmojiWithStringCode:(NSString *)stringCode;

/**
 *  是否为emoji字符
 */
- (BOOL)ymIsEmoji;
/**
 判断是不是九宫格
 @param string  输入的字符
 @return YES(是九宫格拼音键盘)
 */
+ (BOOL)isNineKeyBoard:(NSString *)string;
/**
 *  判断字符串中是否存在emoji  判断第三方键盘 常见的搜狗键盘
 * @param string 字符串
 * @return YES(含有表情)
 */
+ (BOOL)hasEmoji:(NSString*)string;

@end
