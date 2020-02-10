//
//  YMLargeImageView.h
//  YiMiLib
//
//  Created by peanut on 2019/1/25.
//  Copyright © 2019年 YiMi. All rights reserved.
//

/* 接入备注
 * 老课件    非16:9 autoresizing = YMLargeImageAutoresizingOrigin
 * 结构化讲义 非16:9 autoresizing = YMLargeImageAutoresizingFixedRatio fixedRatio = 0.618
 * 结构化讲义 16:9 autoresizing = YMLargeImageAutoresizingHeight fixedRatio = 9/16
 * 老课件    16:9 autoresizing = YMLargeImageAutoresizingHeight fixedRatio = 9/16
 */
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, YMLargeImageAutoresizing) {
    YMLargeImageAutoresizingExactFit = 0, // 铺满，拉伸变形
    YMLargeImageAutoresizingHeight,       // 自适应高，图片加载完成后，会修改视图的高度
    YMLargeImageAutoresizingWidth,        // 自适应宽，图片加载完成后，会修改视图的宽度
    YMLargeImageAutoresizingFixedRatio,   // 按照自定的比例铺满，拉伸变形 ratio=H/W
    YMLargeImageAutoresizingOrigin        // 按照原图加载
};

typedef void(^YMLargeImageLoadFinished)(CGSize);

@interface YMLargeImageView : UIView

@property (nonatomic, assign) YMLargeImageAutoresizing autoresizing;

@property (nonatomic, copy) YMLargeImageLoadFinished loadFinishedBlock;
// 适配大图的比例 height / width
@property (nonatomic, assign) CGFloat fixedRatio;
// 原始视图大小
@property (nonatomic, assign) CGSize originSize;

/**
 加载网络大图
 @param tiledCount 瓦片的数量，使用默认的配置传0
 */
- (void)loadImageWithUrl:(NSString *)url tiledCount:(int)tiledCount;

/**
 加载本地大图
 @param tiledCount 瓦片的数量，使用默认的配置传0
 */
- (void)loadImageWithName:(NSString *)imageName tiledCount:(int)tiledCount;

- (void)loadImage:(UIImage *)image tiledCount:(NSUInteger)tiledCount;

/**
 从大图中截取小图 适用于offset!=CGPointZero
 @param rect 截取的区域，屏幕尺寸
 @param offset 偏移量，暂时只支持一个方向，x和y其中一个=0
 @return 截取后的图片
 */
- (UIImage *)cutImageFromRect:(CGRect)rect offset:(CGPoint)offset;

/**
 从大图中截取小图 适用于 offset= CGPointZero
 @param rect 截取的区域，屏幕尺寸
 @return 截取后的图片
 */
- (UIImage *)cutImageFromRect:(CGRect)rect;

- (void)adjustFrameWithFixedValue:(CGFloat)value;

- (void)cleanDraw;

@end

