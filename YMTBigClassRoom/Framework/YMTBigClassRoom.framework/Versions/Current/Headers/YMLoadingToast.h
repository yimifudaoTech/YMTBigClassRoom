//
//  YMLoadingToast.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/11/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMLoadingToast : UIView

- (void)creatMaskView:(UIView *)view imageName:(NSString *)imageName loadingTitle:(NSString *)loadingTitle isHideTitle:(BOOL)isHideTitle setTimerDelay:(CGFloat)seconds;

- (void)closeLoadingTimer;
@end

NS_ASSUME_NONNULL_END
