//
//  YMBaseControlCenter.h
//  AFNetworking
//
//  Created by yimi on 2019/10/16.
//

#import <Foundation/Foundation.h>
#import "YMIMControlCenter.h"
#import "YMRoomModel.h"
#import "YMTCoursewareControlCenter.h"
#import "YMTAudioVideoControlCenter.h"
#import "YMMediaPlayerControllerCenter.h"
#import "YMWhiteBoardManager.h"
#import "YMClassRoomLifeCycle.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YMClassRoomControlCenterDelegate <NSObject>

@required
- (void)onClassRoomExit;

- (void)onClassRoomEnter;

- (void)onClassRoomCommandReceived:(YMTSCSendMsgEntity *)commandEntity isRealTime:(BOOL)isRealTime;

- (void)onClassRoomDisconnect;

@optional
- (void)onClassAuthChange:(NSString *)uid cameraEnable:(BOOL)cameraEnable micEnable:(BOOL)micEnable drawEnable:(BOOL)drawEnable;

@optional
- (void)onClassShowCourseware:(NSString *)docId docName:(NSString *)docName;

@end

@interface YMBaseControlCenter : NSObject

@property (nonatomic, strong) YMRoomModel *roomModel;

/// 白板和课件控制器
@property (nonatomic, strong) YMTCoursewareControlCenter *boardControlCenter;

@property (nonatomic, strong) YMWhiteBoardManager *boardManager;

/// 音视频控制器
@property (nonatomic, strong) YMTAudioVideoControlCenter *audioVideoControlCenter;


/// 权限控制模块
@property (nonatomic, strong) YMUserAuthManager *userAuthManager;

@property (nonatomic, strong) YMClassRoomLifeCycle *roomLifeCycle;

@property (nonatomic, assign) YMClassRoomType roomType;


- (void)enterRoom;

- (void)exitRoom;

- (void)sendCommand:(NSDictionary *)commandContent withCommandType:(YMTSCCommandConvertType)type;

- (void)destroy;

- (void)enableIMModule;

- (void)enableLiveModule;

- (void)setClassRoomControlCenterDelegate:(id<YMClassRoomControlCenterDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
