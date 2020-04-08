//
//  UIResponderEventProxy.h
//  ToDoDemo
//
//  Created by peanut on 2018/7/19.
//  Copyright © 2018年 peanut. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface UIResponderEventProxy : NSObject

- (instancetype)initWithResponder:(UIResponder *)responder;

- (void)handleEvent:(NSString *)eventName userInfo:(NSDictionary *)userInfo;
- (void)registerEvent:(SEL)selector eventName:(NSString *)eventName;

@end
