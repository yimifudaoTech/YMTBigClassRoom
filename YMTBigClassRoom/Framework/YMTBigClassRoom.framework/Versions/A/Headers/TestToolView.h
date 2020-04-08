//
//  TestToolView.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TestToolItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TestToolOnSelectedBlock)(TestToolItemType type, BOOL state);

@interface TestToolView : UIView

@property (nonatomic, strong) NSMutableArray<TestToolItem *> *dataSource;

@property (nonatomic, copy) TestToolOnSelectedBlock selectedBlock;

@end

NS_ASSUME_NONNULL_END
