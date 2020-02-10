//
//  YMWKWebViewContainer.h
//  YMTCloudClassroom
//
//  Created by mac on 2019/12/3.
//

#import <Foundation/Foundation.h>
#import "YMTJavaScriptService.h"

NS_ASSUME_NONNULL_BEGIN

// 其它注入的js方法

/** 1.1  课件: 同步信息   */
static NSString *kJSFuncWebSetPlantInfo = @"webSetPlantInfo";
/** 1.2  课件: H5结构化课件(h5Question) 发送操作指令JS-Native    */
static NSString *kJSFuncWebSendMessageToNative = @"sendMsgToNative";

/** 2.1  聊天室：收到新消息  */
static NSString *kJSFuncHaveNewMessage = @"haveNewMessage";

/** 3.1  技术支持：关闭    */
static NSString *kJSFuncWebReportClose = @"webReportClose";
/** 3.2  技术支持：报障成功  */
static NSString *kJSFuncWebReportSuccess = @"webReportSuccess";

@protocol YMWKWebViewContainerDelegate <NSObject>

- (void)receiveScriptMessage:(WKScriptMessage *)messageInfo;

@end

@interface YMWKWebViewContainer : NSObject

@property (nonatomic, strong) WKWebView *ymWebView;
@property (nonatomic, weak) id <YMWKWebViewContainerDelegate>delegate;

/**
 初始化方法
 @param type 加载的webView的业务类型
 */
- (instancetype)initWkWebViewContainerWith:(YMTWKWebViewType)type;

/*
 * 原生与H5交互
 */
- (void)evaluateYimiNativeJS:(NSString *)js;

/*
* 所加载的URL
*/
- (void)loadURL:(NSString *)url;

/*
* 销毁
*/
- (void)destroy;

/*
* 是否允许物理交互
*/
- (void)setCanTouch:(BOOL)can;

@end

NS_ASSUME_NONNULL_END
