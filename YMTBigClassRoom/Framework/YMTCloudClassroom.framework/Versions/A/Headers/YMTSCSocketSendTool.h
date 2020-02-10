//
//  GPLSCSocketSendTool.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/11/20.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTSCEntityDatas.h"

@class YMTSCSocketSendTool;

typedef void (^GPLSCSocketDataCallBack)(BOOL isFinished, id tool, YMTSCSendMsgEntity *data);

typedef void (^GPLSCSocketSendDataCallBack)(id tool, YMTSCSendMsgEntity *data);

@interface YMTSCSocketSendTool : NSObject

@property(nonatomic, assign, readonly) NSUInteger tag;
@property(nonatomic, assign, readonly) NSInteger nowTag; //当前tag编号
@property(nonatomic, assign, readonly) BOOL isSending;
@property(nonatomic, assign, readonly) BOOL hasLocalData;

- (void)addSocketSendCallBack:(GPLSCSocketDataCallBack)callBack realSendCallBack:(GPLSCSocketSendDataCallBack)realSendCallBack;
/**
 重置方法
 */
- (void)resetAllData;

/**
 插入消息到发送队列里

 @param context 消息文本
 */
- (void)insertSendMsgToCacheWithContext:(YMTSCSendMsgEntity *)context;

/**
 根据消息类型删除对应消息

 @param type 消息类型
 */
- (void)removeSendMsgFromCacheWithType:(YMTSCCommandConvertType)type;

/**
 删除对应消息编号

 @param tag tag标示
 */
- (void)removeSendMsgFromCacheWithTag:(NSInteger)tag;

/**
 发送本地消息
 */
- (void)sendLocalContext;

/**
 重置本地tag标识

 @param tag 发送的sn
 */
- (void)resetLocalTagFromServer:(NSUInteger)tag;
@end
