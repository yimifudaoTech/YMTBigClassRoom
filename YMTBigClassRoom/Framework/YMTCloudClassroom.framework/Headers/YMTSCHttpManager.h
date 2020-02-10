//
//  GPLSCHttpManager.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/11/16.
//  Copyright © 2018 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>

@class YMTSCResponse;
@class YMTSCRequest;
@class GPLSCHttpManager;


//////////////////Respnose////////////////////////////////////////
@interface YMTSCResponse : NSObject

@property (nonatomic, assign) NSInteger code;
@property (nonatomic, assign) NSInteger mn;
@property (nonatomic, assign) NSInteger sn;
@property (nonatomic) id data;

- (BOOL)isSuccess;

@end

//////////////////Request////////////////////////////////////////
typedef void (^YMTSCRequestBlock)(YMTSCRequest *request);

@interface YMTSCRequest : NSObject

@property (nonatomic, strong) YMTSCResponse *response;
@property (nonatomic, copy) YMTSCRequestBlock successBlock;
@property (nonatomic, copy) YMTSCRequestBlock failedBlock;

@property (nonatomic, strong) NSString *hostIp;//服务器地址

@property (nonatomic, strong) NSDictionary *dicParameters;//入参
@property (nonatomic, strong) NSDictionary *headerParameters;//http头入参
@property (nonatomic, strong) NSError *error;//错误信息

- (instancetype)initWithSuccessCallBack:(YMTSCRequestBlock)succCallBack;
- (instancetype)initWithSuccessCallBack:(YMTSCRequestBlock)succCallBack failedCallBack:(YMTSCRequestBlock)failCallBack;


/**
 服务域名地址

 @return 域名/ip+端口号
 */
- (NSString *)hostUrl;

/**
 链接api接口地址
 @return 地址路径
 */
- (NSString *)url;


/**
 处理原始数据

 @param respObject 原始数据 可能是加密后的
 */
- (void)parseResponse:(NSObject *)respObject;


/**
 相应response的类

 @return 该类
 */
- (Class)responseClass;


/**
 对原始数据做相应的转换成可用数据

 @param data 需要转换的对象
 @return 对应转换的类
 */
- (id)parseToUseDataResponse:(id)data;
@end


//////////////////Http Manager////////////////////////////////////
@interface YMTSCHttpManager : NSObject

/**
 post 请求
 
 @param request 请求体
 */
- (void)asyncPostRequest:(YMTSCRequest *)request;
//取消所有请求线程
- (void)cancleAllOperationQueue;
@end
