//
//  YMCloudClassroomDelegate.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/18.
//

#ifndef YMCloudClassroomDelegate_h
#define YMCloudClassroomDelegate_h
#import "YMEnum.h"
@class YMCloudClassroomInfo;

@protocol YMTCloudClassroomDelegate <NSObject>

@optional
- (void)cloudClassroomDidJoinSuccess:(NSString *_Nonnull)uid withRoomInfo:(YMCloudClassroomInfo *_Nonnull)roomInfo;

- (void)cloudClassroomOccurError:(YMTRoomInfoCode) errorCode;

@end

#endif /* YMCloudClassroomDelegate_h */
