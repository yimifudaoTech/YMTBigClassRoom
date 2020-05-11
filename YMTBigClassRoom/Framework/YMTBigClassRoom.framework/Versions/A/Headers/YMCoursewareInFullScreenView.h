//
//  YMCoursewareInFullScreenView.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2020/4/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YMTCoursewareInfo;

@interface YMCoursewareInFullScreenView : UIView
// 课件信息
@property (nonatomic,strong)YMTCoursewareInfo * coursewareInfo;
@property (nonatomic,copy)void(^ _Nonnull closeActionBlock)(void);
// 初始化
- (instancetype)initFullScreenCoursewareView:(UIView *)superView;
// 设置底部View的Hidden状态,默认显示
- (void)setBottomViewHidden:(BOOL)hidden;
// 设置课件页码信息
- (void)setCoursewareCurrentPage:(NSInteger)currentPage totalPage:(NSInteger)totalPage;
// 销毁
- (void)destory;

@end

NS_ASSUME_NONNULL_END
