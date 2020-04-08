//
//  YMImagePickerController.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/2/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMImagePickerDirection) {
    YMImagePickerDirectionPortrait,// 正常竖屏
    YMImagePickerDirectionLandscapeRight,
};

@interface YMImagePickerController : UIImagePickerController

@property (nonatomic,assign)YMImagePickerDirection direction;

@end

NS_ASSUME_NONNULL_END
