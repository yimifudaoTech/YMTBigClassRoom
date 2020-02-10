//
//  YMLiveEnum.h
//  YiMiApp
//
//  Created by Caffrey on 2019/4/18.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMLiveEnum_h
#define YMLiveEnum_h

#import <Foundation/Foundation.h>

/**
 音视频渠道
 
 - YMLiveChannelNone: 空
 - YMLiveChannelAgora: 声网
 - YMLiveChannelNTES: 网易
 - YMLiveChannelTecentV1: 腾讯v1
 - YMLiveChannelTecentV2: 腾讯v2
 */
typedef NS_ENUM(NSUInteger, YMLiveChannel) {
    YMLiveChannelNone       = 0,
    YMLiveChannelAgora      = 1,
    YMLiveChannelNTES       = 2,
    YMLiveChannelTecentV1   = 3,
    YMLiveChannelTecentV2   = 4,
};

/**
 当前参与直播的用户类型
 
 - YMLiveUserTypeHost: 主播
 - YMLiveUserTypeGuest: 观众
 */
typedef NS_ENUM(NSUInteger, YMLiveUserType) {
    YMLiveUserTypeHost,
    YMLiveUserTypeGuest,
};

typedef NS_ENUM(NSInteger, YMLiveRoomType) {
    YMLiveRoomType1V1,
    YMLiveRoomType1VN
};

#endif /* YMLiveEnum_h */
