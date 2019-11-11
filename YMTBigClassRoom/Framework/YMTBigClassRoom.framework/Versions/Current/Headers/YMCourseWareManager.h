//
//  YMCourseWareManager.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/28.
//

#import <Foundation/Foundation.h>
#import "YMEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMCourseWareManager : NSObject

+ (instancetype)shareCourseWareInstance;
/**
 初始化查看课件视图
 @param controller  控制器
 @param roomId           房间ID
 @param userId           用户ID
 @param result           查看课件回调
 */
- (void)viewCourseWare:(UIViewController *)controller roomId:(NSString *)roomId userId:(NSString *)userId result:(void(^)(BOOL success, YMTRoomInfoCode code, NSString * _Nullable errorMessage))result;

@end

NS_ASSUME_NONNULL_END
