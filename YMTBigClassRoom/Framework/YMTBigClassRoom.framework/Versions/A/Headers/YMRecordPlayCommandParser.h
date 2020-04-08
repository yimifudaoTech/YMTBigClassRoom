//
//  YMRecordPlayCommandParser.h
//  student
//
//  Created by mystarains on 2019/8/19.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMRecordPlayDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMRecordPlayCommandParser : NSObject

@property(nonatomic, copy) void(^click)(NSArray* command,CGFloat nextCommandInterval,CGFloat progress);
@property(nonatomic, copy) void(^palyAudioClick)(NSArray*command);
@property(nonatomic, copy, nullable) void(^complete)(BOOL isComplete);

@property (nonatomic, weak) id<YMRecordPlayCommandParserDelegate> delegate;

@property(nonatomic, strong) id commandPath;
@property(nonatomic, strong) NSMutableArray<NSArray*>* commandArray;
@property(assign, nonatomic) BOOL isNewCommand;
@property(assign, nonatomic) BOOL isPlayAudioCommand;
@property(nonatomic, strong) NSMutableArray<NSArray*>* synCommandarray;

@property(nonatomic, assign)long long totalTime;
@property(nonatomic, readonly) NSString* totalTimeString;

@property(nonatomic, readonly) NSString* currentTimeString;
@property(nonatomic, assign)long long currentPlayTime;

@property(nonatomic, assign) NSUInteger currentIndex;
@property(nonatomic, assign)long long currentCommandTime;
@property(nonatomic, assign) CGFloat progress;
@property(nonatomic, assign) CGFloat rate;//默认1倍速度

/**
 * 开始播放
 * */

- (void)play;

/**
 * 停止播放
 * */
- (void)stop;

/**
 * 暂停
 * */
- (void)pause;

@end

NS_ASSUME_NONNULL_END
