//
//  HSUserAuth.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/13.
//  Copyright © 2018年 peanut. All rights reserved.
//

#import <Foundation/Foundation.h>

// 用户权限
typedef NS_OPTIONS(NSInteger, UserAuth) {
    UserAuth_None     = 0,
    UserAuth_Updown   = 1,
    UserAuth_Trail    = 1 << 1,
    UserAuth_Audio    = 1 << 2,
    UserAuth_Video    = 1 << 3,
    UserAuth_Erase    = 1 << 4,
    UserAuth_Unknow   = 1 << 5
};

@interface HSUserAuth : NSObject

@property (nonatomic,readonly) UserAuth auth;

+ (instancetype)emptyAuth;
+ (instancetype)fullAuth;

- (void)appendAuth:(UserAuth)auth;
- (void)releaseAuth:(UserAuth)auth;

@end
