//
//  YMBoardDataManager.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/1/15.
//

#import <Foundation/Foundation.h>
#import "YMBoardModel.h"
#import <YMTCloudClassroom/YMTCoursewareInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMBoardDataManager : NSObject

+ (instancetype)shareManager;

- (YMBoardModel *)getBoardModel:(NSString *)boardId;

- (YMTCoursewareInfo *)getCoursewareInfo:(NSString *)boardId;

- (YMTCoursewareInfo *)createCoursewareInfo:(NSString *)boardId;

- (void)clearBoardData;

@end

NS_ASSUME_NONNULL_END
