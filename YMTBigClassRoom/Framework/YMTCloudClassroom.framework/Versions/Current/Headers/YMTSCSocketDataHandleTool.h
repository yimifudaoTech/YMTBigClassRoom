//
//  GPLSCSocketDataHandleTool.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/11/21.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTSCEntityDatas.h"

@class YMTSCSocketDataHandleTool;

@protocol GPLSCSocketDataHandleDelegate <NSObject>


@required

/**
 接收解析数据

 @param handleTool 工具类
 @param context 解析后的数据
 */
- (void)scsocketDataHandle:(YMTSCSocketDataHandleTool *)handleTool parseContext:(YMTSCSendMsgEntity *)context;


@optional

/**
 发送加密数据

 @param handleTool 工具类
 @param context 加密数据
 */
- (void)scsocketDataHandle:(YMTSCSocketDataHandleTool *)handleTool sendContext:(YMTSCSendMsgEntity *)context;

@end

@interface YMTSCSocketDataHandleTool : NSObject
@property (nonatomic, weak) id <GPLSCSocketDataHandleDelegate> delegate;

- (instancetype)initWithHandle:(id<GPLSCSocketDataHandleDelegate>)handle;

/**
 发送数据

 @param context 需要发送的数据
 */
- (void)scsocketSendContext:(YMTSCSendMsgEntity *)context;

/**
 解析数据

 @param context 需要解析的数据
 */
- (void)scsockerParseContext:(YMTSCSendMsgEntity *)context;
@end
