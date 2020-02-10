//
//  NetworkDelegate.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//


#import "YMFTaskNotifyDelegate.h"
#import "YMFPushNotifyDelegate.h"
#import "YMFlowDelegate.h"

@class YMFlowTask;

@protocol YMFNetworkDelegate <YMFlowDelegate>

@required - (void)addPushObserver:(id<YMFPushNotifyDelegate>)observer withCmdId:(int)cmdId;
@required - (void)removePushObserverWithCmdId:(int)cmdId;
@required - (void)removeAllPushObserver;


@required - (void)addObserver:(id<YMFTaskNotifyDelegate>)observer forKey:(NSString *)key;
@required - (void)removeObserverForKey:(NSString *)key;
@required - (void)removeAllObserver;

@required - (void)addCGITasks:(YMFlowTask*)cgiTask forKey:(NSString *)key;
@required - (void)removeCGITasksForKey:(NSString *)key;
@required - (void)removeAllCGITasks;

@required @property (nonatomic, weak) id<YMFlowDelegate> flowCallback;

@required - (BOOL)isAuthed;
@optional - (void)onPushWithCmd:(NSInteger)cid data:(NSData *)data;

@required - (NSData *)request2BufferWithTaskID:(uint32_t)tid;
@required - (int)buffer2ResponseWithTaskID:(uint32_t)tid responseData:(NSData *)data;
//
@required - (int)onTaskEndWithTaskID:(uint32_t)tid errType:(uint32_t)errtype errCode:(uint32_t)errcode;

@end

