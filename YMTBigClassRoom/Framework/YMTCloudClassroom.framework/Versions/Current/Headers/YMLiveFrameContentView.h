//
//  YMLiveFrameContentView.h
//  student
//
//  Created by yimi on 2018/11/16.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMLiveFrameView.h"
#import "YMLIveFrameViewProtocol.h"

@interface YMLiveFrameContentView : UIView<YMLIveFrameViewProtocol>

@property (nonatomic, strong, readonly) YMLiveFrameView *liveFrameView;

- (instancetype)initWithFrame:(CGRect)frame videoHeight:(CGFloat )videoHeight;

@end
