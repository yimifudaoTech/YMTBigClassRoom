//
//  YMTReaPackageItemView.h
//  AFNetworking
//
//  Created by SendomZhang on 2/9/2019.
//

#import <UIKit/UIKit.h>

@class YMTRedPackageItemView;

typedef void(^YMTRedPackageItemViewClick)(YMTRedPackageItemView * _Nullable item);

NS_ASSUME_NONNULL_BEGIN

@interface YMTRedPackageItemView : UIButton

/// 红包有两种状态：点开，未点开。 interval 代表红包被点开后多少秒消失， 如果是0 代表不自动消失
- (instancetype)initWithInterval:(NSTimeInterval)interval;

- (void)startAnimationToPoint:(CGPoint)point interval:(NSTimeInterval)interval;

- (void)updateNumOfRedPackage:(NSString *)str;

/// YMTRedPackageItemViewClick
@property (nonatomic, copy, readwrite) YMTRedPackageItemViewClick itemClick;

@end

NS_ASSUME_NONNULL_END
