//
//  YMBaseModel.h
//  AFNetworking
//
//  Created by yimi on 2019/10/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMModelGetDataResultCode) {
    /**
     * 获取成功
     */
    YMModelGetDataResultCodeSuccess = 0,
    
    /**
     * 获取失败
     */
    YMModelGetDataResultCodeFail = -1
};

typedef void(^YMModelGetDataResult)(BOOL result, _Nullable id data, YMModelGetDataResultCode code,  NSString * _Nullable msg);


@interface YMBaseModel : NSObject

@end

NS_ASSUME_NONNULL_END
