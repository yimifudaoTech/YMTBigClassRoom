//
//  YMClassroomEvaluationView.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/1/8.
//

// 课堂评价（老师结束课程后，学生评价View）
#import <UIKit/UIKit.h>
#import "YMFormEditModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMClassroomEvaluationView : UIView

/**
 *  初始化评价View
 *  @param dataArray  评价上传服务器数据model集合
 *  @param completion 回调
 */
- (void)showEvaluationViewWithDataArray:(NSMutableArray *)dataArray completion:(void(^)(NSDictionary * submitDict))completion;
/**
 *  隐藏移除View
 */
- (void)dismissEvaluationView;
/**
 设置评价列表是否可以滑动 默认为YES 可滑动
 @param enabled  是否可滑动状态
 */
- (void)setEvaluateTableViewScrollEnabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
