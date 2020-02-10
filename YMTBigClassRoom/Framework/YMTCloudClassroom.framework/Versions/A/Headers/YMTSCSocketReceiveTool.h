//
//  GPLSCSocketReceiveTool.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/11/20.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTSCSocketSendTool.h"

#define SC_SOCKET_LOCAL(xxxx) [NSString stringWithFormat:@"SC_SocketLocal_%@",xxxx]

@interface YMTSCSocketReceiveTool : NSObject
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, assign, readonly) NSInteger mn;
@property (nonatomic, assign, readonly) BOOL isFirstSync;//是否第一次同步
- (void)addSocketReceiveDataFromLessonId:(NSString *)lessonId callBack:(GPLSCSocketDataCallBack)callBack;

/**
 重置数据
 */
- (void)reserAllData;

/**
 插入缓存一堆数据

 @param contexts 数据数组
 */
- (void)insertCacheWithContexts:(NSArray *)contexts;

/**
 插入一条数据

 @param context 某条数据
 */
- (void)insertCacheWithContext:(NSData *)context isRealTime:(BOOL)isRealTime;

/**
 开始解析本地数据
 */
- (void)startReadCacheContextNeedFinish:(BOOL)needFinish;

@end
