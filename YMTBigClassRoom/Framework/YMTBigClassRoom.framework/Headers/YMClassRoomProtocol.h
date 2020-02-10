//
//  YMClassRoomProtocol.h
//  Pods
//
//  Created by yimi on 2019/10/16.
//

#ifndef YMClassRoomProtocol_h
#define YMClassRoomProtocol_h

typedef NS_ENUM(NSInteger, YMRoomMode) {
    YMRoomMode_LiveRoom,
    YMBoardType_RecordPlay
};

typedef NS_ENUM(NSInteger, YMRoomAbilityModule) {
    YMRoomAbilityModule_IM = 1,
    YMRoomAbilityModule_Chat = 1 << 1,
    YMRoomAbilityModule_Live = 1 << 2,
    YMRoomAbilityModule_BlackBoard = 1 << 3,
    YMRoomAbilityModule_CourseWare = 1 << 4,
    YMRoomAbilityModule_RecordPlay = 1 << 5
};

typedef NS_ENUM(NSInteger, YMRoomUIModule) {
    YMRoomUIModule_TopBar = 1,
    YMRoomUIModule_SideBar = 1 << 1,
    YMRoomUIModule_ToolBar = 1 << 2,
    YMRoomUIModule_LiveVideoArea = 1 << 3,
    YMRoomUIModule_CourseWareWindow = 1 << 4,
    YMRoomUIModule_BlackBoard = 1 << 5
};

@protocol YMClassRoomProtocol <NSObject>


- (void)setRoomMode:(YMRoomMode)mode;

- (void)setRoomConfig:(NSUInteger)supportAbilityModules withUIModules:(NSUInteger)supportUIModules;

- (void)openRoom:(UIViewController *)parentView;

- (void)setVideoInitPosition:(CGSize)position;

- (void)setRoomViewPosition:(CGSize)position;

- (void)enableWhiteBoard:(BOOL)enable;

- (void)enableCourseWare:(BOOL)enable;

- (void)enableAudio:(BOOL)enable;

- (void)enableVideo:(BOOL)enable;

- (void)exit;

- (void)getRoomView;

@end


#endif /* YMClassRoomProtocol_h */
