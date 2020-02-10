//
//
//  QOSSdk
//
//  Created by YiMi on 2018/11/27.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface QOSSdk : NSObject

/**
 *QOS单例方法
 */
+ (instancetype)sharedDataTool;

/**
 *QOS埋点请求
 */
- (void)qosNetRequestMsgType:(NSString *)msgType withLoadUrl:(NSString *)url withData:(NSDictionary *)data withComplete:(void (^)(id requestData))completionBlock;

/**
 *QOS埋点请求(Protobuf 新方式)
 */
- (void)qosProtobufNetRequestMsgType:(NSString *)msgType withLoadUrl:(NSString *)url withData:(NSData *)data withComplete:(void (^)(id requestData))completionBlock;

/**
 *重启后投递
 */
- (void)saveQosRequestAndSendAfterReboot:(NSString *)msgType withLoadUrl:(NSString *)url withData:(NSDictionary *)data;

/**
 *获取ntp时间
 *formatted： YES-格式化   NO-未格式化
 */
- (NSString *)useQOSToGetNTPTimeIsFormatted:(BOOL)formatted;

/**
 *加载队列缓存
 */
- (void)startQOSCacheTaskWithLoadUrl:(NSString *)url;

/**
 *清除缓存
 */
- (void)removeQOSCacheTast;

@end

