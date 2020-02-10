//
//  YMClassRoomLifeCycle.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/11/3.
//

#import <Foundation/Foundation.h>
#import "YMClassRoomLifeCycleProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMClassRoomLifeCycle : NSObject <YMClassRoomLifeCycleProtocol>

- (void)addLifeCycleObserver:(id<YMClassRoomLifeCycleDelegate>)delegate;

- (void)removeLifeCycleObserver:(id<YMClassRoomLifeCycleDelegate>)delegate;

- (BOOL)isRoomStarted;

- (BOOL)isRoomPaused;

- (BOOL)isRoomStoped;

- (BOOL)isCommandSyncFinished;

- (void)setClassStartedFlag:(BOOL)isStarted;

- (BOOL)getClassStartedFlag;

- (void)finishCommandSync;

@end

NS_ASSUME_NONNULL_END
