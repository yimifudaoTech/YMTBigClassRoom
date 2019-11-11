//
//  YMRecordPlayViewController.h
//  student
//
//  Created by mystarains on 2019/8/14.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMRecordPlayViewController : UIViewController

@property(nonatomic, assign) BOOL showAdjustRate;//播放速率,默认不显示
@property(nonatomic, copy) NSString *lessonId;//课程编号

- (instancetype)initWithTrailPath:(NSURL*)trailPath VoicePath:(NSArray*)voicePath title:(NSString *)title voiceTime:(NSInteger)voiceTime;

@end

@interface UIViewController (YMRecordPlayViewController)

-(YMRecordPlayViewController*)presentPlayerWithFilePath:(NSURL *)filePath
                                            mp3PathList:(NSArray *)mp3PathList
                                                  Title:(NSString *)title
                                              voiceTime:(NSInteger)voiceTime;
@end

NS_ASSUME_NONNULL_END
