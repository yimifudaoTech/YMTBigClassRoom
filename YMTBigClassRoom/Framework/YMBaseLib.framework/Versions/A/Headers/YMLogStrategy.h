//
//  YMLogStrategy.h
//  YMLogLib
//
//  Created by juwanli on 2019/9/23.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

@class YMLogTunnelFactory;

@interface YMLogStrategy : NSObject

/**
 根据策略类型获取通道工厂
 @param strategyType 策略枚举类型
 */
- (YMLogTunnelFactory *)getLogTunnelFactory:(YMLogStrategyType)strategyType;

@end

NS_ASSUME_NONNULL_END
