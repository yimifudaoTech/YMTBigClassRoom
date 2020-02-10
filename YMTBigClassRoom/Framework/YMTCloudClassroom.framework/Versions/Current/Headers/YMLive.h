//
//  YMLive.h
//  YiMiLib
//
//  Created by Caffrey on 2019/4/18.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLiveProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMLive : NSObject<YMLiveProtocol>

+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<YMLiveDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
