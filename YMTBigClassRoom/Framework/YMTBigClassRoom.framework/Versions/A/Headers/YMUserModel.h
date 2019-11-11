//
//  YMUserModel.h
//  AFNetworking
//
//  Created by yimi on 2019/10/16.
//

#import <Foundation/Foundation.h>
#import "YMBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMUserModel : YMBaseModel

+ (void)queryStuPrize:(NSString *)roomId userId:(NSString *)userId resultBlock:(YMModelGetDataResult)resultCallback;

+ (void)queryStuCredit:(NSString *)roomId userId:(NSString *)userId resultBlock:(YMModelGetDataResult)resultCallback;

@end

NS_ASSUME_NONNULL_END
