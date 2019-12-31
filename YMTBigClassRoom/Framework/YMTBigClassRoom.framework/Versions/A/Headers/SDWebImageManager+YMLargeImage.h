//
//  SDWebImageManager+LargeImage.h
//  YiMiLib
//
//  Created by peanut on 2019/1/25.
//  Copyright © 2019年 YiMi. All rights reserved.
//

#import "SDWebImageManager.h"

@interface SDWebImageManager (YMLargeImage)

+ (instancetype)sharedManagerForLargeImage;

- (void)downLoadImageWithURL:(NSString *)url callBack:(void(^)(UIImage *image))callBack;

@end
