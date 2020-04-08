//
//  YMPerformanceView.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/20.
//

#import "YMSuspendView.h"
#import <YMBaseLib/YMPerformanceInfo.h>
NS_ASSUME_NONNULL_BEGIN

@interface YMPerformanceView : YMSuspendView

- (void)updatePerformanceInfo:(YMPerformanceInfo *)info;
@end

NS_ASSUME_NONNULL_END
