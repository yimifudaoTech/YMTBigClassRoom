//
//  JWAlert.h
//  YiMiApp
//
//  Created by 王建伟 on 16/8/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XYZView.h"

@class JWAlert;

typedef void(^JWAlertCallBack)(JWAlert *view,NSInteger index);
@interface JWAlert : UIView

@property (nonatomic , strong) id  imageContent;
@property (nonatomic , strong) NSString  * title;
@property (nonatomic , strong) NSString  * contentMsg;
@property (nonatomic , strong) NSString  * tips;
@property (nonatomic , strong) NSMutableArray  * btnsArray;


-(void)showAlert:(id)imageContent title:(NSString*)title content:(NSString *)contentMsg tips:(NSString*) tips btns:(NSArray*)btnsTitles inView:(UIView*)window;

-(void)showAlert:(id)imageContent title:(NSString*)title content:(NSString *)contentMsg tips:(NSString*) tips btns:(NSArray*)btnsTitles inView:(UIView*)window textAlignment:(NSTextAlignment)alignment numberLine:(NSInteger)line;

/**
 可以设置按钮颜色
 
 */
-(void)showAlert:(id)imageContent title:(NSString*)title content:(NSString *)contentMsg tips:(NSString*) tips btns:(NSArray*)btnsTitles inView:(UIView*)window textAlignment:(NSTextAlignment)alignment numberLine:(NSInteger)line btnColor:(UIColor*)color;
-(void)dismiss;
@end
