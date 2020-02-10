//
//  YMEvaluateManager.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2020/1/9.
//

#import <Foundation/Foundation.h>
#import "YMEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMEvaluateManager : NSObject

/**
 初始化显示课堂评价
 @param roomId 教室ID
 @param token  用户token
 @param userId 用户ID
 @param userType 用户类型 STU：学生 TEA：老师
 @param completion 回调
 */
- (void)showClassroomEvaluateWithRoomId:(NSString *)roomId token:(NSString *)token userId:(NSString *)userId userType:(NSString *)userType completion:(void(^)(BOOL success, YMTRoomInfoCode code, NSString * _Nullable errorMessage))completion;
/**
 设置评价列表是否可以滑动 默认为YES 可以滑动
 @param enabled  是否可滑动状态
 */
- (void)setEvaluateTableViewScrollEnabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
