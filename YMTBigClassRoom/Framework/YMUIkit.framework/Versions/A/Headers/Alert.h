//
//  Alert.h
//  YiMiApp
//
//  Created by 王建伟 on 16/7/19.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XYZView.h"
#import "OMGToast.h"
#import "JWToast.h"
#import "JWAlert.h"
#import "NSString+Empty.h"
#define XYZAlert [Alert Instance]

typedef enum : NSUInteger {
    AlertType_Alert,
    AlertType_Toast,
    AlertType_JWToast, // 黑色背景 不带按钮
    AlertType_JWAlert, // 白色背景 带按钮
    
} AlertType;

typedef enum : NSUInteger {
    AlertScheme_OnlyOne,
    AlertScheme_OverLay,
    AlertScheme_Queue,
} AlertScheme;

@interface Alert : NSObject
+(instancetype)Instance;


-(UIView* )showType:(AlertType)alerttype scheme:(AlertScheme)scheme inView:(UIView*)superview CallBackBlock:(id)CallBackBlock;

@end




static NSString* keyAlert_UIAlert_Title        = @"keyAlert_UIAlert_Title";
static NSString* keyAlert_UIAlert_Content      = @"keyAlert_UIAlert_Content";
static NSString * keyAlert_UIAlert_BtnsArray   =@"keyAlert_UIAlert_BtnsArray";
static NSString * keyAlert_UIAlert_Type        =@"keyAlert_UIAlert_Type";
#define AlertMessage(_title_,_message_,...) @{keyAlert_UIAlert_Type:@"Alert",keyAlert_UIAlert_Title:[NSString validateStr:_title_],keyAlert_UIAlert_Content:[NSString validateStr:_message_],keyAlert_UIAlert_BtnsArray:[NSArray arrayWithObjects:__VA_ARGS__, nil]}

typedef void(^AlertViewCallBack)(UIAlertView* alert,NSInteger index);
AlertViewCallBack setAlertViewCallBack(AlertViewCallBack);
@interface UIAlertView (Alert)

@end



static NSString* keyAlert_Toast_Content      = @"keyAlert_Toast_Content";
static NSString * keyAlert_Toast_Duration    = @"keyAlert_Toast_Duration";
#define ToastMessage(_content_,_duration_) @{keyAlert_Toast_Content:_content_,keyAlert_Toast_Duration:@(_duration_)}

@interface OMGToast (Alert)

@end

static NSString * keyAlert_JWToast_Image      = @"keyAlert_JWToast_Image";
static NSString * keyAlert_JWToast_Content      = @"keyAlert_JWToast_Content";
static NSString * keyAlert_JWToast_Duration    = @"keyAlert_JWToast_Duration";
#define JWToastMessage(_image_,_content_,_duration_) @{keyAlert_JWToast_Image:[NSString validateStr:_image_],keyAlert_JWToast_Content:[NSString validateStr:_content_],keyAlert_JWToast_Duration:@(_duration_)}

@interface JWToast (Alert)

@end



static NSString * keyAlert_JWAlert_Image      = @"keyAlert_JWAlert_Image";
static NSString * keyAlert_JWAlert_Title      = @"keyAlert_JWAlert_Title";
static NSString * keyAlert_JWAlert_Content      = @"keyAlert_JWAlert_Content";
static NSString * keyAlert_JWAlert_Tips      = @"keyAlert_JWAlert_Tips";
static NSString * keyAlert_JWAlert_BtnsTitles      = @"keyAlert_JWAlert_BtnsTitles";


#define JWAlertMessage(_image_,_title_,_content_,_tips_,...) @{keyAlert_JWAlert_Image:[NSString validateStr:_image_],keyAlert_JWAlert_Title:[NSString validateStr:_title_],keyAlert_JWAlert_Content:[NSString validateStr:_content_],keyAlert_JWAlert_Tips:[NSString validateStr:_tips_],keyAlert_JWAlert_BtnsTitles:[NSArray arrayWithObjects:__VA_ARGS__, nil]}


JWAlertCallBack setJWAlertCallBack(JWAlertCallBack block);
@interface JWAlert (Alert)

@end


@interface UIView (dismiss)
-(void)dismiss;
@end

