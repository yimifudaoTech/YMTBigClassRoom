//
//  YMDrawTrailModel.h
//  YMWhiteBoardSDK
//
//  Created by mystarains on 2019/7/17.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMBoardBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMDrawTrailModel : YMBoardBaseModel

@property (assign, nonatomic) CGFloat width;
// 线宽类型 0 1 2 代表小 中 大
@property (copy, nonatomic) NSString *widthType;
//color为空代表橡皮
@property (strong, nonatomic, nullable) UIColor *color;
@property (strong, nonatomic) NSMutableArray<NSValue*> *pointArray;
@property (copy, nonatomic) NSString *offsetY;

@end

NS_ASSUME_NONNULL_END
