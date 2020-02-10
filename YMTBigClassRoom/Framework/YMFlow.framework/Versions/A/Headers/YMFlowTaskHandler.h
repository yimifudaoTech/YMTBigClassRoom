//
//  YMFlowTaskHandler.h
//  YMFlow
//
//  Created by Caffrey on 2019/1/30.
//

#import <Foundation/Foundation.h>
#import "YMFTaskNotifyDelegate.h"
#import "YMFlowTask.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^YMFlowTaskOnFinish)(YMFlowTask *taskInfo);

@interface YMFlowTaskHandler : NSObject<YMFTaskNotifyDelegate>

@property (readonly) YMFlowTask *taskInfo;
@property (nonatomic, copy) YMFlowTaskOnFinish onFinish;

- (instancetype)initWithMessage:(NSString *)msg;

@end

NS_ASSUME_NONNULL_END
