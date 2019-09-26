//
//  YMTAppDelegate.m
//  YMTCloudClassroom
//
//  Created by zhangqian on 07/30/2019.
//  Copyright (c) 2019 zhangqian. All rights reserved.
//

#import "YMTAppDelegate.h"

#import <YMTBigClassRoom/YMTHTTPSessionManager.h>

#import <PINCache/PINCache.h>

@implementation YMTAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.

    [YMTHTTPSessionManager shareManager].resultSuccessModify = ^id _Nullable(id  _Nullable object, NSError * _Nullable __autoreleasing * _Nullable error) {
        if ([object[@"data"] isKindOfClass:[NSDictionary class]]) {
            return object[@"data"];
        }else {
            *error = [NSError errorWithDomain:@"服务器响应成功，参数方法可能出现某种错误" code:1000 userInfo:nil];
            return nil;
        }
    };
    
#if DEBUG
    NSString *envString = (NSString *)[[PINCache sharedCache].diskCache objectForKey:@"kAppEnvString"];
    if (!envString) {
        envString = @"Debug";
        [[PINCache sharedCache].diskCache setObject:@"Debug" forKey:@"kAppEnvString"];
    }
    [[YMTHTTPSessionManager shareManager] changeEnv:envString];
#else
    [[YMTHTTPSessionManager shareManager] changeEnv:@"Release"];
#endif
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
