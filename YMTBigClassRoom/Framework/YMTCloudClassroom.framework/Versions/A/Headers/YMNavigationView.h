//
//  YMNavigationView.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMNavigationViewType) {
    YMNavigationViewSelectAlbumType,    //相册
    YMNavigationViewListType,           //课件列表
    YMNavigationViewDetailType,         //课件详情
};

typedef NS_ENUM(NSUInteger, YMNavigationActionType) {
    YMNavigationBackActionType,         //返回
    YMNavigationRightButtonActionType,  //右侧按钮事件
};
@interface YMNavigationView : UIView

- (instancetype)initNavigationViewWithFrame:(CGRect)frame navigationViewType:(YMNavigationViewType)type callBack:(void(^)(YMNavigationActionType actionType))callBack;

+ (CGFloat)navigationBarHeight;

@property (nonatomic,copy) NSString * title;
// 相册
@property (nonatomic,assign)BOOL enableStatus;

@end

NS_ASSUME_NONNULL_END
