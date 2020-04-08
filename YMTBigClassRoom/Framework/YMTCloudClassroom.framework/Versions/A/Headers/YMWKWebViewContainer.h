//
//  YMWKWebViewContainer.h
//  YMTCloudClassroom
//
//  Created by mac on 2019/12/3.
//

#import <Foundation/Foundation.h>
#import "YMTJavaScriptService.h"
#import "YMWebviewNativeBridgeProtocol.h"

NS_ASSUME_NONNULL_BEGIN

// 其它注入的js方法

/** 1.1  课件: 同步课件信息   */
static NSString *kJSFuncWebSetPlanInfo = @"webSetPlanInfo";
/** 1.2  课件: H5结构化课件(h5Question) 发送操作指令JS-Native    */
static NSString *kJSFuncWebSendMessageToNative = @"sendMsgToNative";
/** 1.3  课件: H5结构化课件 页码更新 */
static NSString *kJSFuncWebUpdatePlanPageIndex = @"webUpdatePlanPageIndex";
/** 1.4  课件: H5结构化课件 唤起答题板  */
static NSString *kJSFuncWebGetAnswerBoard = @"webGetAnswerBoard";
/** 1.5  课件: H5结构化课件 Toast提示 */
static NSString *kJSFuncWebSetH5TextTip = @"setH5TextTip";

/** 2.1  聊天室：收到新消息  */
static NSString *kJSFuncHaveNewMessage = @"haveNewMessage";

/** 3.1  技术支持：关闭    */
static NSString *kJSFuncWebReportClose = @"webReportClose";
/** 3.2  技术支持：报障成功  */
static NSString *kJSFuncWebReportSuccess = @"webReportSuccess";

/** 4.1  通用功能: 调用Native相册功能    */
static NSString *kJSFuncWebGetAlbum = @"webGetAlbum";
/** 4.2  通用功能: 调用Native相机功能    */
static NSString *kJSFuncWebGetCamera = @"webGetCamera";

@protocol YMWKWebViewContainerDelegate <NSObject>

- (void)receiveScriptMessage:(WKScriptMessage *)messageInfo;

@end

@interface YMWKWebViewContainer : NSObject

@property (nonatomic, strong) WKWebView *ymWebView;
@property (nonatomic, weak) id <YMWKWebViewContainerDelegate> delegate;
@property (nonatomic, strong) id<YMWebviewNativeBridgeProtocol> ymNativeBridge;

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

/**
 是否允许手势捏合缩放
 */
- (void)setZoomEnabled:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
