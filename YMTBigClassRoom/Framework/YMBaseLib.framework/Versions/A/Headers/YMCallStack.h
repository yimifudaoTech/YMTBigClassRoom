//
//  YMCallStack.h
//
//  Created by yimi on 2017/6/22.
//

#import <Foundation/Foundation.h>
#import "YMCallLib.h"

typedef NS_ENUM(NSUInteger, YMCallStackType) {
    YMCallStackTypeAll,     //全部线程
    YMCallStackTypeMain,    //主线程
    YMCallStackTypeCurrent  //当前线程
};



@interface YMCallStack : NSObject

+ (NSString *)callStackWithType:(YMCallStackType)type;

extern NSString *ymStackOfThread(thread_t thread);

@end
