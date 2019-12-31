//
//  YMUIResponderEventProxy.h
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface YMUIResponderEventProxy : NSObject

- (instancetype)initWithResponder:(UIResponder *)responder;

- (void)handleEvent:(NSString *)eventName userInfo:(NSDictionary *)userInfo;
- (void)registerEvent:(SEL)selector eventName:(NSString *)eventName;

@end
