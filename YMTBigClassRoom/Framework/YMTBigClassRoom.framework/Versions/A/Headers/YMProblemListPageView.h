//
//  YMProblemListPageView.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/11/13.
//

typedef NS_ENUM(NSInteger,YMProblemListType) {
    YMProblemListTypeStudentNoSound,
    YMProblemListTypeTeacherNoSound,
    YMProblemListTypeTeacherCantSeeVideo,
    YMProblemListTypeStudentsCantSeeVideo,
    YMProblemListTypeCoursewareNoPage,
    YMProblemListTypeCaton
};

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^clickProblemButtonBack)(YMProblemListType problemType, NSString *problemContent);

@interface YMProblemListPageView : UIView

@property (nonatomic, copy) clickProblemButtonBack clickProblemButtonBack;

- (void)createdProblemListPageView:(UIView *)view ;

@end

NS_ASSUME_NONNULL_END
