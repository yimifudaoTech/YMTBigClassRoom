//
//  GPLPageControl.h
//  YiMiLib
//
//  Created by 顾鹏凌 on 2018/9/4.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
@class GPLPageControl;
@protocol GPLPageControlDelegate <NSObject>

-(void)gplPageControlClick:(GPLPageControl*)pageControl index:(NSInteger)clickIndex;

@end
@interface GPLPageControl : UIControl
/*
 分页数量
 */
@property(nonatomic) NSInteger numberOfPages;
/*
 当前点所在下标
 */
@property(nonatomic) NSInteger currentPage;
/*
 其他未选中点颜色
 */
@property(nonatomic,strong) UIColor *otherColor;
/*
 当前点颜色
 */
@property(nonatomic,strong) UIColor *currentColor;
/*
 当前点背景图片
 */
@property(nonatomic,strong) UIImage *currentBkImg;
@property(nonatomic,weak) id <GPLPageControlDelegate> delegate;
@end
