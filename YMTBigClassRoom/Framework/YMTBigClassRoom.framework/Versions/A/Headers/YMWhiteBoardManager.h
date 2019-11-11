//
//  YMWhiteBoardManager.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/10/28.
//

#import <Foundation/Foundation.h>
#import <YMTCloudClassroom/YMWhiteBoardModule.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMBoardType) {
    YMBoardType_BlackBoard,
    YMBoardType_CoursewareBoard,
    YMBoardType_SmallBoard
};

static NSDictionary <NSNumber *, NSString *> * YMBoardTypeAndNameDictionary() {
    static NSDictionary *_boardTypeDictionary;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _boardTypeDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
                                  @"blackboard", @(YMBoardType_BlackBoard),
                                  @"coursewareWhiteBoard", @(YMBoardType_CoursewareBoard),
                                  @"smallWhiteBoard",@(YMBoardType_SmallBoard),
                                  nil];
    });
    
    return _boardTypeDictionary;
};

@interface YMWhiteBoardManager : NSObject

- (void)addBoard:(id<YMWhiteBoardProtocol>) board withBoardIdentify:(NSString *)identify;

- (void)setSelectBoard:(NSString *)indentify;

- (NSString *)getSelectBoardIdentify;

- (YMBoardType)getSelectBoardType;

- (NSMutableDictionary *)getAllBoard;

- (id<YMWhiteBoardProtocol>) getSelectBoard;

- (id<YMWhiteBoardProtocol>) getSelectBoard:(NSString *)identify;


@end

NS_ASSUME_NONNULL_END
