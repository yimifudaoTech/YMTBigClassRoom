//
//  YMDrawGraphModel.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/24.
//

#import <Foundation/Foundation.h>
#import "YMBoardBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMDrawGraphType) {
    YMDrawGraphType_Polygon, //多边形
    YMDrawGraphType_Ellipse, //椭圆
    YMDrawGraphModel_Image
};

@interface YMDrawGraphModel : YMBoardBaseModel

@property (nonatomic, assign) YMDrawGraphType type;
@property (nonatomic, assign) CGFloat rectX;
@property (nonatomic, assign) CGFloat rectY;
@property (nonatomic, assign) CGFloat rectWidth;
@property (nonatomic, assign) CGFloat rectHeight;
@property (nonatomic, assign) CGFloat angle;
@property (nonatomic, copy) NSString *color;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, strong) NSMutableArray<NSValue*> *pointArray;

@end

NS_ASSUME_NONNULL_END
