//
//  YMBoardBaseModel.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMBoardBaseModel : NSObject

@property (nonatomic, strong) NSString *itemId;
@property (copy, nonatomic) NSString *groupId;
@property (nonatomic, assign) NSInteger orderNum;
@property (nonatomic, copy) NSString *boardId;
@property (nonatomic, copy) NSString *pageId;


@end

NS_ASSUME_NONNULL_END
