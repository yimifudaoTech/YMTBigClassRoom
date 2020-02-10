//
//  YMTH5CoursewareState.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTH5CoursewareState : NSObject

@property(nonatomic, strong) NSString *url;
@property(nonatomic, assign) NSInteger page;
@property(nonatomic, assign) NSInteger step;
@property(nonatomic, assign) double scrollOffset;

- (void)clearPageState;

@end

NS_ASSUME_NONNULL_END
