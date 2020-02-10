//
//  YMToastUtil.h
//  AFNetworking
//
//  Created by mystarains on 2019/9/15.
//

#import <Foundation/Foundation.h>
#import "YMEndClassAlertView.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, YMToastType) {
    YMToastTypeAnswerWrong,
    YMToastTypeAnswerCancle,
    YMToastTypeAnswerStop,
    YMToastTypeAnswerCorrect,
    YMToastTypeAnswerTimeOut,
    YMToastTypeTeacherLeave,
    YMToastTypeWatingClass,
    YMToastTypeStartClass,
    YMToastTypeEndClass,
};

NS_ASSUME_NONNULL_BEGIN

@interface YMToastUtil : NSObject

+ (void)showWithType:(YMToastType)type message:(NSString *)message;

+ (void)showWithType:(YMToastType)type duration:(NSTimeInterval)duration;

+ (void)showWithType:(YMToastType)type message:(NSString *)message duration:(NSTimeInterval)duration;

+ (void)showWithType:(YMToastType)type message:(NSString *)message duration:(NSTimeInterval)duration inView:(UIView*)superView;

+ (void)showEndClassAlert:(YMClassAlertType)type block:(void (^)(void))closeBlock;

@end

NS_ASSUME_NONNULL_END
