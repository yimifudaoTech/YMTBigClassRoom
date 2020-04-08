//
//  YMPerformanceInfo.h
//  YMBaseLib
//
//  Created by yimi on 2020/3/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMPerformanceInfo : NSObject

@property (nonatomic, assign) float cpuUsage;
@property (nonatomic, assign) float memoryUsage;
@property (nonatomic, assign) float fps;
@property (nonatomic, assign) float batteryLevel;

@end

NS_ASSUME_NONNULL_END
