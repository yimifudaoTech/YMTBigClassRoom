//
//  YMPageTypeModel.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMPageTypeModel<ObjectType> : NSObject

@property (nonatomic, copy) NSString *boardId;
@property (nonatomic, assign) NSInteger currentPageNo;
@property (nonatomic, assign, readonly) NSInteger pageCount;
@property (nonatomic, strong) NSMutableArray<ObjectType> *pageInfoArray;

- (ObjectType)getCurrentPageInfo;

@end

NS_ASSUME_NONNULL_END
