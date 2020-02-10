//
//  YMCourseWindowView.h
//  AFNetworking
//
//  Created by yimi on 2019/10/23.
//

#import <UIKit/UIKit.h>
#import "YMBoardWindow.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMCourseWindowView :YMBoardWindow

@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) UIView *bottomView;

- (void)addContentView:(UIView *)contentView;

- (void)addSubviewInContentView:(UIView *)view;

- (void)addTitleView:(CGFloat )referenceViewHeight;

- (void)setTitle:(NSString *)title;

@end

NS_ASSUME_NONNULL_END
