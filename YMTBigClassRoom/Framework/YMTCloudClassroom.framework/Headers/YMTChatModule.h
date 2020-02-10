//
//  YMTChatModule.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/6.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTChatProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YMTChatMoudleDelegate <NSObject>

- (void)receiveNewMessage;

@end

@interface YMTChatModule : NSObject <YMTChatProtocol>

@property (nonatomic,weak)id <YMTChatMoudleDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
