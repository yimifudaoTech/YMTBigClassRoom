//
//  YMGraphicsView.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/10/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^clickGraphicsbButtonBack)(int index);

@interface YMGraphicsView : UIView

- (void)initUIRelation:(UIView *)view;

@property (nonatomic, copy) clickGraphicsbButtonBack clickButtonBack;

@property (nonatomic, assign) NSInteger selectedIndex;

@end

NS_ASSUME_NONNULL_END
