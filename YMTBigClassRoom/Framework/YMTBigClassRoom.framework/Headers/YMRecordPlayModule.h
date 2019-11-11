//
//  YMRecordPlayModule.h
//  student
//
//  Created by mystarains on 2019/8/19.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMRecordPlayProtocol.h"
#import "YMRecordPlayDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMRecordPlayModule : NSObject <YMRecordPlayProtocol>

@property (nonatomic, weak) id<YMRecordPlayDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
