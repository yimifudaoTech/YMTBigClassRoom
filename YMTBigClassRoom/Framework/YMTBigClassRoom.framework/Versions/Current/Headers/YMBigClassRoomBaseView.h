//
//  YMBigClassRoomBaseView.h
//  TestCloudClassRoom
//
//  Created by 顾鹏凌 on 2018/1/29.
//  Copyright © 2018年 顾鹏凌. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMBigClassViewForGroupRoom.h"

typedef NS_ENUM(NSInteger, YMTGroupRoomViewPageControlOperation) {
    YMTGroupRoomViewPageControlOperation_None = 0,
    YMTGroupRoomViewPageControlOperation_Turn,
    YMTGroupRoomViewPageControlOperation_Add,
    YMTGroupRoomViewPageControlOperation_Delete
};

typedef NS_ENUM(NSInteger, YMTGroupRoomViewOperation) {
    YMTGroupRoomViewOperation_None = 0,
    YMTGroupRoomViewOperation_TrailClean,
    YMTGroupRoomViewOperation_TrailRevoke,
    YMTGroupRoomViewOperation_delete
};

@interface YMBigClassRoomBaseView : UIView
@property(nonatomic, strong) YMBigClassViewForGroupRoom *nowRoom;
@property(nonatomic, assign) YMTUserStatusKindType userStatusType;
@property(nonatomic, strong) NSMutableArray *arrViews;
@property(nonatomic, assign) BOOL is16_9version;
@property(nonatomic, assign) BOOL isFullScreen;
@property(nonatomic, assign) BOOL isResetting;

//@property (nonatomic, strong) NSMutableArray *arrData;
/**
 添加group room
 
 @param key 标记id
 */
- (void)addGroupIdViewIdView:(NSString *)key
           drawLayerDelegate:(id<YMWhiteBoardDelegate>)delegate
                 cursorPoint:(void (^)(CGFloat pointX, CGFloat pointY))cursorPoint
                   zoomInOut:(void (^)(CGFloat zoomScale, CGFloat offsetX, CGFloat offsetY))zoomInOut
               didScrollView:(void (^)(UIScrollView *scrollView))didScrollView
                 refreshPage:(void (^)(id<YMTRoomDataProtocol> DB, NSMutableDictionary *drawData, NSMutableDictionary *drawOldData, YMTCourseWareModel *courseWare))refreshPage;

- (void)isSamllClass:(BOOL)smallClass;

// 页码控制
- (void)controlPage:(NSInteger)pageIndex key:(NSString *)docId controlType:(NSInteger)type;
- (void)addPageAtIndex:(NSInteger)pageIndex toView:(YMBigClassViewForGroupRoom *)roomView;
- (void)deletePageAtIndex:(NSInteger)pageIndex toView:(YMBigClassViewForGroupRoom *)roomView;
- (void)turnPageToIndex:(NSInteger)pageIndex toView:(YMBigClassViewForGroupRoom *)roomView;

// 画笔清除撤销
- (void)handleOperationWithParams:(NSDictionary *)params;

// 滚动条控制
- (void)scrolltoPercent:(CGFloat)percent;
- (void)zoomEvent:(NSDictionary *)config;

- (YMBigClassViewForGroupRoom *)groupRoomViewWithKey:(NSString *)key;

@end
