//
//  YMPBProtocol.h
//  YMPingbackSDK
//
//  Created by yimi on 2019/5/28.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMPBProtocol_h
#define YMPBProtocol_h

#import "YMQOSToolMacros.h"

@protocol YMPBDataSource <NSObject>


@required

/**
 获取网络状态

 @return 网络状态，2g,3g,4g,5g,wifi等
 */
- (NSString *)getNetState;

@optional

/**
 实时获取用户信息

 @return 字典字段中，QOS_KEY_USERID @"userID"
 #define QOS_KEY_USERTYPE @"usertype"
 */
- (NSDictionary *)getUserInfo;

@end

@protocol YMPBProtocol <NSObject>


/**
sdk初始化，在AppDelegate中didFinishLaunchingWithOptions中调用，同时会更新sessonId

 @param company 公司名
 @param appType 取值为“yimi”
 @param url 数据投递api接口url
 @param dataSource 用来实时获取部分投递字段
 */
- (void)initSDK:(QOS_COMPANY) company appType:(NSString *)appType url:(NSString *)url dataSource:(id<YMPBDataSource>)dataSource;



/**
 设置用户信息，在登录或注册成功后设置,若需要实时获取用户信息，则需要实现YMPBDataSource的getUserInfo方法

 @param uid 用户ID
 @param userType 用户类型
 */
- (void)setUserInfo:(NSString *)uid userType:(QOS_USERTYPE)userType;


/**
 清除用户信息，在用户注销之后调用此方法
 */
- (void)clearUserInfo;


/**
 注册教室内事件列表

 @param eventIdList 教室内事件列表
 */
- (void)registerRoomEventList:(NSArray<NSString *> *)eventIdList;


/**
 注入教室事件基础信息，在进入教室，socket连上服务器后调用此方法

 @param roomInfo 教室内相关字段，字段名见YMQOSToolMacros_h，QOS_KEY_LESSONID，QOS_KEY_LESSONTYP，QOS_KEY_SERVERIP
 */
- (void)registerRoomEventParams:(NSDictionary *)roomInfo;


/**
 清除教室内基础信息，在退出教室后调用
 */
- (void)unregisterRoomEventParams;


/**
  发送投递事件

 @param eventId 事件ID
 @param logType 事件类型
 @param bussiness 业务类型，ymfdApp（溢米辅导app），yunClass_1（1对1云教室），yunClass_2（小组课云教室）
 @param extraInfo 额外信息
 */
- (void)sendEvent:(NSString *)eventId logType:(QOS_LOGTYPE)logType bussiness:(NSString *)bussiness extraInfo:(NSDictionary *)extraInfo;


/**
 释放SDK
 */
- (void)releaseSDK;

@end


#endif /* YMPBProtocol_h */
