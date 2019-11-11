//
//  UIImage+Extension.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/11/5.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Extension)

/**
 压缩图片到指定尺寸
 @param sourceImage 原始图片
 @param targetSize  压缩的尺寸
 @return 处理后的image
 */
+ (UIImage *)compressImage:(UIImage *)sourceImage toTargetSize:(CGSize)targetSize;

@end

NS_ASSUME_NONNULL_END
