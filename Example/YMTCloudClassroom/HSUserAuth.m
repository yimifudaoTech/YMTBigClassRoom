//
//  HSUserAuth.m
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/13.
//  Copyright © 2018年 peanut. All rights reserved.
//

#import "HSUserAuth.h"

@interface HSUserAuth ()

@property (nonatomic,readwrite) UserAuth auth;

@end

// 注意保证添加进入的顺序
static NSInteger Auths[5] = {UserAuth_Updown,UserAuth_Trail,UserAuth_Audio,
    UserAuth_Video,UserAuth_Erase};

@implementation HSUserAuth

+ (instancetype)emptyAuth {
    HSUserAuth *emptyAuth = [[self alloc] init];
    emptyAuth.auth = UserAuth_None;
    return emptyAuth;
}

+ (instancetype)fullAuth {
    HSUserAuth *fullAuth = [self emptyAuth];
    for (int i = 0; i < sizeof(Auths)/sizeof(NSInteger); i++) {
        fullAuth.auth |= Auths[i];
    }
    return fullAuth;
}

#pragma mark -- 权限操作相关
// 添加权限
- (void)appendAuth:(UserAuth)auth {
    _auth |= auth;
}

// 移除权限
- (void)releaseAuth:(UserAuth)auth {
    
    UserAuth validAuth = _auth&auth;
    
    NSMutableArray *indexs = [NSMutableArray array];
    for (int i = 0; i < sizeof(Auths)/sizeof(NSInteger); i++) {
        UserAuth pre_auth = Auths[i];
        if (pre_auth & validAuth) {
            [indexs addObject:@(i+1)];
        }
    }
    [self releaseAuthAtIndexs:indexs];
}

#pragma mark -- Priate Method
// 移除某一个权限
- (UserAuth)releaseAuthAtIndex:(int)index {
    _auth = _auth^(1<<(index-1));
    return _auth;
}

// 移除某一组权限
- (UserAuth)releaseAuthAtIndexs:(NSArray *)indexs {
    for (NSNumber *index in indexs) {
        _auth = [self releaseAuthAtIndex:[index intValue]];
    }
    return _auth;
}

@end
