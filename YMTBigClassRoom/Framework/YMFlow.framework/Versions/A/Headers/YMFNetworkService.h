//
//  YMFNetworkService.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//

#ifndef NetworkService_h
#define NetworkService_h

#import <Foundation/Foundation.h>

#import "YMFNetworkDelegate.h"
#import "YMFNetworkStatus.h"
#import "YMFPushNotifyDelegate.h"
#import "YMFlowDelegate.h"

@class YMFlowTask;

@interface YMFAccountInfo : NSObject
@property (nonatomic, assign) long uin;
@property (nonatomic,copy) NSString *username;
@end

@interface YMFDeviceInfo : NSObject
@property (nonatomic,copy) NSString *devicename;
@property (nonatomic,copy) NSString *devicetype;
@end

@interface YMFNetworkService : NSObject<YMFNetworkStatusDelegate>

@property(nonatomic, strong) id<YMFNetworkDelegate> delegate;

+ (YMFNetworkService*)sharedInstance;

- (void)setCallBack;
- (void)createMars;

- (void)setClientVersion:(UInt32)clientVersion;
- (void)setShortLinkDebugIP:(NSString *)IP port:(const unsigned short)port;
- (void)setShortLinkPort:(const unsigned short)port;
- (void)setLongLinkAddress:(NSString *)address port:(const unsigned short)port debugIP:(NSString *)IP;
- (void)setLongLinkAddress:(NSString *)address port:(const unsigned short)port;
- (void)setLongLinkAddress:(NSString *)address ports:(NSArray<NSNumber *> *)portList;
- (void)setLongLinkBackupIps:(NSArray<NSString *> *)ipList;
- (void)setAccountInfoWithUin:(long)uin userNmae:(NSString *)userName;
- (void)makesureLongLinkConnect;
- (void)destroyMars;

- (void)addPushObserver:(id<YMFPushNotifyDelegate>)observer withCmdId:(int)cmdId;
- (void)setFlowCallback:(id<YMFlowDelegate>)callback;
- (int)startTask:(YMFlowTask *)task forTaskNotify:(id<YMFTaskNotifyDelegate>)taskNotifyDelegate;
- (void)stopTask:(int)taskID;
- (void)clearTasks;

// event reporting
- (void)reportEventAPPOnForeground:(BOOL)isForeground;
- (void)reportEvent_OnNetworkChange;

// callbacks

+ (BOOL)isAuthed;
+ (NSArray *)onNewDns:(NSString *)host;
+ (void)onPushWithCmd:(NSInteger)cid data:(NSData *)data;
+ (NSData *)request2BufferWithTaskID:(uint32_t)tid userContext:(const void *)context;
+ (int)buffer2ResponseWithTaskID:(uint32_t)tid ResponseData:(NSData *)data userContext:(const void *)context;
+ (int)onTaskEndWithTaskID:(uint32_t)tid userContext:(const void *)context errType:(uint32_t)errtype errCode:(uint32_t)errcode;
+ (void)onConnectionStatusChange:(int32_t)status longConnStatus:(int32_t)longConnStatus;
+ (void)onLongLinkStatusChange:(int)status;
+ (int)getLonglinkIdentifyCheckBuffer:(NSData *)buffer bufferHash:(NSData *)hash cmdid:(int *)cmdid;
+ (bool)onLonglinkIdentifyResponse:(NSData *)response identifyBufferHash:(NSData *)hash;
+ (void)onLongLinkNetworkError:(int)errType errCode:(int)errCode ip:(NSString *)ip port:(int)port;
+ (void)onLongLinkIPPortReport:(NSString *)ip port:(int)port;

+ (YMFAccountInfo *)accountInfo;
+ (YMFDeviceInfo *)deviceInfo;

@end

#endif /* NetworkService_hpp */
