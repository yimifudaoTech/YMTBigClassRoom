//
//  YMTTimeMeterView.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/12.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, YMTTimeMeterDirection) {
    YMTTimeMeterDirectionClockwise = 1,
    YMTTimeMeterDirectionAnticlockwise = 2
};

typedef NS_ENUM(NSInteger, YMTTimeMeterDirectionOperation) {
    YMTTimeMeterDirectionBegan = 1,
    YMTTimeMeterDirectionPause = 2,
    YMTTimeMeterDirectionReset = 3,
    YMTTimeMeterDirectionClose = 4
};


NS_ASSUME_NONNULL_BEGIN

@interface YMTTimeMeterView : UIView

- (instancetype)initWithTimerWithTimeInterval:(NSTimeInterval)interval direction:(YMTTimeMeterDirection)direction;

- (void)startTimer;

- (void)pauseTimer;

- (void)resetTimer;

- (void)closeTimer;

@end

NS_ASSUME_NONNULL_END
