//
//  YMTSideButtonbar.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/6.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, YMTSideButtonType) {
    YMTSideButtonTypeDevice       = 0,
    YMTSideButtonTypeChat         = 1,
    YMTSideButtonTypeHandUp       = 2,
    YMTSideButtonTypeNoChoice     = 3,
};

@protocol YMTSideButtonbarDelegate <NSObject>

- (void)sideBarButtonDidClicked:(UIButton *)sender type:(YMTSideButtonType)buttonType;

@end


@interface YMTSideButtonbar : UIView

@property (nonatomic, weak) id<YMTSideButtonbarDelegate> delegate;

@property (nonatomic, assign) BOOL handButtonOnline;
@property (nonatomic, assign) BOOL handButtonSelected;
@property (nonatomic, assign) NSInteger handldButtonWaitTime;

- (instancetype)initWithFrame:(CGRect)frame removeType:(YMTSideButtonType )removeType;

- (void)setButtonSelected:(BOOL)selected type:(YMTSideButtonType)buttonType;

- (void)handButtonCountDown:(NSInteger)countDownTime;

- (void)setBadgeViewHidden:(BOOL)hidden;

@end

NS_ASSUME_NONNULL_END
