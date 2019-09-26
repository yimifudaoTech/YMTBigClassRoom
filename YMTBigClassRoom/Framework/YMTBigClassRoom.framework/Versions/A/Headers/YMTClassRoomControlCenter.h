//
//  YMTClassRoomControCenter.h
//  student
//
//  Created by SendomZhang on 12/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>


#import <YMTCloudClassroom/YMWhiteBoardModule.h>
//#import <YMWhiteBoard/XYZDrawTool.h>
//#import <YMWhiteBoard/XYDrawLayer.h>
//#import <XYZRoom/XYZRoomProtocols.h>
//#import <YMWhiteBoard/XYZCursorView.h>

#import <YMTCloudClassroom/YMTSCServerHeader.h>
#import <YMTCloudClassroom/YMTCourseWareModel.h>
#import <YMTCloudClassroom/YMTRoomProtocols.h>

@class XYCourseWareLayer;
@class YMBigClassViewForGroupRoom;
@class SCAgoraDomainModel;
@class GPLSCEntityDatas;
@class SCServerIpModel;
@class YMTSCSendMsgEntity;

@protocol YMTClassRoomControlCenterDelegate;

typedef void(^YMTCCIMModuleCallBlock)(void);

typedef NS_ENUM(NSInteger,YMTControlCenterConnectResult) {
    YMTControlCenterConnectResultSuccess,    // 链接成功
    YMTControlCenterConnectResultFail,       // 链接失败
    YMTControlCenterConnectResultEnd,        // 链接结束
    YMTControlCenterConnectResultRepeat      // 重新链接
};

@interface YMTClassRoomControlCenter : NSObject

/// classRoom ControlCenter Delegate
@property (nonatomic, weak, readwrite) id <YMTClassRoomControlCenterDelegate> delegate;

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

/// IM相关操作

@interface YMTClassRoomControlCenter (IM)

/// 初始化IM模块
- (void)IMInitSocketControllerWithDNSIPList:(NSArray *)dnsIPList domain:(SCAgoraDomainModel *)domain liveRoomID:(NSString *)liveRoomID uid:(NSString *)uid;

/// 销毁IM模块
- (void)IMdestroy;

/// 获取当前使用的IP
- (NSString *)IMGetCurrentIP;

//TODO:???
- (void)IMstartTimeOut:(YMTCCIMModuleCallBlock)callBack;

/// 发送消息至server
- (void)IMSendSocketContext:(NSDictionary *)sendContext type:(YMTSCCommandConvertType)type;

//TODO:???
- (void)IMStopTimeOut;

/// 断开链接
- (void)IMDisconnect;

/// 同步消息
- (void)IMAsyncSeverDataWithComplete:(void (^)(BOOL isSuccess))completionBlock;

@end

@protocol YMTClassRoomControlCenterDelegate <NSObject>

@required

/**
 获取服务端消息
 
 @param controlCenter 管理类
 @param context 消息管理模型。所有数据
 @param isRealTime 实时/同步 消息
 */

- (void)controlCenter:(YMTClassRoomControlCenter *)controlCenter
            context:(YMTSCSendMsgEntity *)context
         isRealTime:(BOOL)isRealTime;


/**
 发送的消息服务端已收到
 
 @param controlCenter 管理类
 @param context 服务端收到的消息
 */
- (void)controlCenter:(YMTClassRoomControlCenter *)controlCenter
    realSendContext:(YMTSCSendMsgEntity *)context;


/**
 同步回调
 
 @param controlCenter 管理类
 @param isSyncDone 是否同步完成
 */
- (void)controlCenter:(YMTClassRoomControlCenter *)controlCenter
         isSyncDone:(BOOL)isSyncDone;

@optional

/**
 连接状态变化
 
 @param controlCenter 管理类
 @param connectModel 当前IP
 @param connectResult 连接状态
 */
- (void)controlCenter:(YMTClassRoomControlCenter *)controlCenter
       connectModel:(SCServerIpModel *)connectModel
      connectResult:(YMTControlCenterConnectResult)connectResult;

/**
 重连IP上报
 
 @param controlCenter 管理类
 @param connectModel 重连IP
 */
- (void)controlCenter:(YMTClassRoomControlCenter *)controlCenter
  reportReconnectIp:(SCServerIpModel *)connectModel;

@end

