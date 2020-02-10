//
//  YMFloatButton.h
//  AFNetworking
//
//  Created by yimi on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import <UIkit/UIkit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^YMFloatButtonOnClick)(void);

@interface YMFloatButton : UIView
@property (nonatomic, copy)YMFloatButtonOnClick onClickCallback;
@property (nonatomic, copy)UIImage *backgroundImage;
@end

NS_ASSUME_NONNULL_END
