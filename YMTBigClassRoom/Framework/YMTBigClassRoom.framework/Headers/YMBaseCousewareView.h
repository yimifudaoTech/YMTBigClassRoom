//
//  YMBaseCousewareView.h
//


#import <UIKit/UIKit.h>
#import "YMNativeCourseWare.h"
#import <YMTCloudClassroom/YMTCoursewareInfo.h>

@interface YMBaseCousewareView : UIView
@property(nonatomic, strong) YMNativeCourseWare * _Nullable nativeCourseWare;
@property(nonatomic, assign) BOOL is16_9version;
 
- (void)showCourseWare:(YMTCoursewareInfo * _Nonnull)courseWareInfo;

- (void)refreshSubViewFrame:(CGRect)frame;

@end
