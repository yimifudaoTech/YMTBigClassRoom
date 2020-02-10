//
//  YMTTimeMeterTool.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/12.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTTimeMeterView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMTTimeMeterTool : NSObject

+ (void)showTimeMeterWithTimeInterval:(NSTimeInterval)interval direction:(YMTTimeMeterDirection)direction inView:(UIView *)view  frame:(CGRect)frame;


+ (void)startTimer;

+ (void)pauseTimer;

+ (void)resetTimer;

+ (void)closeTimer;

@end

NS_ASSUME_NONNULL_END
