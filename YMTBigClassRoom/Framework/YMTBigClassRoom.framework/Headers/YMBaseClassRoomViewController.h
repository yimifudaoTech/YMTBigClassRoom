//
//  BaseClassRoomViewController.h
//  AFNetworking
//
//  Created by yimi on 2019/10/16.
//

#import <UIKit/UIKit.h>
#import "YMClassRoomProtocol.h"
#import "YMTClassRoomControlCenter.h"
#import "SDSCMineCatalogGOModel.h"
#import <YMTCloudClassroom/YMTChatModule.h>
#import <YMTCloudClassroom/YMTSideButtonbar.h>
#import <YMTCloudClassroom/YMTTopBar.h>
#import <YMTCloudClassroom/YMTIMModule.h>
#import "YMTAudioVideoControlCenter.h"
#import "YMMediaPlayerControllerCenter.h"
#import "YMCourseWindowView.h"
#import "YMCursorView.h"
#import "YMClassRoomLifeCycle.h"

NS_ASSUME_NONNULL_BEGIN

@class YMUserAuthManager;

static NSString * const YimiFudaoNewVerdorKey = @"6bdd1aedee814f1fade7ef5e42578ff7";

@interface YMBaseClassRoomViewController : UIViewController <YMClassRoomProtocol, YMClassRoomLifeCycleDelegate, YMClassRoomLifeCycleProtocol>
@property (strong, nonatomic) SDSCMineGoAgoraRoomModel *roomModel;
@property (nonatomic, strong) YMTAudioVideoControlCenter *audioVideoControlCenter;
@property (nonatomic, strong) YMMediaPlayerControllerCenter *mediaPlayControlCenter;
@property (nonatomic, strong) YMTChatModule *chatModule;
@property (nonatomic, strong) YMTSideButtonbar *sideButtonbar;
@property (nonatomic, strong) YMTTopBar *topBar;
@property (nonatomic, strong) UIView *blackBoardView;
@property (nonatomic, strong) YMCourseWindowView *avCourseWareWindow;
/// 控制中心
@property (nonatomic, strong, readwrite) YMTClassRoomControlCenter *controlCenter;

@property (nonatomic, strong) YMUserAuthManager *userAuthManager;

@property (nonatomic, assign) CGFloat kWidth;
@property (nonatomic, assign) CGFloat kHeight;

@property (nonatomic, assign) YMRoomMode roomMode;
@property (nonatomic, assign) YMClassRoomType roomType;

//课程状态
@property (nonatomic, assign, readonly) NSUInteger supportAbilityModules;
@property (nonatomic, assign, readonly) NSUInteger supportUIModules;

@property (nonatomic, strong)NSMutableDictionary *courseWareTypeDic;

@property (nonatomic ,strong) YMCursorView * cursorView;

@property (nonatomic, strong) YMClassRoomLifeCycle *roomLifeCycle;

- (void)initUserAuthManager;

- (void)setUpSideButtonBar;

- (void)setUpVideoView;

- (void)setupTopBar;

- (void)setUpCourseWareView;

- (void)setUpBlackBoardView;

- (void)setUpAVCourseWareView;

- (void)showCourseWare:(NSString *)docId docName:(NSString *)docName;

- (void)showAVCourseWareView:(NSString * __nullable)courseWareName;

- (void)hideAVCourseWareView;

- (void)showChatView;

- (void)hideChatView;

- (void)setUpCursorView;

- (void)drawTrail:(NSString *)boardId withTrailModel:(YMDrawTrailModel *)model withUid:(NSString *)uid withDocId:(NSString *)docId;

- (void)processCommand:(YMTSCSendMsgEntity *)context isRealTime:(BOOL)isRealTime;

- (YMTAudioVideoControlCenter *)createAudioVideoControlCenter;

- (void)onUserEnter:(NSUInteger)uid;

- (void)sideBarButtonDidClicked:(UIButton *)sender type:(YMTSideButtonType)buttonType;

- (void)setRecordParams:(NSString *)title trailPath:(NSURL *)trailPath  voicePath:(NSArray *)voicePath voiceTime:(NSInteger )voiceTime;

- (void)setCursorWareCurrentPage:(NSInteger )currentNumber totalPage:(NSInteger )totalNumber;

@end

NS_ASSUME_NONNULL_END
