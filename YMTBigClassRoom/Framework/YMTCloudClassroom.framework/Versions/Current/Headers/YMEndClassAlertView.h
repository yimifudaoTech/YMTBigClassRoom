//
//  YMEndClassAlertView.h
//  AFNetworking
//
//  Created by mystarains on 2019/9/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMClassAlertType) {
    YMClassAlertTypeEndClass,
    YMClassAlertTypeKickOut,
    YMClassAlertTypeDisconnect,
};

@interface YMEndClassAlertView : UIView

- (instancetype)initWithFrame:(CGRect)frame type:(YMClassAlertType)type exit:(void(^)(void))exitBlock;


@end

NS_ASSUME_NONNULL_END
