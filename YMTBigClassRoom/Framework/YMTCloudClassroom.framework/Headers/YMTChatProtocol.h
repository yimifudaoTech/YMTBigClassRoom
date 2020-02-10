//
//  YMTChatProtocol.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/6.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YMTChatInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YMTChatProtocol <NSObject>

@required
/**
 当前聊天窗口视图
 
 @return 获取当前聊天窗口视图
 */
- (UIView *)getChatView;

/**
 设置聊天室url
 
 @param chatUrl 聊天室url
 */
- (void)setChatUrl:(NSString *)chatUrl;

/**
 设置聊天数据
 
 @param chatInfo 聊天初始数据
 */
- (void)setChatInfoData:(YMTChatInfo *)chatInfo;

/**
 显示聊天视图
 */
- (void)show;

/**
 隐藏聊天视图
 */
- (void)hide;

/**
 设置是否能响应touch事件
 
 @param can 是否可以
 */
- (void)setCanTouch:(BOOL)can;

/**
 销毁
 */
- (void)destroy;


@end

NS_ASSUME_NONNULL_END
