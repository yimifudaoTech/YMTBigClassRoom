//
//  KxMenu.h
//  kxmenu project
//  https://github.com/kolyvan/kxmenu/
//
//  Created by Kolyvan on 17.05.13.
//

/*
 Copyright (c) 2013 Konstantin Bukreev. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 - Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 - Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#import <UIKit/UIKit.h>

typedef void (^DismissBlock)(void);

@interface KxMenuItem : NSObject

@property (readwrite, nonatomic, strong) UIImage *image;
@property (readwrite, nonatomic, strong) NSString *title;
@property (readwrite, nonatomic, weak) id target;
@property (readwrite, nonatomic) SEL action;
// 默认字体颜色
@property (nonatomic,strong)UIColor * normalColor;
// 选中状态字体颜色
@property (readwrite, nonatomic, strong) UIColor *foreColor;
@property (readwrite, nonatomic) NSTextAlignment alignment;
// 按钮高亮状态的背景图片
@property (nonatomic,strong)UIColor * hightLightColor;
// 菜单子类的高度
@property (nonatomic,assign)CGFloat height;
// 选中态背景颜色
@property (nonatomic,strong)UIColor * selectedBackgroundColor;
// 是否当前选中的
@property (nonatomic,assign)BOOL selectedStatus;

+ (instancetype) menuItem:(NSString *) title
                    image:(UIImage *) image
                   target:(id)target
                   action:(SEL) action;
+ (instancetype) menuItem:(NSString *) title
                    image:(UIImage *) image
                   target:(id)target
               titleColor:(UIColor*)color
                   action:(SEL) action;

@end

@interface KxMenu : NSObject
+ (instancetype) sharedMenu;

+ (void) showMenuInView:(UIView *)view
               fromRect:(CGRect)rect
              menuItems:(NSArray *)menuItems;

+ (void) dismissMenu;

+ (UIColor *) tintColor;
+ (void) setTintColor: (UIColor *) tintColor;

+ (UIFont *) titleFont;
+ (void) setTitleFont: (UIFont *) titleFont;
@property (copy, nonatomic) void(^dissMissBlock)(void);

@end
