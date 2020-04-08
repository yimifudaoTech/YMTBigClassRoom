//
//  WhiteBoardView.h
//  YMWhiteBoardSDK
//
//  Created by mystarains on 2019/7/16.
//

#import <UIKit/UIKit.h>
#import "YMDrawTool.h"
#import "YMDrawTrailModel.h"
#import <YMUIkit/UIView+YMCaptureImage.h>

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMDrawEvent) {
    YMDrawEvent_Began = 0,
    YMDrawEvent_Move,
    YMDrawEvent_End
};

typedef void (^SplitTrailEndBlock)(YMDrawTrailModel *model);
typedef void (^RectagleStrokeEndBlock)(CGRect rect);
typedef void (^UpdateGraphBlock)(NSString *itemId, YMDrawGraphTool *graphTool);
typedef void (^ReloadImageBlock)(YMDrawImageTool * model);

@interface YMWhiteBoardView : UIView

@property (strong, nonatomic) NSMutableArray *dataSource;//轨迹数据源
@property (nonatomic, strong) NSMutableDictionary *shapeDataSource;//图形轨迹数据源

@property (nonatomic, strong) UIColor *lineColor;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) YMDrawToolType toolType;

@property(nonatomic, copy) SplitTrailEndBlock splitTrailEndBlock;//绘制结束回调
@property(nonatomic, copy) RectagleStrokeEndBlock rectagleStrokeEndBlock;//图形绘制回调（目前只有截图选择的矩形）
@property(nonatomic, copy) UpdateGraphBlock updateGraphBlock;//移动图形回调
@property(nonatomic, copy) void(^deleGraphBlock)(NSString *itemId, YMDrawGraphTool *tool);//删除图形回调
@property(nonatomic, copy) void(^selectGraphBlock)(NSString *itemId);//选择图形回调

@property (nonatomic, assign) CGPoint currentRatePoint;//比例点
@property (nonatomic, assign) WhiteBoardCursorViewType cursorType;
@property (nonatomic, copy) void(^cursorMoved)(CGFloat pointX,CGFloat pointY);
@property(nonatomic, copy) ReloadImageBlock reloadImageBlock;//重新加载图片回调
/**
 *  手写板事件
 */
- (void)handleTouchEvent:(int)event point:(CGPoint)point previous:(CGPoint)previous;
- (void)handlePendoSuspendedEvent:(CGPoint)point;
/**
 *  清空画笔
 */
- (void)clearTrails;

/**
 *  清空图形图片
 */
- (void)clearGraphs;

/**
 绘制圆

 @param model model description
 */
- (void)drawEllipseTrail:(YMDrawTuoCircleTool *)model;

/**
 绘制多边形

 @param model model description
 */
- (void)drawPolygonTrail:(YMDrawPolygonTool *)model;

/**
 绘制图片

 @param model model description
 */
- (void)drawImage:(YMDrawImageTool *)model;

/**
 移动图形
 
 @param graphTool graphTool description
 */
- (void)moveGraph:(YMDrawGraphTool *)graphTool;


/**
 删除图形图片
 
 @param itemId itemId description
 */
- (void)deleGraph:(NSString *)itemId deleteBySelf:(BOOL)flag;

@end

NS_ASSUME_NONNULL_END
