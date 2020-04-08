//
//  BaseClassRoomViewController.h
//  AFNetworking
//
//  Created by yimi on 2019/10/16.
//

#import <UIKit/UIKit.h>
#import "YMClassRoomProtocol.h"
#import "YMTCoursewareControlCenter.h"
#import "YMRoomModel.h"
#import <YMTCloudClassroom/YMTChatModule.h>
#import "YMTSideButtonbar.h"
#import "YMTTopBar.h"
#import <YMTCloudClassroom/YMTIMModule.h>
#import "YMCourseWindowView.h"
#import "YMCursorView.h"
#import "YMBaseControlCenter.h"
#import "YMBoardWindowManager.h"
#import "YMCloudClassroomDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@class YMUserAuthManager;


@interface YMBaseClassRoomViewController : UIViewController <YMClassRoomProtocol, YMClassRoomLifeCycleDelegate, YMClassRoomLifeCycleProtocol,YMTTopBarDelegate>
@property (strong, nonatomic) YMRoomModel *roomModel;
@property (nonatomic, strong) YMTChatModule *chatModule;
@property (nonatomic, strong) YMTSideButtonbar *sideButtonbar;
@property (nonatomic, strong) YMTTopBar *topBar;
@property (nonatomic, strong) UIView *blackBoardView;
@property (nonatomic, strong) YMCourseWindowView *avCourseWareWindow;
@property (nonatomic, strong) YMBoardWindowManager *boardWindowManager;

/// 控制中心
@property (nonatomic, strong) YMBaseControlCenter *controlCenter;
/// 音视频课件播放控制器
@property (nonatomic, strong) YMMediaPlayerControllerCenter *mediaPlayControlCenter;

@property (nonatomic, assign) CGFloat kWidth;
@property (nonatomic, assign) CGFloat kHeight;

@property (nonatomic, assign) YMRoomMode roomMode;
@property (nonatomic, assign) YMClassRoomType roomType;

//课程状态
@property (nonatomic, assign, readonly) NSUInteger supportAbilityModules;
@property (nonatomic, assign, readonly) NSUInteger supportUIModules;

@property (nonatomic, strong)NSMutableDictionary *courseWareTypeDic;

@property (nonatomic ,strong) YMCursorView * cursorView;

@property (nonatomic, strong, nullable) YMClassRoomConfiguration *roomConfiguration;

- (void)setDelegate:(id<YMTCloudClassroomDelegate>)delegate;

- (void)setUpSideButtonBar;

- (void)setUpVideoView;

- (void)setupTopBar;

- (void)setUpCourseWareView;

- (void)setUpBlackBoardView;

- (void)setUpAVCourseWareView;

- (void)showAVCourseWareView:(YMAVControl *)avCourseWare;

- (void)setUpChatView;

- (void)showChatView;

- (void)hideChatView;

- (void)setUpCursorView;

- (void)processCommand:(YMTSCSendMsgEntity *)context isRealTime:(BOOL)isRealTime;

- (void)sideBarButtonDidClicked:(UIButton *)sender type:(YMTSideButtonType)buttonType;

- (void)setRecordParams:(NSString *)title trailPath:(NSURL *)trailPath  voicePath:(NSArray *)voicePath voiceTime:(NSInteger )voiceTime;

@end

NS_ASSUME_NONNULL_END
