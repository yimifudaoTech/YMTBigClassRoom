//
//  YMFlow.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMFlowSettings.h"
#import "YMFlowTaskHandler.h"
#import "YMFlowDelegate.h"
#import "YMFPushNotifyDelegate.h"
#import "YMFLogUtil.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMFlow : NSObject

+ (void)initializeFlow;
+ (void)initializeFlowWithXlogPath:(nullable NSString *)xlogPath;
+ (void)destroy;
+ (void)connect;

+ (void)setIp:(NSString *)mainIp backupIps:(nullable NSArray<NSString *> *)backupIps port:(int)port;

+ (int)sendMessage:(NSString *)msg;
+ (int)sendMessage:(NSString *)msg taskCallback:(YMFlowTaskOnFinish)callback;

+ (void)cancelTaskWithID:(int)taskID;
+ (void)clearAllTasks;

+ (void)setPushMsgHandler:(id<YMFPushNotifyDelegate>)pushMsgHandler cmdID:(int)cmdID;

+ (void)setForeground:(BOOL)isForeground;

+ (void)setFlowCallback:(id<YMFlowDelegate>)flowCallback;

+ (void)setAccountInfoWithUin:(long)uin userNmae:(NSString *)userName;

@end

NS_ASSUME_NONNULL_END
