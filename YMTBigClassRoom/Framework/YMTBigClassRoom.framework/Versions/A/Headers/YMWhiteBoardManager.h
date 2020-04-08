//
//  YMWhiteBoardManager.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/10/28.
//

#import <Foundation/Foundation.h>
#import <YMWhiteBoardControlCenter.h>

NS_ASSUME_NONNULL_BEGIN

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

- (void)addBoard:(YMWhiteBoardControlCenter *)board;

- (void)removeBoard:(NSString *)boardId;

- (void)clearAllBoard;

- (void)setSelectBoard:(NSString *)boardId;

- (void)setSelectBoardWithBoard:(YMWhiteBoardControlCenter *)board;

- (NSString *)getSelectBoardId;

- (YMBoardType)getSelectBoardType;

- (NSMutableDictionary<NSString *, YMWhiteBoardControlCenter *> *)getAllBoard;

- (YMWhiteBoardControlCenter *) getSelectBoard;

- (YMWhiteBoardControlCenter *) getSelectBoard:(NSString *)boardId;


@end

NS_ASSUME_NONNULL_END
