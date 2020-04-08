//
//  YMMethodRunUtil.h
//  YMTCloudClassroom
//
//  Created by yimi on 2020/1/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMMethodRunUtil : NSObject

+ (BOOL)runSelector:(SEL)selector target:(id)target;

@end

NS_ASSUME_NONNULL_END
