//
//  YMFTaskNotifyDelegate.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 caoshaokun. All rights reserved.
//

#ifndef UINotifyDelegate_h
#define UINotifyDelegate_h

@protocol YMFTaskNotifyDelegate <NSObject>

@required
- (NSData *)req2buf;
- (int)buf2resp:(NSData *)responseData;
- (int)onTaskEnd:(uint32_t)tid errType:(uint32_t)errtype errCode:(uint32_t)errcode;

@end

#endif /* UINotifyDelegate_h */
