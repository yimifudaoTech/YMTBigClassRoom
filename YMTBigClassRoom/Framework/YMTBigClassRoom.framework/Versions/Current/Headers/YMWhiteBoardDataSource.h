//
//  YMWhiteBoardDataSource.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/10/15.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMBoardModel.h"
#import "YMPageDataSourceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMWhiteBoardDataSource : NSObject <YMPageDataSourceProtocol>

@property (nonatomic, copy) void(^refreshBlock)(YMBoardPageInfo *pageInfo);

@property (nonatomic, copy) void(^pageChangeBlock)(NSInteger pageCount, NSInteger pageIndex);

/// 获取当前页面数据
- (YMBoardPageInfo *)getCurrentPage;

- (void)setBoardId:(NSString *)boardId;

@end

NS_ASSUME_NONNULL_END
