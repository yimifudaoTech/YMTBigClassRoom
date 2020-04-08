//
//  YMKPITrack.h
//  AFNetworking
//
//  Created by yimi on 2019/12/17.
//

#import <Foundation/Foundation.h>
#import "YMKPIMacros.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMKPITrack : NSObject

+ (void)printKPIEvent:(NSString *)target withEvent:(YMKPIEvent)event withExtraInfo:(NSString *)info;

+ (void)printKPIEventWithSystemLog:(NSString *)target withEvent:(YMKPIEvent)event withExtraInfo:(NSString *)info;

+ (void)enableKPITrackToast:(BOOL)isEnable;

@end


NS_ASSUME_NONNULL_END
