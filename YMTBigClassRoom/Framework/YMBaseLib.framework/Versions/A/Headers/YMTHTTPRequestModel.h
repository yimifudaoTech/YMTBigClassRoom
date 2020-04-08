//
//  YMTHTTPRequestModel.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define HttpMethodTypePost  @"POST"
#define HttpMethodTypeGet   @"GET"

typedef NSString * RequestUrl;
typedef NSString * HTTPMethodType;

@interface YMTHTTPRequestModel : NSObject

/**
 * 请求URL
 */
@property (nonatomic,copy) RequestUrl urlStr;
/**
 * 调用方式POST,GET
 */
@property (nonatomic,copy,readonly) HTTPMethodType methodType;
/**
 *  需传递的参数
 */
@property (nonatomic,strong) id params;

@property (nonatomic,strong,getter=getHTTPHeaderDict) NSDictionary * httpHeaderDict;

/**
 初始化GET请求
 */
- (instancetype)initGetRequestWithUrl:(RequestUrl)urlStr params:(nullable id)params;

/**
 初始化POST请求
 */
- (instancetype)initPostRequestWithUrl:(RequestUrl)urlStr params:(nullable id)params;

/**
 *  在已有的参数中添加参数(此函数为避免参数为nil的情况)
 *  @param value value
 *  @param key   key
 */
- (void)addParam:(NSString*)value forKey:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
