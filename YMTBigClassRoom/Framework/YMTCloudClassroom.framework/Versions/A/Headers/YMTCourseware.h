//
//  YMCourseware.h
//  YiMiLib
//
//  Created by Caffrey on 2019/5/22.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTCoursewareProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/** 课件组件 */
@interface YMTCourseware : NSObject <YMTCoursewareProtocol>
@property(nonatomic, weak) id<YMTCoursewareCallback> callback;
@end

NS_ASSUME_NONNULL_END
