//
//  YMHTTPTool.h
//  YiMiApp
//
//  Created by Yangsenkai on 2017/2/21.
//  Copyright © 2017年 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef void (^YMRequestSuccess)(id json);
typedef void (^YMRequestFailure)(NSError *error);
@interface YMHTTPTool : NSObject
+ (instancetype)shareInstance;
+ (void)GET:(NSString *)url params:(NSDictionary *)params success:(YMRequestSuccess)success failure:(YMRequestFailure)failure;

+ (void)POST:(NSString *)url params:(NSDictionary *)params success:(YMRequestSuccess)success failure:(YMRequestFailure)failure;

/**POST网络请求*/
-(NSURLSessionDataTask* )POSTUrl:( NSString* )url
                           Parma:(NSDictionary* )parma
                       BodyParma:(id)bodyParma
                     HeaderParma:(NSDictionary* )headerParma
                         success:(void (^ )( NSURLSessionDataTask *  task, id responseObject,int code))success
                         failure:(void (^ )(NSURLSessionDataTask *  task, NSError *  error))failure
                       hudInView:(UIView* )view;

/**POST网络请求 imgaeIdentifier 图片唯一标示*/
-(NSURLSessionDataTask* )POSTUrl:( NSString* )url
                           Parma:(NSDictionary* )parma
                       BodyParma:(id)bodyParma
                 imgaeIdentifier:(NSString*)imgaeIdentifier
                     HeaderParma:(NSDictionary* )headerParma
                  uploadProgress:( void (^)(NSProgress *uploadProgress)) uploadProgressBlock
                         success:(void (^ )( NSURLSessionDataTask *  task, id responseObject,int code))success
                         failure:(void (^ )(NSURLSessionDataTask *  task, NSError *  error))failure
                       hudInView:(UIView* )view;
@end
