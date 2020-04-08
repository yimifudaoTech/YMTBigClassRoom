//
//  YMCoursewareInfo.h
//  YiMiApp
//
//  Created by Caffrey on 2019/5/22.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMTCoursewarePageInfo.h"
#import "YMPageTypeModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 课件类型

 - YMTCoursewareTypeUndefined: 未定义的类型
 - YMTCoursewareTypeImage: 普通图片课件
 - YMTCoursewareTypeStructure: 结构化课件
 - YMTCoursewareTypeHTML: H5课件
 */
typedef NS_ENUM(NSUInteger, YMTCoursewareType) {
    YMTCoursewareTypeUndefined,
    YMTCoursewareTypeImage,
    YMTCoursewareTypeStructure,
    YMTCoursewareTypeHTML,
};

/** 课件信息 */
@interface YMTCoursewareInfo : YMPageTypeModel<YMTCoursewarePageInfo *>
/** 课件ID */
@property(nonatomic, copy) NSString *courseWareId;
/** 课堂ID */
@property(nonatomic, copy) NSString *lessonId;
/** h5课件的url */
@property(nonatomic, copy) NSString *h5Url;
/** 课件类型 1普通课件/2结构化/3h5 */
@property(nonatomic, copy) NSString *courseWareType;

@property(nonatomic, copy) NSString *courseWareName;

/// 总页数
@property(nonatomic, assign) NSInteger totalCount;

/** 课件类型 */
@property(nonatomic, assign) YMTCoursewareType type;

@property(nonatomic, copy) NSString *token;

/**栏目索引*/
@property(nonatomic, assign) NSInteger menuIndex;
/**是否已开始答题*/
@property(nonatomic, assign) BOOL hasStartExercise;
/**是否显示解析*/
@property(nonatomic, assign) BOOL syncToStudent;

///课件宽高比例
@property (nonatomic, assign) CGFloat docAspectRatio;


/** 获取当前对象对应的json字符串 */
- (NSString *)jsonString;

@end

NS_ASSUME_NONNULL_END
