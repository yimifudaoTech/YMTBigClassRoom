//
//  SKBOSClient.h
//  YiMiLib
//
//  Created by mac on 2019/3/5.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SKBOSClient : NSObject

/**
 请求百度BOS 上传图片
 */
+ (void)baiduBOSUploadFileRequestWithSessionToken:(NSString *)sessionToken
                                    secretKey:(NSString *)secretKey
                                        keyId:(NSString *)keyId
                                     endPoint:(NSString *)endPoint
                                   bucketName:(NSString *)bucketName
                                      keyPath:(NSString *)keyPath
                                    imageData:(NSData *)imageData
                                  bosProgress:(void (^)(NSNumber *))bosProgress
                              completionBlock:(void (^)(int code, id responseData))completionBlock;

@end


