//
//  UIResponder+Router.h
//  ToDoDemo
//
//  Created by peanut on 2018/7/19.
//  Copyright © 2018年 peanut. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIResponderEventProxy.h"

@interface UIResponder (Router)

@property (nonatomic,strong) UIResponderEventProxy *eventProxy;

- (void)routerEventWithName:(NSString *)eventName userInfo:(NSDictionary *)userInfo;
- (NSDictionary *)appendParamToUserInfo:(NSDictionary *)userInfo;

@end
