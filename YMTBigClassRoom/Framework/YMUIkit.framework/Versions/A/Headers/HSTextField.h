//
//  HSTextField.h
//  YiMiLib
//
//  Created by peanut on 2018/6/11.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HSTextField : UITextField

@property (nonatomic,strong) IBInspectable UIImage *leftImage;
@property (nonatomic,strong) IBInspectable UIImage *rightImage;
@property (nonatomic,assign) IBInspectable BOOL drawLineDependOnRightview;
@property (nonatomic,assign) IBInspectable BOOL drawLineDependOnLeftview;
@property (nonatomic,assign) IBInspectable BOOL editEnable;
@property (nonatomic,assign) IBInspectable CGFloat leftImageLead;
@property (nonatomic,assign) IBInspectable CGFloat leftImageTrail;
@property (nonatomic,assign) IBInspectable CGFloat rightImageLead;
@property (nonatomic,assign) IBInspectable CGFloat rightImageTrail;

@end
