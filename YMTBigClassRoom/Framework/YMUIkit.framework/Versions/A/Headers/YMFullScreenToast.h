//
//  YMFullScreenToast.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/11/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^clickButtonBack)(BOOL select);

@interface YMFullScreenToast : UIView

/**
 *  按钮点击
 */
@property (nonatomic, copy) clickButtonBack clickButtonBack;

/*
 * loading加载页面
 * view 父视图
 * imageName 图片名称
 * loadingTitle 提示语文字
 * isHideTitle 是否隐藏提示语
 * seconds 延迟时间
 */
- (void)creatLoadingMaskView:(UIView *)view imageName:(NSString *)imageName loadingTitle:(NSString *)loadingTitle isHideTitle:(BOOL)isHideTitle setTimerDelay:(CGFloat)seconds;

/**
*  关闭定时器
*/
- (void)closeLoadingTimer;


/*
 * 教室进入失败提醒
 * view 父视图
 * imageName 图片名称
 * errorTitle 错误码文字
 */
- (void)creatWarnMaskView:(UIView *)view imageName:(NSString *)imageName errorTitle:(NSString *)errorTitle inTheClass:(BOOL)inTheClass;



@end

NS_ASSUME_NONNULL_END
