//
//  YMWhiteBoardDrawManager.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/10/29.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMWhiteBoardDrawManager : NSObject

@property (nonatomic, strong) CALayer *drawLayer;//轨迹绘制层

- (void)drawTrailWithData:(NSArray *)dataSource;

@end

NS_ASSUME_NONNULL_END
