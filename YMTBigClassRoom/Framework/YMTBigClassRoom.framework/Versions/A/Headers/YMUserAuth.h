//
//  YMUserAuth.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/13.
//  Copyright © 2018年 peanut. All rights reserved.
//

#import <Foundation/Foundation.h>

// 用户权限
typedef NS_OPTIONS(NSInteger, UserAuth) {
    UserAuth_None       = 0,
    UserAuth_Updown     = 1,
    UserAuth_Trail      = 1 << 1,
    UserAuth_DrawGraph  = 1 << 2,
    UserAuth_DrawImage  = 1 << 3,
    UserAuth_SelectMode = 1 << 4,
    UserAuth_Audio      = 1 << 5,
    UserAuth_Video      = 1 << 6,
    UserAuth_Erase      = 1 << 7,
    UserAuth_Unknow     = 1 << 8
};

typedef NS_ENUM(NSInteger, YMUserAuthStatus) {
    YMUserAuthStatus_Enable = 0,
    YMUserAuthStatus_Interrupt = 1
};


@interface YMUserAuth : NSObject

@property (nonatomic,readonly) UserAuth auth;
@property (nonatomic, readonly) YMUserAuthStatus status;

+ (instancetype)emptyAuth;
+ (instancetype)fullAuth;

- (void)appendAuth:(UserAuth)auth;
- (void)appendAuths:(NSArray *)authArray;
- (void)releaseAuth:(UserAuth)auth;
- (void)setUserAuthStatus:(YMUserAuthStatus )status;


@end
