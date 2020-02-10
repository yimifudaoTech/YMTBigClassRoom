//
//  YMTWKWebViewManager.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2019/12/27.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMTWKWebViewType) {
    YMTWKWebViewType_Courseware = 0, // 课件
    YMTWKWebViewType_Chat, // 聊天
    YMTWKWebViewType_TechnicalSupport // 技术支持
};

@interface YMTWKWebViewManager : NSObject

/**
 实例方法获取WebView
 */
+ (WKWebView *)getWKWebView;

/**
初始化WebView
@param type webView对应的类型
@param url 加载的url
 */
+ (void)wkWebViewWithType:(YMTWKWebViewType)type loadUrl:(NSString *)url;

/**
初始化WebView
@param type webView对应的类型
*/
+ (void)wkWebViewWithType:(YMTWKWebViewType)type;

/**
获取WebView
@param type webView对应的类型
 */
+ (WKWebView *)getWKWebViewWithType:(YMTWKWebViewType)type;

/**
销毁WebView
@param type webView对应的类型
 */
+ (void)destoryWKWebViewWithType:(YMTWKWebViewType)type;

/**
销毁所有WebView
*/
+ (void)destoryAllWKWebView;

/**
 加载WebView
 @param type webView对应的类型
 @param url 加载的url
 */
+ (void)loadRequestWithType:(YMTWKWebViewType)type url:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
