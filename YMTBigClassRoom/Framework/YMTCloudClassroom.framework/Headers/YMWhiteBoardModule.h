//
//  YMWhiteBoardModule.h
//  YMWhiteBoardSDK
//
//  Created by mystarains on 2019/7/12.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMWhiteBoardProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMWhiteBoardModule : NSObject<YMWhiteBoardProtocol>

@property (nonatomic, weak) id<YMWhiteBoardDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
