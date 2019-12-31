//
//  YMProblemListPageView.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/11/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^clickProblemButtonBack)(BOOL isToast);

@interface YMProblemListPageView : UIView

@property (nonatomic, copy) clickProblemButtonBack clickProblemButtonBack;

- (void)createdProblemListPageView:(UIView *)view loadURL:(NSString *)loadURL;

@end

NS_ASSUME_NONNULL_END
