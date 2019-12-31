//
//  YMIMControlCenter.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/11/19.
//

#import <Foundation/Foundation.h>
#import "YMTIMModule.h"

NS_ASSUME_NONNULL_BEGIN
@class YMIMControlCenter;

@protocol YMIMControlCenterDelegate <NSObject>

@optional
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onEnterRoom:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onExitRoom:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onDisconnect:(nullable NSString *)uid;
- (void)imControlCenter:(YMIMControlCenter *)centerCenter onCommandReceived:(YMTSCSendMsgEntity *)commandEntity isRealTime:(BOOL)isRealTime;


@end

@interface YMIMControlCenter : NSObject

/// 初始化IM模块
- (void)initIMControlCenter:(NSArray *)dnsIPList withTcpPort:(NSString *)tcpPort withHttpPort:(NSString *)httpPort liveRoomID:(NSString *)liveRoomID uid:(NSString *)uid userName:(NSString *)name bussinessType:(NSInteger)bType groupId:(NSInteger)gId;

/// 销毁IM模块
- (void)destroy;

/// 发送消息至server
- (void)sendCommand:(NSDictionary *)commandContent commandType:(YMTSCCommandConvertType)type;

/// 退出教室
- (void)exitRoom;

- (void)setDelegate:(id<YMIMControlCenterDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
