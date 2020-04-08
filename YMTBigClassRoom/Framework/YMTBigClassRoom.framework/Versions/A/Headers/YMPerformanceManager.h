//
//  YMPerformanceManager.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/21.
//

#import <Foundation/Foundation.h>
#import <YMBaseLib/YMPerformanceMonitor.h>
#import "YMPerformanceView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMPerformanceManager : NSObject

- (void)showPerformanceView;

- (void)hidePerformanceView;



@end

NS_ASSUME_NONNULL_END
