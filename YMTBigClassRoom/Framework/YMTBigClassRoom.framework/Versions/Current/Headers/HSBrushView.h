//
//  HSBrushView.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/15.
//  Copyright © 2018年 peanut. All rights reserved.
//
// 画笔选择view
#import <UIKit/UIKit.h>

@protocol HSBrushViewDelegate <NSObject>
@optional
- (void)brushSliderValueChanged:(NSDictionary *)info;
- (void)brushSelectedChanged:(NSDictionary *)info;
@end

@interface HSBrushView : UIView

@property (nonatomic,weak) id<HSBrushViewDelegate> delegate;
@property (nonatomic,assign) NSUInteger clomuns;
@property (nonatomic,assign) CGFloat minLineWidth;
@property (nonatomic,assign) CGFloat maxLineWidth;

- (void)setColors:(NSArray *)colors;
- (void)loadConfig:(NSDictionary *)config;

@end
