//
//  YMToastView.h
//  YMToast
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, YMToastType) {
    YMToastTypeSuccess = 0,
    YMToastTypeError,
    YMToastTypeWords,
    YMToastTypeImage,
};

@interface YMToastView : UIView

+ (instancetype)toastWithMessage:(NSString *)message type:(YMToastType)type originY:(CGFloat)originY tipImage:(UIImage *)image;

@end
