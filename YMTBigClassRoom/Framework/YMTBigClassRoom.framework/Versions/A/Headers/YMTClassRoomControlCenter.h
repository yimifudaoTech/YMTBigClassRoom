//
//  YMTClassRoomControCenter.h
//  student
//
//  Created by SendomZhang on 12/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>


#import <YMTCloudClassroom/YMWhiteBoardModule.h>
#import <YMTCloudClassroom/YMTSCServerHeader.h>
#import <YMTCloudClassroom/YMTCourseWareModel.h>
#import <YMTCloudClassroom/YMTRoomProtocols.h>

@class XYCourseWareLayer;
@class YMBigClassViewForGroupRoom;

@interface YMTClassRoomControlCenter : NSObject

- (void)resetAllClassRoomView;

@end

/// 课件相关操作
@interface YMTClassRoomControlCenter (Course)

/// 课件视图
- (UIView *)getCourseViewWithLiveRoomID:(NSString *)liveRoomID smallClass:(BOOL)small title:(NSString *)title;

- (YMBigClassViewForGroupRoom *)getCurrentGroupRoom;

/// 跳到课件第几页
- (void)gotoPage:(NSInteger)page;

/// 获取当前课件是第几页
- (NSUInteger)getCurrentPage;

/// 是否正在同步
- (void)syncing:(BOOL)status;

/// 更新视图
- (void)update;

/// 设置h5的课件内容
- (void)setupH5CoursewareWithCoursewareContent:(NSDictionary *)dic;

- (void)controlPage:(NSInteger)pageIndex key:(NSString *)docId controlType:(NSInteger)type;

- (NSString *)getKeyDocId;

- (void)zoomEvent:(NSDictionary *)config;

// 通过key获取view
- (YMBigClassViewForGroupRoom *)groupRoomViewWithKey:(NSString *)key;

/// 获取当前课件的总页数
- (NSInteger)getTotalPage;

/**
 添加group room
 
 @param key 标记id
 */
- (void)addGroupIdViewIdView:(NSString *)key
           drawLayerDelegate:(id<YMWhiteBoardDelegate>)delegate
                 cursorPoint:(void(^)(CGFloat pointX, CGFloat pointY))cursorPoint
                   zoomInOut:(void(^)(CGFloat zoomScale, CGFloat offsetX, CGFloat offsetY))zoomInOut
               didScrollView:(void(^)(UIScrollView *scrollView))didScrollView
                 refreshPage:(void(^)(id<YMTRoomDataProtocol> DB, NSMutableDictionary * drawData,NSMutableDictionary * drawOldData, YMTCourseWareModel *courseWare))refreshPage;
/// 获取 //TODO: 待补充
- (YMTCourseWareModel *)getCourseWareModel;

/// 课件偏移YM
- (CGPoint)getCourseScrollOffset;

/// 获取当前房间的数据
- (NSMutableArray *)getArrData;

/// TODO:设置图片课件隐藏？
- (void)setCourseImageHidden:(BOOL)hidden;
/// TODO:设置大图？
- (void)setCourseLageImageHidden:(BOOL)hidden;

/// 绘制网络图片
- (void)draw_picture:(YMTCourseWareModel*)model;
/// 重新布局课件
- (void)courseLayout;

@end

/// 课件相关操作
@interface YMTClassRoomControlCenter (WhiteBoard)

- (void)setWhiteBoardEnable:(BOOL)enable;


/**
 隐藏绘制层
 @param isHiden 是否隐藏绘制层
 */
- (void)hideDrawLayer:(BOOL)isHiden;

/// 选择白板行为类型
- (void)setWhiteBoardToolType:(YMDrawToolType)type;
/// 设置线段宽度
- (void)setLineWidth:(CGFloat)width;
/// 设置线段颜色
- (void)setLineColor:(UIColor *)color;
//TODO: 待确定
- (BOOL)existSpecifiedTrail:(NSString *)config;

// 画笔清除撤销
- (void)handleOperationWithParams:(NSDictionary *)params;

/// 设置教鞭位置
- (void)setCursorRatePoint:(CGPoint)point;

- (void)drawTrail:(YMDrawTrailModel*)model groupId:(NSString*)groupId;

/// 撤销笔迹
- (void)draw_undo_groupId:(NSString *)groupId;

/// 撤销指定的所有轨迹
- (void)cleanSpecifiedTrail:(NSString *)groupId;
/// 播放动画
- (void)playAnimationWithContent:(NSDictionary *)content;
/// 获取白板实际高度
- (CGFloat)getWhiteBoardRealHeight;

/// 设置白板相关偏移 高度
- (void)refreshWhiteBoard;
/// 设置白板相关偏移
- (void)setWhiteBoardOffset:(CGPoint)offset;
/// 设置教鞭类型
- (void)setCursorType:(WhiteBoardCursorViewType)cursorType;
/// 设置白板数据
- (void)setWhiteBoardDataSource:(NSMutableDictionary *)dataSource;
//TODO: 待确定 原始数据
- (void)setWhiteBoardDicAllDataSource:(NSMutableDictionary *)dicAllDataSource;
/// 设置白板是否可以缩放
- (void)setWhiteBoardZoomEnable:(BOOL)enable;

/// 设置白板是否可以拖动
- (void)setWhiteBoardZoomTapMoveEnabled:(BOOL)enable;

/// 刷新课件图片状态(使具有缩放,平移功能)
- (void)transferImageScale:(CGFloat)zoomScale offsetX:(CGFloat)offsetX offsetY:(CGFloat)offsetY;
/// 设置zoom content size
- (void)setZoomContentSize:(CGSize)size;
/// 获取zoom size
- (CGSize)getWhiteBoardZoomSize;
/// 重新布局zoom
- (void)whiteBoardZoomLayout;

@end

