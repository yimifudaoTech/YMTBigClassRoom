//
//  XYCourseWareLayer.h
//  YiMiApp
//
//  Created by xieyan on 16/6/27.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMLargeImageView.h"

typedef void (^ChannelDataOtherCallBack)(int code, id data,id otherData);

@interface YMCourseWareLayer : UIView
@property (nonatomic, strong) UIImageView* imageview;
@property (copy, nonatomic) ChannelDataOtherCallBack failCallBack;
@property (nonatomic, strong) YMLargeImageView *largeImageView;
@property (nonatomic, assign) CGSize originSize;


// 适配16:9新增，课件的高度变化需要更新父容器scorollview的contentsize;
@property (nonatomic, copy) void(^coursewareFrameUpdateBlock)(CGSize);
@property (nonatomic, assign) CGFloat coursewareAspectRatio;
@property (nonatomic,assign) CGFloat courseWidth;

/**
 是否重置layer
 */
@property(nonatomic, assign) BOOL isResetting;

- (void)addCoursePicterFailBack:(ChannelDataOtherCallBack)fail;

//绘制网络图片
- (void)draw_picture:(NSString *)imageUrl;

//绘制已经下载好的图片
- (void)drawImage:(UIImage *)image;

#pragma mark -- 翻页动画
/**
 *  向后翻页动画
 */
-(void)pageTurnBackward;
/**
 *  向前翻页动画
 */
-(void)pageTurnForward;
@end
