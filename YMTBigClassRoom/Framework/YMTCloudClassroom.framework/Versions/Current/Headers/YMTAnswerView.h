//
//  YMTAnswerView.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/11.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YMTAnswerConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMTAnswerCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) UILabel *contentLabel;

@end

@interface YMTAnswerView : UIView

- (void)setItemId:(NSString *)itemId itemAnswer:(NSString *)itemAnswer optionList:(NSArray *)items countDownTime:(NSTimeInterval)interval result:(YMTAnswerResult)result;

- (void)stopAnswerWithItemId:(NSString *)itemId type:(YMAnswerType)type result:(YMTStopAnswerResult)result;

@end

NS_ASSUME_NONNULL_END
