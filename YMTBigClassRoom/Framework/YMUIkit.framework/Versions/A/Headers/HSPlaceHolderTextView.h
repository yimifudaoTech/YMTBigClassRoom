//
//  HSPlaceHolderTextView.h
//  YiMiLib
//
//  Created by peanut on 2018/8/10.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HSPlaceHolderTextView;
@protocol HSPlaceHolderTextViewDelegate <NSObject>
@optional
- (void)HSTextViewDidChange:(HSPlaceHolderTextView *)textView;
- (void)HSTextViewDidBeginEditting:(HSPlaceHolderTextView *)textView;
- (void)HSTextViewDidEndEditting:(HSPlaceHolderTextView *)textView;

@end

@interface HSPlaceHolderTextView : UITextView

@property (nonatomic,copy) NSString *placeHolder;
@property (nonatomic,strong) UIFont *placeHolderFont;
@property (nonatomic,strong) UIColor *placeHolderColor;
@property (nonatomic,strong) UIColor *inputTextColor;
@property (nonatomic,strong) UIFont *inputTextFont;

@property (nonatomic,copy,readonly) NSString *inputText;

@property (nonatomic,assign) NSInteger maxLength;

@property (nonatomic,weak) id<HSPlaceHolderTextViewDelegate> placeHolderDelegate;

+ (instancetype)initWithFrame:(CGRect)frame
                  placeHodler:(NSString *)placeHolder
                         font:(UIFont *)placeHolderFont
                        color:(UIColor *)placeHolderColor;

+ (instancetype)initWithPlaceHolder:(NSString *)placeHolder
                               font:(UIFont *)placeHolderFont
                              color:(UIColor *)placeHolderColor;

@end
