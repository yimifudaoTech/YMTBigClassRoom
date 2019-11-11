//
//  YMCursorView.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/24.
//

//  光标/教鞭
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,YMCursorViewType) {
    YMCursorViewType_None = 0,
    YMCursorViewType_OneToOne,
    YMCursorViewType_SmallClass,
    YMCursorViewType_BigClass
};

@interface YMCursorView : UIView

//实际点
@property (nonatomic,assign) CGPoint currentPoint;
@property (nonatomic,assign) YMCursorViewType cursorType;
@property (nonatomic,copy) void(^hiddenBlock)(BOOL hidden);
@property (nonatomic,copy) void(^point)(CGFloat pointX,CGFloat pointY);

/**
 初始化函数
 @return 返回教鞭对象
 */
+ (instancetype)initCursorView;

/**
 教鞭命令处理
 @param blackBoard  黑板视图
 @param currentPoint 点的位置
 */
- (void)showCursorView:(UIView *)blackBoard currentPoint:(CGPoint)currentPoint;

/**
移除
*/
+ (void)removeCursorView;

// 手写板
- (void)handleTouchEvent:(CGPoint)point previous:(CGPoint)previous;
- (void)handlePendoSuspendedEvent:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
