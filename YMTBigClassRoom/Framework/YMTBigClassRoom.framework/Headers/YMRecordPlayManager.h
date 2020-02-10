//
//  YMRecordPlayManager.h
//  student
//
//  Created by mac on 2019/9/18.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMRecordPlayManager : NSObject

+ (YMRecordPlayManager *)sharedInstance;

- (void)startRecordingVideoWithLessonid:(NSString *)lessonid token:(NSString *)token viewParent:(UIViewController *)viewParent userid:(NSString *)userid;

- (BOOL)removeRecordFiles:(NSString *)userid;

@end

NS_ASSUME_NONNULL_END
