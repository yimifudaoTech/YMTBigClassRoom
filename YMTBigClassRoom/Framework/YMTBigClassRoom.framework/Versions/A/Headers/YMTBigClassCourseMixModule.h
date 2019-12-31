//
//  SDSmallClassRoomBaseView.h
//  student
//
//  Created by Caffrey on 2019/5/29.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMBigClassRoomBaseView.h"
#import <YMTCloudClassroom/YMTH5Courseware.h>

NS_ASSUME_NONNULL_BEGIN
/// 课件组件与白板
@interface YMTBigClassCourseMixModule : YMBigClassRoomBaseView
/** 课堂ID */
@property(nonatomic, copy) NSString *lessonId;
/** h5课件组件 */
@property(nonatomic, readonly, nullable) YMTH5Courseware *h5Courseware;
/** 当前正在同步数据 */
@property(nonatomic, assign, getter=isSyncing) BOOL syncing;

- (void)setupH5CoursewareWithCoursewareContent:(NSDictionary *_Nullable)content;

- (void)playAnimationWithContent:(NSDictionary *_Nullable)content;

@end

NS_ASSUME_NONNULL_END
