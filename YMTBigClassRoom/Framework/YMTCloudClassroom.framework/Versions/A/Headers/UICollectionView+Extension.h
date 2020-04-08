//
//  UICollectionView+Extension.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/11/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UICollectionView (Extension)

// 返回坐标位置范围内的所有indexPath
- (NSArray *)indexPathsForElementsInRect:(CGRect)rect;

@end

NS_ASSUME_NONNULL_END
