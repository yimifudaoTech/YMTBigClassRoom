//
//  YMXlogModal.h
//  XLogDemo
//
//  Created by juwanli on 2019/7/30.
//  Copyright © 2019 juwanli. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMAPPTargetType) {
    YMTargetStudent,// 学生
    YMTargetTeacher,// 老师
};

@interface YMLogModel : NSObject

@property (nonatomic,assign)YMAPPTargetType targetType;
@property (nonatomic,copy)NSString * userName;
@property (nonatomic,copy)NSString * userMobile;
// 课程ID
@property (nonatomic,copy)NSString * lessonId;

/*
 * 初始化日志
 * @param   target          客户端类型 老师或者学生
 * @param   userName        当前登录的用户姓名
 * @param   userMobile      当前登录的用户账号
 * @param   lessonId        教室ID，可以为nil表示在教室外
 */

- (instancetype)initLogModelWithTargetType:(YMAPPTargetType)target userMobile:(NSString * _Nullable)userMobile userName:(NSString * _Nullable)userName lessonId:(NSString * _Nullable)lessonId;

@end

NS_ASSUME_NONNULL_END
