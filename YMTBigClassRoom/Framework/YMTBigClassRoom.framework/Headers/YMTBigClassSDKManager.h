//
//  YMTClassInfoFetchTool.h
//  AFNetworking
//
//  Created by SendomZhang on 10/9/2019.
//

#import <Foundation/Foundation.h>
#import "YMEnum.h"
@class YMSDKUserInfo;

typedef void(^YMTBigClassRoomRegisterResult)(BOOL success, YMTRoomInfoCode code);

typedef void(^YMTBigClassRoomLoginRoomResult)(BOOL success, YMTRoomInfoCode code,NSString * _Nullable token);

typedef void(^YMTBigClassRoomJoinRoomResult)(BOOL success, YMTRoomInfoCode code, UIViewController * _Nullable vc);

typedef void(^YMTBigClassRoomLevelRoomResult)(BOOL success, YMTRoomInfoCode code);

typedef void(^YMTRequestCallBackResult)(BOOL success, YMTRoomInfoCode code, NSString * _Nullable errorMessage);

/*
 * 云教室交互流程
 * sequenceDiagram
 * (巨人)APP->>(溢米)云教室: registerSDK()
 * (溢米)云教室->>(巨人)APP: 返回初始化结果
 * (巨人)APP->>(溢米)云教室: 登录（appID、sercet、房间ID）
 * (溢米)云教室->>(溢米)API: 获取教室通行token
 * (溢米)API->>(溢米)云教室: 返回溢米教室通行token
 * (溢米)云教室->>(巨人)APP: 回调结果返回 APP
 * (巨人)APP->>(溢米)云教室: joinCloudRoom()进入教室（appID、溢米token、房间ID）
 * (溢米)云教室->>(巨人)APP:返回结果
 * (巨人)APP->>(溢米)云教室:leaveCloudRoom()退出房间
 * (溢米)云教室-->>(溢米)API:退出房间
 * (溢米)云教室->>(巨人)APP:返回退出结果
 * (巨人)APP->>(溢米)云教室:recordPlay()播放录播
 * (溢米)云教室-->>(溢米)API:下载录播信息
 * (溢米)云教室->>(巨人)APP:返回结果
 */

NS_ASSUME_NONNULL_BEGIN

@interface YMTBigClassSDKManager : NSObject

/**
 设置YMTBigClassSDKManager环境
 */
@property (nonatomic, assign) YMTRoomEnvironment switchEnv;

+ (instancetype)shareManager;


/**
 开启崩溃收集，默认开启，在进教室前调用

 @param enable YES 开启， NO 关闭
 */
- (void)enableCrashReport:(BOOL)enable;

/**
 初始化sdk

 @param appID 业务后台分配
 @param appKey 业务后台分配
 @param result 结果回调
 */
- (void)registerSDKWithAppID:(NSString *)appID AppKey:(NSString *)appKey result:(YMTBigClassRoomRegisterResult)result;

/**
 登录
 
 @param userID 用户ID
 @param result 结果回调
 */
- (void)loginWithUserID:(NSString *)userID result:(YMTBigClassRoomLoginRoomResult)result;

/**
 加入教室,如果成功自动开发房间
 @param userInfo  教室内用户信息模型
 @param result    onJoinCloudRoom 回调
 */
- (void)joinCloudRoom:(YMSDKUserInfo *)userInfo
                      appViewController:(UIViewController *)parentView
                                 result:(YMTBigClassRoomJoinRoomResult)result ;

/**
 退出教室

 @param result leaveCloudRoom 回调
 */
- (void)leaveCloudRoom:(YMTBigClassRoomLevelRoomResult)result;

/**
 房间销毁,释放和教室相关的信息
 */
- (void)destroy;

/**
 录播回放

 @param viewParent   传递视图展示层
 @param roomId       房间Id
 @param token        用户token
 @param userid       用户Id
 */
- (void)recordPlay:(UIViewController *)viewParent roomID:(NSString *)roomId token:(NSString *)token userid:(NSString *)userid;

/**
 清除用户缓存文件，包括录播缓存文件

 @param userid 用户Id
 */
- (BOOL)clearCache:(NSString *)userid;

/**
 查看课件
 
 @param  parentVC    视图
 @param  roomId      房间ID
 @param  token       用户token
 @param  userId      用户ID
 @param  result      查看课件回调
 */
- (void)courseWare:(UIViewController *)parentVC roomId:(NSString *)roomId token:(NSString *)token userId:(NSString *)userId result:(YMTRequestCallBackResult)result;

@end

@interface YMSDKUserInfo : NSObject

// roomID  房间ID     必填项
@property (nonatomic, strong) NSString *roomID;
// token   用户token  必填项
@property (nonatomic, strong) NSString *token;
// userID  用户ID     必填项
@property (nonatomic, strong) NSString *userID;
// groupId 用户分组ID  必填项
@property (nonatomic, strong) NSString *groupId;
// headUrl 用户头像    必填项
@property (nonatomic, strong) NSString *headUrl;
// role    用户角色    必填项
@property (nonatomic, assign) YMRoleType role;
// identity 用户身份    选填项
@property (nonatomic, strong) NSString *identity;
// nickName 用户昵称或者名字    必填项
@property (nonatomic, strong) NSString *nickName;
// bussinessData 自定义业务json数据    选填项
@property (nonatomic, strong) NSString *bussinessData;
// relatedUserId 家长旁听原学生uid    选填项
@property (nonatomic, strong) NSString *relatedUserId;
// userIdentity 家长uid    选填项
@property (nonatomic, strong) NSString *userIdentity;

@end

NS_ASSUME_NONNULL_END
