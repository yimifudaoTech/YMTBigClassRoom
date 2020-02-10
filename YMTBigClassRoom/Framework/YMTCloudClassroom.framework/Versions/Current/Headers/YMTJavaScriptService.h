//
//  YMTJavaScriptService.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2019/12/26.
//

#import <Foundation/Foundation.h>
#import "YMTWKWebViewManager.h"

NS_ASSUME_NONNULL_BEGIN

// 通用的需要注入的方法名 **不需要在使用的地方再次添加**
static NSString *kJSFuncWebGetToken = @"webGetToken";
static NSString *kJSFuncWebLoadFinshed = @"webLoadFinshed"; // 课件和技术支持
static NSString *kJSFuncWebLoadFinished = @"webLoadFinished";// 聊天

@class YMTJSMessageHandler;

@interface YMTJavaScriptService : NSObject

/**
 设置默认的需要注入的方法名
 */
- (void)setUpDefaultScriptMessages;

/**
 初始化js 的 window.yimiNative 对象，
 在往window.yimiNative对象注入js前必须执行一次此方法
 注意：如果已经往window.yimiNative对象注入了js，再执行此方法，会导致之前注入的js全部失效
 */
- (void)setupJSYimiNativeToWebViewConfiguration:(WKWebViewConfiguration *)configuration;

/**
 注册原生方法到 js 的 window.yimiNative 对象上
 @param messageHandler js调Native回调对象
 @param messageNames 方法名集合
 */
- (void)injectNativeFuncInJsWithScriptMessageHandler:(YMTJSMessageHandler *)messageHandler scriptMessageName:(NSMutableArray<NSString *> *)messageNames;

/**
 获取注入的方法名
 */
- (NSArray<NSString *> *)getScriptMessages;

/**
 移除注入的某个js方法
 */
- (void)removeScriptMessageHandlerWithName:(NSString * _Nullable)name;

/**
 移除注入的所有JS方法
 */
- (void)removeAllScriptMessages;

@end


@protocol YMTJSMessageHandlerDelegate <NSObject>

// 收到H5通知，Native接收到通知做响应的处理
- (void)receiveScriptMessage:(WKScriptMessage *)messageInfo;

@end

@interface YMTJSMessageHandler : NSObject<WKScriptMessageHandler>

@property (nonatomic,weak)id<YMTJSMessageHandlerDelegate> delegate;

@end


@interface YMTEvaluateJSHanlder : NSObject

- (instancetype)setUpEvaluate:(WKWebView *)wkWebView;

/**
 Native调用JS的方法
 @param js 方法名
 @param completion 回调
 */
- (void)evaluateYimiNativeJS:(NSString *)js completionHandler:(void(^)(id _Nullable response, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
