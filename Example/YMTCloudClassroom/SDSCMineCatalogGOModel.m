//
//  SDSCMineCatalogGOModel.m
//  student
//
//  Created by 顾鹏凌 on 2018/9/12.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import "SDSCMineCatalogGOModel.h"
//#import "HSRosterCell.h"

/**
 配置对对应的 type 和 key

 @return 所有字典
 */
static NSMutableDictionary <NSString * ,SCCloudDiskFileDetailModel *> * SCCommandTypeAndNameDictionary() {
    static NSMutableDictionary *_allDocFileDictionary;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _allDocFileDictionary = [NSMutableDictionary dictionary];
    });

    return _allDocFileDictionary;
}

//小班课根据课件id查询课件接口
@implementation SCCloudDiskFileDetailModel

/**
 将课件数据插入到字典中

 @param model 课件数据
 @param key 课件ID
 */
+ (void)insetModelToDicWithModel:(SCCloudDiskFileDetailModel *)model key:(NSString *)key {
    NSMutableDictionary *fileDic = SCCommandTypeAndNameDictionary();
    if (![[fileDic allKeys] containsObject:key]) {
        [fileDic setObject:model forKey:key];
    }
}

/**
 从字典中获取对应的课件数据

 @param key 课件ID
 @return 课件数据
 */
+ (SCCloudDiskFileDetailModel *)readModelFromDicWithKey:(NSString *)key {
    NSMutableDictionary *fileDic = SCCommandTypeAndNameDictionary();
    return [fileDic objectForKey:key];
}

//

- (instancetype)init {
    self = [super init];
    if (self) {
        _seekTime = 0.f;
        _avOperation = AVCourseWareOperation_None;
    }
    return self;
}
@end

//进入教室配置信息获取
@implementation SCAgoraDomainModel

//
@end

@implementation SCAgoraIpListModel
+ (NSDictionary *)mj_replacedKeyFromPropertyName {
    return @{@"ID": @"id"};//预览讲义用
}
//
@end

@implementation SCAgoraRoomAgoraAuthModel


@end

@implementation SCAgoraRoomUserModel



- (void)refreshAuthWithConfig:(NSDictionary *)config {
    NSAssert([[config objectForKey:@"uid"] isEqualToString:self.userId], @"refreshAuth Error, uid is not equal to self");

    if ([config objectForKey:@"up"]) {
        NSInteger updown = [[config objectForKey:@"up"] integerValue];
        updown == 0 ? [self.userAuth releaseAuth:UserAuth_Updown] : [self.userAuth appendAuth:UserAuth_Updown];
    }

    if ([config objectForKey:@"trail"]) {
        NSInteger trail = [[config objectForKey:@"trail"] integerValue];
        trail == 0 ? [self.userAuth releaseAuth:UserAuth_Trail] : [self.userAuth appendAuth:UserAuth_Trail];
        trail == 0 ? [self.userAuth releaseAuth:UserAuth_Erase] : [self.userAuth appendAuth:UserAuth_Erase];
    }

    if ([config objectForKey:@"audio"]) {
        NSInteger audio = [[config objectForKey:@"audio"] integerValue];
        audio == 0 ? [self.userAuth releaseAuth:UserAuth_Audio] : [self.userAuth appendAuth:UserAuth_Audio];
    }

    if ([config objectForKey:@"video"]) {
        NSInteger video = [[config objectForKey:@"video"] integerValue];
        video == 0 ? [self.userAuth releaseAuth:UserAuth_Video] : [self.userAuth appendAuth:UserAuth_Video];
    }
}

- (BOOL)muteEnable {
    return (self.userAuth.auth&UserAuth_Updown) > 0 && (self.userAuth.auth&UserAuth_Audio) > 0;
}

- (BOOL)videoEnable {
    return (self.userAuth.auth&UserAuth_Updown) > 0 && (self.userAuth.auth&UserAuth_Video) > 0;
}

- (void)setMuteEnabel:(BOOL)mute {
    mute ? [self.userAuth releaseAuth:UserAuth_Audio] : [self.userAuth appendAuth:UserAuth_Audio];
}

- (HSUserAuth *)userAuth {
    if (_userAuth == nil) {
        _userAuth = [HSUserAuth emptyAuth];
        [_userAuth appendAuth:UserAuth_Updown];
        [_userAuth appendAuth:UserAuth_Audio];
        [_userAuth appendAuth:UserAuth_Video];
    }
    return _userAuth;
}

- (NSDictionary *)rosterStateDictionary {
    NSMutableDictionary *dic = [NSMutableDictionary dictionaryWithCapacity:5];

    SDSCRosterViewState updown = (self.userAuth.auth&UserAuth_Updown)?SDSCRosterViewState_On:SDSCRosterViewState_Off;
    updown = _isOnline ? updown : SDSCRosterViewState_Unkonw;

    SDSCRosterViewState auth = (self.userAuth.auth&UserAuth_Trail)?SDSCRosterViewState_On:SDSCRosterViewState_Off;
    auth = _isOnline ? auth : SDSCRosterViewState_Unkonw;

    SDSCRosterViewState video = (self.userAuth.auth&UserAuth_Video)?SDSCRosterViewState_On:SDSCRosterViewState_Off;
    video = _isOnline ? video : SDSCRosterViewState_Unkonw;

    SDSCRosterViewState audio = [self muteEnable] ? SDSCRosterViewState_On : SDSCRosterViewState_Off;
    audio = _isOnline ? audio : SDSCRosterViewState_Unkonw;

    [dic setObject:@(updown) forKey:kSDSCRosterViewUpdownKey];
    [dic setObject:@(auth) forKey:kSDSCRosterViewAuthKey];
    [dic setObject:@(audio) forKey:kSDSCRosterViewAudioKey];
    [dic setObject:@(video) forKey:kSDSCRosterViewVideoKey];
    [dic setObject:self.userName forKey:kSDSCRosterViewNameKey];
    [dic setObject:@(_medalNumber) forKey:kSDSCRosterViewMedalKey];

    return [dic copy];
}

- (NSDictionary *)topviewStateDictionary {
    SDSCUserMicState micState = [self muteEnable] ? SDSCUserMicState_Authon : SDSCUserMicState_Authoff;
    SDSCUserCameraState cameraState = [self videoEnable] ? SDSCUserCameraState_Joined : SDSCUserCameraState_Authoff;
    // 新增用户自己摄像头权限被禁止，自己仍然可以看到自己的本地视频
    cameraState = self.isCurrentRoomUser ? SDSCUserCameraState_Joined : cameraState;
    if (!self.isCurrentRoomUser) {// 非当前用户被下台 自主退出登录后重新进入 摄像头被禁止时语音也应该被禁止
        SDSCRosterViewState audio = [self muteEnable] ? SDSCRosterViewState_On : SDSCRosterViewState_Off;
        if (audio == SDSCRosterViewState_On) {
            micState = SDSCUserMicState_Authon;
        } else {
            micState = SDSCUserMicState_Authoff;
        }
    }
    return @{kSDSCUserMicStatusKey:@(micState),kSDSCUserCameraStatusKey:@(cameraState),kSDSCUserNameKey:self.userName};
}

- (NSDictionary *)bottomviewStateDictionary {
   return @{kBottonToolBarPenButtonKey:@(self.userAuth.auth&UserAuth_Trail),
      kBottomToolBarEraseButtonKey:@(self.userAuth.auth&UserAuth_Erase)
      };
}


@end

@implementation HSSCSocketUserModel


@end
//v1.0 进入教室
@implementation SDSCMineGoAgoraRoomModel
+ (NSDictionary *)mj_objectClassInArray{

    return @{@"students":@"SCAgoraRoomUserModel"};
}



- (SCAgoraRoomUserModel *)obtainUserFromUserId:(NSString *)userId {
    if (!userId) {
        return nil;
    }

    if ([_teacher.userId isEqualToString:userId]) {
        return _teacher;
    }

    for (SCAgoraRoomUserModel *user in self.students) {
        user.isCurrentRoomUser = [user.userId isEqualToString:self.currentUserId];
        if (![user.userId isEqualToString:userId]) continue;
        return user;
    }

    return nil;
}

- (SCAgoraRoomUserModel *)obtainUserFromUid:(NSString *)uid {
    if (!uid) {
        return nil;
    }

    if ([_teacher.uid isEqualToString:uid]) {
        return _teacher;
    }

    for (SCAgoraRoomUserModel *user in self.students) {
        user.isCurrentRoomUser = [user.uid isEqualToString:self.currentUid];
        if (![user.uid isEqualToString:uid]) continue;
        return user;
    }

    return nil;
}

- (void)muteAllToStudent:(BOOL)mute {
    for (SCAgoraRoomUserModel *user in self.students) {
        [user setMuteEnabel:mute];
    }
}

- (NSArray<NSString *> *)randomRollResources {
    NSMutableArray *resources = [NSMutableArray arrayWithCapacity:self.students.count];
    for (SCAgoraRoomUserModel *student in self.students) {
        if (!student.isOnline) continue ;
        [resources addObject:student.userName];
    }

    return [resources copy];
}

@end

@implementation SDSCMineCatalogGOModel
//+ (NSDictionary *)mj_replacedKeyFromPropertyName {
//    return @{@"fileName": @"name",
//             @"fileType":@"docType"};//预览讲义用
//}
+ (NSDictionary *)mj_objectClassInArray{
    
    return @{@"liveRoom":@"SDSCMineLiveRoomModel"};
}


@end

@implementation SDSCMineLiveRoomModel

@end

