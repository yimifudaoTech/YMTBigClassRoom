//
//  YMFPushNotifyDelegate.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//

#ifndef PushNotifyDelegate_h
#define PushNotifyDelegate_h

@protocol YMFPushNotifyDelegate <NSObject>

@required - (void)notifyPushMessage:(NSData *)pushData withCmdId:(NSInteger)cmdId;

@end

#endif /* PushNotifyDelegate_h */
