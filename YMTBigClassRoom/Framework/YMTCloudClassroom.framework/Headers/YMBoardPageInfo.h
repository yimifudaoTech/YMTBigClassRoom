//
//  YMBoardPageInfo.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/24.
//

#import <Foundation/Foundation.h>
#import "YMDrawTrailModel.h"
#import "YMDrawGraphModel.h"
#import "YMDrawImageModel.h"
#import "NSMutableDictionary+YMSort.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMBoardPageInfo : NSObject

@property (nonatomic, assign) NSInteger pageNo;

- (BOOL)isGraphExit:(NSString *)itemId;

- (BOOL)isImageExit:(NSString *)itemId;

- (NSArray *)getTrailArray;

- (NSDictionary *)getGraphDic;

- (NSDictionary *)getImageDic;

- (NSArray *)getItemIdArray;

- (void)addTrail:(YMDrawTrailModel *)trailModel;

- (void)addGraph:(YMDrawGraphModel *)graphModel;

- (void)addImage:(YMDrawImageModel *)imageModel;

- (void)removeGraph:(NSString *)itemId;

- (void)removeImage:(NSString *)itemId;

- (void)clearPageInfo;

@end

NS_ASSUME_NONNULL_END
