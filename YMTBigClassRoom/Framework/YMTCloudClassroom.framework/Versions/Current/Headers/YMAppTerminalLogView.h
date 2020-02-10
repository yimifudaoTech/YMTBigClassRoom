//
//  YMAppTerminalLogView.h
//  YMUILib
//
//  Created by juwanli on 2019/9/23.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMAppTerminalLogView : UIView

+ (instancetype)shareView;

// 显示
- (void)showAppTerminalLogView;

- (void)printLog:(NSString *)log;

@end

NS_ASSUME_NONNULL_END
