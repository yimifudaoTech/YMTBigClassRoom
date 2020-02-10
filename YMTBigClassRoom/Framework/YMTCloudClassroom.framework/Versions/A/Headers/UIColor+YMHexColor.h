//
//  UIColor+YMHexColor.h
//  AFNetworking
//
//  Created by mystarains on 2019/9/17.
//

#import <UIKit/UIKit.h>

#define YMColorHex(__HEX__) [UIColor yimi_colorWithHexString:__HEX__]

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (YMHexColor)

@property(nonatomic ,copy, readonly) NSString *hexString;

+ (instancetype)yimi_colorWithHexString:(NSString*)hexColor;

+ (instancetype)randomColor;

@end

NS_ASSUME_NONNULL_END
