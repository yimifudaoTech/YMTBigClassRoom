//
//  YMTCoursewareProtocol.h
//  YiMiLib
//
//  Created by Caffrey on 2019/5/21.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YMTCoursewareCallback.h"
#import "YMTCoursewareInfo.h"
#import "YMTCoursewarePageInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 课件系统的接口设计，详情请看Wiki：
 http://192.168.3.24:22233/pages/viewpage.action?pageId=5281657#id-%E4%BA%91%E6%95%99%E5%AE%A4%E6%8A%BD%E7%A6%BB%E6%A8%A1%E5%9D%97%E6%96%B9%E6%A1%88-2%EF%BC%89%E8%AF%BE%E4%BB%B6%E6%A8%A1%E5%9D%97
 */
@protocol YMTCoursewareProtocol <NSObject>

@required
/**
 当前课件视图

 @return 显示课件的视图
 */
- (UIView *)getCoursewareView;

/**
 课件加空白页
 */
- (void)addPage;

/**
 课件加图片页

 @param url 图片地址
 */
- (void)addImagePage:(NSString *)url;

/**
 课件减页
 */
- (void)delPage;

/**
 跳转到指定页

 @param pageIndex 页码
 */
- (void)goPage:(NSInteger)pageIndex;

/**
 课件滚动的offSet
 
 @param offset  页面scroll百分比的值
 */
- (void)setScrollOffset:(double)offset;

/**
 设置课件数据

 @param coursewareData 课件数据
 */
- (void)setCoursewareData:(YMTCoursewareInfo *)coursewareData;

/**
 截图，对当前课件进行截图

 @param rect 截图返回
 @return 截取的图片
 */
- (nullable UIImage *)screenshot:(CGRect)rect;

/**
 显示课件视图
 */
- (void)show;

/**
 隐藏课件视图
 */
- (void)hide;

/**
 获取当前页的信息

 @return 课件当前页面的信息
 */
- (nullable YMTCoursewarePageInfo *)getPageInfo;

/**
 设置是否能响应touch事件

 @param can 是否可以
 */
- (void)setCanTouch:(BOOL)can;

/**
 播放当前页面动画

 @param step 播放到第几步
 */
- (void)playAnimation:(NSInteger)step;

/**
 H5结构化课件课堂练习 答题指令
 */
@optional
- (void)sendDataToCourseware:(NSDictionary *)content;

/**
 销毁
 */
- (void)destroy;

/**
 回调
 */
@property(nonatomic, weak) id<YMTCoursewareCallback> callback;

@end

@protocol YMTCoursewareReceiveDataDelegate <NSObject>

/**
 接收到JS发送消息
 */
@optional
- (void)receiveDataFromCourseware:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
