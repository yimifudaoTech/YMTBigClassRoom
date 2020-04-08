//
//  XYZCoverView.h
//  YiMiApp
//
//  Created by xieyan on 15/10/23.
//  Copyright © 2015年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
//抽象类，只用来继承，类里集成各种动画效果
typedef enum : NSUInteger {
    XYZCoverViewAnimateTypeNone,
//    XYZCoverView,
//    XYZCoverView,
} XYZCoverViewAnimateType;
@interface XYZCoverView : UIView


-(instancetype)initWithView:(UIView*)view withAnimate:(void(^)(UIView* animateView,CGRect destinationFrame))animate;
@property(nonatomic,strong)UIView* contentView;


//animate
-(void)startAnimate;
@property(nonatomic,assign)XYZCoverViewAnimateType animateType;


//自定义动画用
@property(nonatomic,strong)void(^animate)(UIView* animateView,CGRect destinationFrame);
-(void)contentAnimate:(UIView*)animateView;


@end
