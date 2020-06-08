//
//  YMTAnswerTool.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/11.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YMTAnswerConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMTAnswerTool : NSObject

+ (void)startAnswerWithItemId:(NSString *)itemId itemAnswer:(NSString *)itemAnswer optionList:(NSArray *)items countDownTime:(NSTimeInterval)interval  result:(YMTAnswerResult)result;

+ (void)startAnswerWithItemId:(NSString *)itemId itemAnswer:(NSString *)itemAnswer optionList:(NSArray *)items countDownTime:(NSTimeInterval)interval inView:(UIView *)view result:(YMTAnswerResult)result;

+ (void)stopAnswer:(YMAnswerType)type  result:(YMTStopAnswerResult _Nullable)result;

@end

NS_ASSUME_NONNULL_END
