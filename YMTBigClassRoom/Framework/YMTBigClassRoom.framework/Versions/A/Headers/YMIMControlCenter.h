//
//  YMIMControlCenter.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/11/19.
//

#import <Foundation/Foundation.h>
#import "YMTIMModule.h"
#import "YMIMControlCenterProtocol.h"

NS_ASSUME_NONNULL_BEGIN
@class YMIMControlCenter;

@protocol YMIMControlCenterDelegate <NSObject>

@optional
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onEnterRoom:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onExitRoom:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onDisconnect:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onConnectFail:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onCommandReceived:(YMTSCSendMsgEntity *)commandEntity isRealTime:(BOOL)isRealTime;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onAsyncHistoryData:(BOOL)isSuccess withUid:(NSString *)uid;


@end

@interface YMIMControlCenter : NSObject <YMIMControlCenterProtocol>

/// 初始化IM模块
- (void)initIMControlCenter:(NSArray *)dnsIPList withTcpPort:(NSString *)tcpPort withHttpPort:(NSString *)httpPort liveRoomID:(NSString *)liveRoomID uid:(NSString *)uid roleType:(NSInteger )roleType relatedUserId:(NSString *)relatedUserId userIdentity:(NSString *)userIdentity userName:(NSString *)name bussinessType:(NSInteger)bType groupId:(NSInteger)gId;

/// 销毁IM模块
- (void)destroy;

/// 发送消息至server
- (void)sendCommand:(NSDictionary *)commandContent commandType:(YMTSCCommandConvertType)type;

/// 退出教室
- (void)exitRoom;

- (void)setDelegate:(id<YMIMControlCenterDelegate>)delegate;


/// 获取当前连接的服务器IP
- (NSString *)getCurrentIp;

@end

NS_ASSUME_NONNULL_END
