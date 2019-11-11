//
//  HSRubberView.h
//  CollectiveTeachDemo
//
//  Created by peanut on 2018/11/15.
//  Copyright © 2018年 peanut. All rights reserved.
//
// 橡皮擦view
#import <UIKit/UIKit.h>

@protocol HSRubberViewDelegate <NSObject>
@optional
- (void)sliderValueChanged:(NSDictionary *)info;
@end

@interface HSRubberView : UIView

@property (nonatomic,weak) id<HSRubberViewDelegate> delegate;

@property (nonatomic,assign) CGFloat rubberMinValue;
@property (nonatomic,assign) CGFloat rubberMaxValue;

- (void)loadConfig:(NSDictionary *)config;

@end
