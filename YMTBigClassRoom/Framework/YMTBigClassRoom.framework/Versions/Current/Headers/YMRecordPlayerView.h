//
//  YMRecordPlayView.h
//  student
//
//  Created by mystarains on 2019/8/19.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMRecordPlayDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMRecordPlayerView : UIView

@property(nonatomic, weak) id<YMRecordPlayerViewDelegate> delegate;
@property(nonatomic, assign) CGFloat progress;
@property(nonatomic, assign) NSInteger timeTotal;
@property(nonatomic, assign) NSInteger timeCurrent;
@property(nonatomic, copy) NSString *title;

@property(nonatomic, assign) BOOL showAdjustRate;//播放速率,默认不显示
@property(nonatomic, assign) CGFloat rate;//速率 1, 1.5, 2, 3, 5.

- (void)playOrPause:(YMRecordPlayerViewClickType)type;

- (void)isStuckRecord:(BOOL)isStuck;

@end

NS_ASSUME_NONNULL_END
