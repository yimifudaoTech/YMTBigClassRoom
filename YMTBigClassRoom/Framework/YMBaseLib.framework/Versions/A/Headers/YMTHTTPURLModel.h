//
//  YMTHTTPURLModel.h
//  YMTCloudClassroom_Example
//
//  Created by SendomZhang on 6/8/2019.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTHTTPURLModel : NSObject

/// domain
@property (nonatomic, copy, readwrite) NSString *domain;

/// path
@property (nonatomic, copy, readwrite) NSString *path;

/// method
@property (nonatomic, copy, readwrite) NSString *method;

/// requestSerializer
@property (nonatomic, copy, readwrite) NSString *requestSerializer;

@end

NS_ASSUME_NONNULL_END
