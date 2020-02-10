//
//  YMUserAuthManager.h
//  AFNetworking
//
//  Created by yimi on 2019/10/29.
//

#import <Foundation/Foundation.h>
#import "YMAuthCommand.h"
#import "YMUserAuth.h"
#import "YMRoomModel.h"
#import "YMTBigClassSDKManager.h"


typedef void(^YMUserAuthChangeBlock)(NSString *uid);

@interface YMUserAuthManager : NSObject

- (void)setAuthChangeBlock:(YMUserAuthChangeBlock)callback;

/*
 设置课程类型
 不同的课程类型，不同角色的权限不同
 */
- (void)setClassType:(YMClassRoomType )classType;

/*
 增加用户
 需要对uid做处理，可以采用和音视频通道相同的uid处理方式
*/
- (void)addUser:(NSString *)userId  withUserRole:(YMRoleType )userRole;

/*
 设置权限状态
 在获取老师授权，取消授权或暂停授权时调用
*/
- (void)setAuthStatus:(NSString *)userId withAuthName:(YMAuthName )authName withAuthStatus:(YMAuthStatus )status;

/*
 权限功能是否被授权
 在使用某个功能前先判断是否有权限
*/
- (BOOL)isAuthed:(NSString *)userId withAuthName:(YMAuthName)authName;

/*
 重置用户中断中的权限
*/
- (void)recoveryAuth:(NSString *)userId withAuthName:(YMAuthName)authName;

/*
 用户是否被设置权限
 用于用户进入教室还未添加的判断
*/
- (BOOL)isUserAuthSaved:(NSString *)uid;

/*
 用户权限刷新
*/
- (void)refreshUserAuthWithUid:(NSString *)uid;

/*
 清除用户权限
*/
- (void)clearAuth:(NSString *)uid;

/*
 清除所有用户权限
*/
- (void)clearAllAuth;

@end
