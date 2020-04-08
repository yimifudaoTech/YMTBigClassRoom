//
//  TestToolManager.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/20.
//

#import <Foundation/Foundation.h>
#import "TestToolView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TestToolManager : NSObject

- (void)showTestToolViewWithBlock:(TestToolOnSelectedBlock)block;

@end

NS_ASSUME_NONNULL_END
