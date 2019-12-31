//
//  YMTDrawGraphTool.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/10/23.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTDrawView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMTDrawGraphTool : NSObject


+ (void)showDrawGraphView:(YMTDrawViewType)type image:(UIImage * _Nullable)drawImage onView:(UIView *)view contentSize:(CGSize)contentSize contentOffset:(CGPoint)offset selectedPoint:(CGPoint)selectedPoint completionHandler:(void (^)(BOOL confirmed, NSDictionary *contentDic))completionHandler;

+ (void)showDrawGraphView:(YMTDrawViewType)type image:(UIImage * _Nullable)drawImage convertRect:(CGRect)convertRect contentSize:(CGSize)contentSize contentOffset:(CGPoint)offset selectedPoint:(CGPoint)selectedPoint completionHandler:(void (^)(BOOL confirmed, NSDictionary *contentDic))completionHandler;


@end

NS_ASSUME_NONNULL_END
