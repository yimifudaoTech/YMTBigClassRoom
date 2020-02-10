//
//  YMH5Courseware.h
//  YiMiLib
//
//  Created by Caffrey on 2019/5/22.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTCoursewareProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/** H5课件组件 */
@interface YMTH5Courseware : NSObject <YMTCoursewareProtocol>

@property(nonatomic,weak)id<YMTCoursewareCallback> callback;
@property(nonatomic,weak)id<YMTCoursewareReceiveDataDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
