//
//  YMBlankPlaceHolderView.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/4/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMBlankPlaceHolderView : UIView

+ (void)showBlankPlaceHolderWithView:(UIView *)superView imageName:(NSString *)imageName title:(NSString *)title;

+ (void)hiddenBlankPlaceHolderView:(UIView *)superView;

@end

NS_ASSUME_NONNULL_END
