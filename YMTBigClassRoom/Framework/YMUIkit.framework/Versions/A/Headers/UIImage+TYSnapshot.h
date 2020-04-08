//
//  UIImage+TYSnapshot.h
//  UITableViewSnapshotTest
//
//  Created by Tony on 2016/7/11.
//  Copyright © 2016年 TonyReet. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (TYSnapshot)

/**
*  拼接快照
*
*  @param imagesArr 快照的数组
*
*  @return 最终拼接的图片
*/
+ (UIImage *)getImageFromImagesArray:(NSArray *)imagesArr;

/**
根据scrollview截取长图
@param scrollView scrollerview 或者 tableview 或者 collectionView
@return 图片
*/
+ (UIImage *)snapImageFromScrollView:(UIScrollView *)scrollView;

@end
