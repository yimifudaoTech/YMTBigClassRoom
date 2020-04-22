//
//  UIAlertView+Category.h
//  XYZCollection
//
//  Created by xieyan on 15/4/1.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIAlert : NSObject
+(UIAlertView*)pushAlert:(NSString*)content;
+(UIAlertView*)pushAlertWithTitle:(NSString *)title message:(NSString*)content;
    

+(UIAlertView*)pushAlert:(NSString*)content confirm:(void(^)(void))confirm;
+(UIAlertView*)pushAlert:(NSString*)content title:(NSString*)title confirmTitle:(NSString*)confirmTitle confirm:(void(^)(void))confirm;




+(UIAlertView*)pushCancelAlert:(NSString*)content confirm:(void(^)(void))confirm;
+(UIAlertView*)pushCancelAlert:(NSString*)content confirm:(void(^)(void))confirm cancel:(void(^)(void))cancel;//取消
+(UIAlertView*)pushrefuseAlert:(NSString*)content confirm:(void(^)(void))confirm refuse:(void(^)(void))cancel;//拒绝
+(UIAlertView*)pushrefuseAlert:(NSString*)content  leftBtn:(NSString*)leftTitle rightBtn:(NSString*)rightTitle left:(void(^)(void))left right:(void(^)(void))right;
+(UIAlertView*)pushCancelAlert:(NSString*)content title:(NSString*)title confirmTitle:(NSString*)confirmTitle confirm:(void(^)(void))confirm cancel:(void(^)(void))cancel;

@end
