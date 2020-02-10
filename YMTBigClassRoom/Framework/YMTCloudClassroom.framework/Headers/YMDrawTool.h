//
//  YMDrawTool.h
//  YMWhiteBoardSDK
//
//  Created by mystarains on 2019/7/16.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMWhiteBoardEnum.h"
#import "YMTextLayer.h"
#import "YMKPITrack.h"

#if __has_feature(objc_arc)
#define ACE_HAS_ARC 1
#define ACE_RETAIN(exp) (exp)
#define ACE_RELEASE(exp)
#define ACE_AUTORELEASE(exp) (exp)
#else
#define ACE_HAS_ARC 0
#define ACE_RETAIN(exp) [(exp) retain]
#define ACE_RELEASE(exp) [(exp) release]
#define ACE_AUTORELEASE(exp) [(exp) autorelease]
#endif

// 定义教室内线宽 小 中 大
#define lineWidthSmall  @"1"
#define lineWidthMiddle @"4"
#define lineWidthBig    @"8"

@protocol YMDrawTool <NSObject>

@property (nonatomic, strong) UIColor *lineColor;
@property (nonatomic, assign) CGFloat lineAlpha;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) NSUInteger order_num;
@property (nonatomic, copy) NSString *itemId;
@property (nonatomic, assign) CGFloat boardViewWidth;
@property (nonatomic, assign) CGFloat boardViewHeight;

@optional
- (void)setInitialPoint:(CGPoint)firstPoint;
- (void)moveFromPoint:(CGPoint)startPoint toPoint:(CGPoint)endPoint;
- (void)setPolygonPoints:(NSArray *)pointsArr;
- (void)setTuoCircleRectX:(CGFloat)rectX rectY:(CGFloat)rectY rectWidth:(CGFloat)rectWidth rectHeight:(CGFloat)rectHeight angle:(CGFloat)angle;
- (void)draw;
- (void)drawInContext:(CGContextRef)ctx;

@end

#pragma mark -

@interface YMDrawToolFactory : NSObject

+ (id<YMDrawTool>)toolWithCurrentSettings:(YMDrawToolType)drawType;

@end

#pragma mark -

@interface YMDrawPenTool : UIBezierPath<YMDrawTool>
{
    CGMutablePathRef path;
}

- (CGRect)addPathPreviousPreviousPoint:(CGPoint)p2Point withPreviousPoint:(CGPoint)p1Point withCurrentPoint:(CGPoint)cpoint;

@end

#pragma mark -

@interface YMDrawEraserTool : YMDrawPenTool

@end

#pragma mark -

@interface YMDrawLineTool : NSObject<YMDrawTool>

@end

#pragma mark -

@interface YMDrawRectangleTool : NSObject<YMDrawTool>

@property (nonatomic, assign) BOOL fill;

@end

#pragma mark -

@interface YMDrawEllipseTool : NSObject<YMDrawTool>

@property (nonatomic, assign) BOOL fill;

@end


#pragma mark -

@interface YMDrawGraphTool  : NSObject<YMDrawTool>

@property (nonatomic, assign) BOOL fill;

@property (nonatomic, strong) CAShapeLayer *pathLayer;
@property (nonatomic, strong) CAShapeLayer *borderLayer;

- (CGRect)getCurrentRect;

- (CALayer *)refreshLayer;

@end


#pragma mark -

@interface YMDrawPolygonTool  : YMDrawGraphTool
// 点数组
@property (nonatomic, strong) NSArray *pointsArr;

@end

#pragma mark -

@interface YMDrawTuoCircleTool  : YMDrawGraphTool

@property (nonatomic, assign) CGFloat rectx;
@property (nonatomic, assign) CGFloat recty;
@property (nonatomic, assign) CGFloat rectWidth;
@property (nonatomic, assign) CGFloat rectHeight;
@property (nonatomic, assign) CGFloat angle;

@end

#pragma mark -

@interface YMDrawImageTool  : YMDrawGraphTool

@property (nonatomic, copy) NSString *url;

@property (nonatomic, strong) UIImage *image;

@property (nonatomic, assign) CGFloat rectx;
@property (nonatomic, assign) CGFloat recty;
@property (nonatomic, assign) CGFloat rectWidth;
@property (nonatomic, assign) CGFloat rectHeight;

@property (nonatomic, strong) CALayer *imageLayer;
// 图片加载状态以及结果提示图层
@property (nonatomic, strong) YMTextLayer *textLayer;
@property (nonatomic, copy) NSString *textLayerString;
@property (nonatomic, assign)YMDrawImageToolLoadingType loadingType;

- (void)setRectX:(CGFloat)rectX rectY:(CGFloat)rectY rectWidth:(CGFloat)rectWidth rectHeight:(CGFloat)rectHeight;

@end

