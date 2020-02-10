//
//  YMCoursewarePageInfo.h
//  teacher
//
//  Created by Caffrey on 2019/5/27.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 课件单页信息 */
@interface YMTCoursewarePageInfo : NSObject

/** 页码 */
@property (nonatomic, assign) NSInteger pageNo;
/** 类型 0空白、1原始课件、2图片 */
@property (nonatomic, copy) NSString *courseWareType;
/** url */
@property (nonatomic, copy) NSString *url;
/** 当前动画播放的步骤 */
@property (nonatomic, assign) NSInteger currentAnimStep;

/** 获取当前对象对应的json字符串 */
- (NSString *)jsonString;
@end

NS_ASSUME_NONNULL_END
