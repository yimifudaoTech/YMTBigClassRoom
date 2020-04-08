//
//  Macro_Notification.h
//  YiMiApp
//
//  Created by xieyan on 15/9/15.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#ifndef YiMiApp_Macro_Notification_h
#define YiMiApp_Macro_Notification_h



#define NotificationCenter [NSNotificationCenter defaultCenter]

#define kNotificationCenter [NSNotificationCenter defaultCenter]


#define PostNotification(__signal__,__object__) \
[NotificationCenter postNotificationName:__signal__ object:__object__]

#define RegistNotification(__signal__,__function__)\
[NotificationCenter addObserver:self selector:@selector(__function__) name:__signal__ object:nil]

#define RemoveNotification(__signal__)\
[NotificationCenter removeObserver:self name:__signal__ object:nil]

#import <Foundation/Foundation.h>

static NSString *BackgroundTaskTimeoutKey =  @"BackgroundTaskTimeoutKey";
static NSString *UIApplicationDidResignActiveNotification =  @"UIApplicationDidResignActiveNotification";
static NSString *keyNotify_RefreshBadge = @"getUnreadMessTotalNum";
static NSString *keyNotify_RefreshAllBadge = @"refreshAllBadgeNum";

//static NSString* UIApplicationDidResignActiveNotification =  @"UIApplicationDidResignActiveNotification";
#endif
