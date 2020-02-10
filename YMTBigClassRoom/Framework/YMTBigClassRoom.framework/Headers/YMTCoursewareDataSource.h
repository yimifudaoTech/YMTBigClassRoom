//
//  YMTCoursewareDataSource.h
//  AFNetworking
//
//  Created by yimi on 2019/12/19.
//

#import <Foundation/Foundation.h>
#import "YMPageDataSourceProtocol.h"
#import <YMTCloudClassroom/YMTCoursewarePageInfo.h>
#import <YMTCloudClassroom/YMTCoursewareInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTCoursewareDataSource : NSObject<YMPageDataSourceProtocol>

@property (nonatomic, strong)YMTCoursewareInfo *courseWareInfo;

@property (nonatomic, copy) void(^refreshBlock)(YMTCoursewarePageInfo *pageInfo);

@property (nonatomic, copy) void(^pageChangeBlock)(NSInteger pageCount, NSInteger pageIndex);

- (YMTCoursewarePageInfo *)getCurrentPage;

- (YMTCoursewarePageInfo *)getPageAtIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
