//
//  YMBoardWindowManager.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/12/26.
//

#import <Foundation/Foundation.h>
@class YMBoardWindow;

NS_ASSUME_NONNULL_BEGIN

@interface YMBoardWindowManager : NSObject

//设置父视图
@property (nonatomic, strong) UIView *parentView;


/// 展示所有窗口
- (void)showAllWindows;

/*
 添加视图
*/
- (void)addWindow:(YMBoardWindow *)window withBoardIdentify:(NSString *)identify;

/*
 移除视图
*/
- (void)removeWindow:(NSString *)identify;


/// 移除所有窗口
- (void)removeAllWindow;

/*
 显示视图
*/
- (void)showWindow:(NSString *)identify;




/// 更新window显示状态，不会调用addSubview
/// @param identify 窗口ID
/// @param isHidden 是否显示
- (void)updateWindowState:(NSString *)identify withState:(BOOL)isHidden;

/*
 隐藏视图
*/
- (void)hideWindow:(NSString *)identify;

/*
 视图移至最上层
*/
- (void)bringWindowToTop:(NSString *)identify;

/*
 修改视图位置与大小
 */
- (void)updateWindowRect:(CGRect)rect withBoardIdentify:(NSString *)identify;

@end

NS_ASSUME_NONNULL_END
