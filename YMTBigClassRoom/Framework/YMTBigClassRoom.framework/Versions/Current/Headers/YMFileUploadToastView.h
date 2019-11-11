//
//  YMFileUploadToastView.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/11/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMFileUploadToastView : UIView

- (void)showProgressMessage:(NSString *)message;

- (void)showErrorMessage:(NSString *)message finishHander:(dispatch_block_t)hander;

- (void)removeToastView;

@end

NS_ASSUME_NONNULL_END
