//
//  YMLiveViewConfig.h
//  YiMiApp
//
//  Created by mystarains on 2019/8/8.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMLiveViewConfig_h
#define YMLiveViewConfig_h

typedef NS_ENUM(NSUInteger, YMLiveRoleType) {
    YMLiveRoleType_Stu = 5,
    YMLiveRoleType_Tea = 10
};

typedef NS_ENUM(NSUInteger, YMLiveUserMicState) {
    YMLiveUserMicState_AuthOn = 3, // 打开
    YMLiveUserMicState_AuthOff = 6, // 关闭
    YMLiveUserMicState_Invalid = 9 // 无效，一般是设备原因
};

typedef NS_ENUM(NSUInteger, YMLiveUserCameraState) {
    YMLiveUserCameraState_Invalid = 4,  // 未进入
    YMLiveUserCameraState_Loading = 8,  // 等待视频
    YMLiveUserCameraState_Joined  = 12, // 加入完成
    YMLiveUserCameraState_AuthOff = 16  // 禁止授权
};

static NSString *const kYMLiveUserRoleKey         = @"kSDSCuserRoleKey";
static NSString *const kYMLiveUserMicVolumeKey    = @"kSDSCUserMicVolumeKey";
static NSString *const kYMLiveUserMicStatusKey    = @"kSDSCUserMicStatusKey";
static NSString *const kYMLiveUserNameKey         = @"kSDSCUserNameKey";
static NSString *const kYMLiveUserCameraStatusKey = @"kSDSCUserCameraStatusKey";

#endif /* YMLiveViewConfig_h */
