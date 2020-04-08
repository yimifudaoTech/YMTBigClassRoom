//
//  ZQButton.h
//  YiMiLib
//
//  Created by CoderZQ on 2018/1/4.
//  Copyright © 2018年 YiMi. All rights reserved.
//  灵活自定义按钮 调用示例如下
/*
 ZQButton *button =[ZQButton buttonWithType:UIButtonTypeCustom];
 button.layoutStyle = 3;  // 改这个就可以了
 [button setTitle:@"哈哈" forState:UIControlStateNormal];
 [button setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
 [button setImage:[UIImage imageNamed:@"微信"] forState:UIControlStateNormal];
 [self.view addSubview:button];
 
 [button mas_makeConstraints:^(MASConstraintMaker *make) {
 make.centerX.equalTo(self.view.mas_centerX);
 make.centerY.equalTo(self.view.mas_centerY);
 }];
 */

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ZQLayoutButtonStyle){
    
    ZQLayoutButtonStyleLeftImageRightTitle,  // 0 左图片 右文本
    ZQLayoutButtonStyleLeftTitleRightImage,  // 1 左文本 右图片
    ZQLayoutButtonStyleUpImageDownTitle,     // 2 图片在上文字在下
    ZQLayoutButtonStyleUpTitleDownImage      // 3 文字在上图片在下
    
};

@interface ZQButton : UIButton

// 布局方式
@property (nonatomic, assign) ZQLayoutButtonStyle layoutStyle;
// 图片和文字的间距，默认值8
@property (nonatomic, assign) CGFloat midSpacing;

@end
