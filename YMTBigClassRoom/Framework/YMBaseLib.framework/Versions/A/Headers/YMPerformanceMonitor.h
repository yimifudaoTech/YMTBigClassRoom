//
//  YMPerformanceMonitor.h
//  YMBaseLib
//
//  Created by yimi on 2020/3/20.
//

#import <Foundation/Foundation.h>
@class YMPerformanceInfo;

NS_ASSUME_NONNULL_BEGIN

typedef void(^YMPerformanceUpdateBlock)(YMPerformanceInfo *info);

@interface YMPerformanceMonitor : NSObject

- (void)startMonitorWithblock:(YMPerformanceUpdateBlock)block;

- (void)stopMonitor;


@end

NS_ASSUME_NONNULL_END
