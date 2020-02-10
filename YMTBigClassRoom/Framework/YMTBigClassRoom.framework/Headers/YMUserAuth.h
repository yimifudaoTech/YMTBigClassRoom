//
//  YMUserAuth.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/13.
//  Copyright © 2018年 peanut. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMAuthModel.h"

@interface YMUserAuth : NSObject

@property (nonatomic, strong) NSMutableDictionary *userAuthDic;

- (void)appendAuth:(YMAuthName)auth;
- (void)appendAuths:(NSArray *)authArray;
- (void)appendAuth:(YMAuthName)auth withAuthStatu:(YMAuthStatus)authStatus;
- (void)releaseAuth:(YMAuthName)auth;
- (void)releaseAuths:(NSMutableArray *)authArray;

@end
