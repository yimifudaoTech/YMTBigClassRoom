//
//  YMUIResponder+Router.h
//


#import <UIKit/UIKit.h>
#import "YMUIResponderEventProxy.h"

@interface UIResponder (YMRouter)

@property (nonatomic,strong) YMUIResponderEventProxy *eventProxy;

- (void)routerEventWithName:(NSString *)eventName userInfo:(NSDictionary *)userInfo;
- (NSDictionary *)appendParamToUserInfo:(NSDictionary *)userInfo;

@end
