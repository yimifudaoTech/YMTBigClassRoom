//
//  YMTHTTPSessionManager.h
//  YMTCloudClassroom_Example
//
//  Created by SendomZhang on 6/8/2019.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTHTTPURLModel.h"
#import "YMTHTTPMacros.h"
#import "YMTHTTPRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary *_Nullable(^YMTHTTPSessionManagerParametersModify)(NSDictionary *parameters);

typedef id _Nullable (^YMTHTTPSessionManagerResultModify)(id _Nullable object, NSError *__autoreleasing *_Nullable error);

@interface YMTHTTPSessionManager : NSObject

/// env string
@property (nonatomic, copy, readonly) NSString *envString;

@property (nonatomic, copy, readonly) NSString *imEnvString;


@property (nonatomic, copy) NSString *urlHost;
@property (nonatomic, copy) NSString *urlPort;

/// 参数处理
@property (nonatomic, copy, readwrite) YMTHTTPSessionManagerParametersModify parametersModify;

/// 参数处理
@property (nonatomic, copy, readwrite) YMTHTTPSessionManagerResultModify resultSuccessModify;

+ (instancetype)httpSessionManagerWithType:(YMTHttpSessionManagerType)type;

- (void)setJsonFilePath:(NSString *)filePath;

- (nullable NSURLSessionDataTask *)fetch:(YMTHTTPRequestModel *)requestModel
                                progress:(nullable void (^)(NSProgress *progress))progress
                                  result:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject, NSError *error))result;

- (void)changeEnv:(YMTRoomEnvironment)envStr;

- (YMTHTTPURLModel *)modifyURL:(NSString *)URLString;

@end

NS_ASSUME_NONNULL_END
