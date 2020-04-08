//
//  TestToolItem.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/20.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TestToolItemType){
    TestToolItemType_Performance,
    TestToolItemType_Mock,
    TestToolItemType_Log,
    TestToolItemType_ShareLog,
    TestToolItemType_CoursewareWhiteBoard
};

@interface TestToolItem : NSObject

@property (nonatomic, assign) TestToolItemType itemType;

@property (nonatomic, strong) NSString *itemName;

@property (nonatomic, assign) BOOL itemState;

@end

