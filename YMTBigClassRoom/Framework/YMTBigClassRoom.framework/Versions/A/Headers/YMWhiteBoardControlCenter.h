//
//  YMWhiteBoardControlCenter.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/12/25.
//

#import <Foundation/Foundation.h>
#import <YMTCloudClassroom/YMWhiteBoardSDK.h>
#import "YMIMControlCenterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMBoardType) {
    YMBoardType_BlackBoard,
    YMBoardType_CoursewareBoard,
    YMBoardType_SmallBoard
};

@interface YMWhiteBoardControlCenter : NSObject

@property (nonatomic, assign, readonly) YMBoardType boardType;

- (void)setSyncDataState:(BOOL)isFinishSyncData;

#pragma mark - 图形轨迹数据操作相关
- (void)addTrail:(YMDrawTrailModel*)model;

- (void)addGraph:(YMDrawGraphModel *)model drawBySelf:(BOOL)isSelf;

- (void)addImage:(YMDrawImageModel *)model drawBySelf:(BOOL)isSelf;

- (void)clearCurrentBoardPage;

- (void)clearAllBoardPage;

- (void)deleteGraph:(NSString *)itemId;

- (void)deleteGraphBySelf;

- (void)updateImage:(UIImage * _Nullable)drawImage loadStatus:(NSString *)statusText loading:(BOOL)loading itemId:(NSString *)itemId;

#pragma mark - 页面相关操作

/// 加页
- (void)addBoardPage;

/// 删页
- (void)deleteBoardPage;

/// 跳转到页面
/// @param pageNo 页码
- (void)goToBoardPage:(NSInteger)pageNo;

#pragma mark - 白板属性相关


/// 是否开启白板交互
- (void)setEnable:(BOOL)enable;


/// 是否隐藏白板
/// @param isHiden YES 隐藏， NO 显示
- (void)hideDrawLayer:(BOOL)isHiden;

/// 选择白板行为类型
- (void)setWhiteBoardToolType:(YMDrawToolType)type;


/// 获取当前白板工具类型
- (YMDrawToolType)getWhiteBoardToolType;

/// 设置线段宽度
- (void)setLineWidth:(CGFloat)width;
/// 设置线段颜色
- (void)setLineColor:(UIColor *)color;
/// 设置白板相关偏移
- (void)setWhiteBoardOffset:(CGPoint)offset;

/** 设置白板contentSize*/
- (void)setWhiteBoardContentSize:(CGSize)contentSize;

/** 获取白板缩放*/
- (CGSize)getWhiteBoardContentSize;

- (void)setScrollOffset:(CGPoint)scrollOffset;
/** 获取白板偏移点 */
- (CGPoint)getScrollOffset;

///设置boardId
- (void)setBoardId:(NSString *)boardId;

- (void)updateWhiteboard;

- (void)captureImage:(void(^)(UIImage *image))callback;


/// 获取boardId
- (NSString *)getBoardId;

#pragma mark - 获取白板属性

- (UIView *)getWhiteBoardView;

@end

NS_ASSUME_NONNULL_END
