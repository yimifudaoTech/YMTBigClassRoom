//
//  YMBoardWindow.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/12/26.
//

#import <UIKit/UIKit.h>
#import "YMSuspendView.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^YMBoardWindowFrameChangeCallback)(CGRect frame);

@interface YMBoardWindow : YMSuspendView

@property (nonatomic, strong) NSString *boardID;

@property (nonatomic, copy) YMBoardWindowFrameChangeCallback frameChangeCallback;

- (void)updateWindowFrame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
