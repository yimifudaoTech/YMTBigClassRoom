//
//  YMTInteractiveTool.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/4.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTInteractiveTool : NSObject

+ (void)showTrophyViewTo:(UIView *)view animateWithDuration:(NSTimeInterval)duration stayWithDuration:(NSTimeInterval)stayDuration completion:(void (^ __nullable)(BOOL finished))completion;

@end

NS_ASSUME_NONNULL_END
