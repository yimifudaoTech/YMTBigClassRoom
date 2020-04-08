//
//  JWToast.h
//  YiMiApp
//
//  Created by 王建伟 on 16/8/1.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JWToast : UIView
@property(nonatomic,strong)NSString * message;
@property(nonatomic,strong)id imageString;
@property(nonatomic,assign)NSInteger     duration;
-(void)showToast:(id)imageName message:(NSString *)mseeage inView:(UIView*)window duration :(NSInteger)duration;

-(void)dismiss;
@end
