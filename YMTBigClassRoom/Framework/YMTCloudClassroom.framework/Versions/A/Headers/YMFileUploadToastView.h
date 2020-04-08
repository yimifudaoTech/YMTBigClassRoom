//
//  YMFileUploadToastView.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/11/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMFileUploadToastView : UIView

/**
显示上传进度Toast
@param message  加载提示文案
*/
- (void)showProgressMessage:(NSString *)message;
/**
显示上传失败Toast
@param message  加载失败提示文案
@param hander 回调Block
*/
- (void)showErrorMessage:(NSString *)message finishHander:(dispatch_block_t)hander;
/**
移除Toast
*/
- (void)removeToastView;

@end

NS_ASSUME_NONNULL_END
