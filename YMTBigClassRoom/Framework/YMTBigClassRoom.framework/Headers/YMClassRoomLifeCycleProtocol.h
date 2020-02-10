//
//  YMClassRoomLifeCycleProtocol.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/11/3.
//

#ifndef YMClassRoomLifeCycleProtocol_h
#define YMClassRoomLifeCycleProtocol_h

typedef NS_ENUM(NSInteger, YMClassLifeCycleState) {
    YMClassLifeCycleState_Init,            //初始状态
    YMClassRoomLifeCycle_SyncCommands,  //开始指令同步
    YMClassRoomLifeCycle_SyncCommandsFinished,  //指令同步完成
    YMClassLifeCycleState_Wait,            //等待上课
    YMClassLifeCycleState_Stated,            //开始上课（上课中）
    YMClassLifeCycleState_Paused,       //课程中断（老师退出）
    YMClassLifeCycleState_Stoped,                //课程结束
};

@protocol YMClassRoomLifeCycleDelegate <NSObject>

@optional
- (void)classOnInit;

@optional
- (void)classOnSyncCommands;

@optional
- (void)classOnSyncCommandsFinish;

@optional
- (void)classOnWait;

@optional
- (void)classOnStart;

@optional
- (void)classOnResume;

@optional
- (void)classOnPaused;

@optional
- (void)classOnStop;
@end

@protocol YMClassRoomLifeCycleProtocol <NSObject>

- (void)startClass;

- (void)syncClassCommands;

- (void)resumeClass;

- (void)pauseClass;

- (void)stopClass;

@end

#endif /* YMClassRoomLifeCycleProtocol_h */
