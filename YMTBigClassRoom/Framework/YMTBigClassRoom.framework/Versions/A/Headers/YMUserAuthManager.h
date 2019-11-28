//
//  YMUserAuthManager.h
//  AFNetworking
//
//  Created by yimi on 2019/10/29.
//

#import <Foundation/Foundation.h>
#import "HSUserAuth.h"
#import "YMAuthCommand.h"

NS_ASSUME_NONNULL_BEGIN



typedef void(^YMUserAuthChangeBlock)(NSString *uid);

@interface YMUserAuthManager : NSObject

- (void)setAuthChangeBlock:(YMUserAuthChangeBlock)callback;

- (void)addInitAuths:(NSArray *)initAuths withUid:(NSString *)uid;

- (void)appendAuths:(NSArray *)auths withUid:(NSString *)uid;

- (void)refreshUserAuth:(YMAuthCommand *)command;

- (void)setUserAuthStatus:(YMUserAuthStatus)status withUid:(NSString *)uid;

- (void)resetUserAuth:(NSString *)uid withAuthStatus:(YMUserAuthStatus)status withInitAuths:(NSArray *)initAuths;

- (void)clearAllUserAuth;

- (BOOL)muteEnable:(NSString *)uid;

- (BOOL)videoEnable:(NSString *)uid;

- (BOOL)drawEnable:(NSString *)uid;

- (BOOL)isUserAuthSaved:(NSString *)uid;

@end

NS_ASSUME_NONNULL_END
