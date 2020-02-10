//
//  YMTRedPackageTool.h
//  AFNetworking
//
//  Created by SendomZhang on 2/9/2019.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTRedPackageTool : NSObject

+ (void)showPackageWithCountDown:(int)interval rainInterval:(NSTimeInterval)rainInterval URL:(NSString *)url param:(NSDictionary *)param result:(void(^)(void))reault autoRemove:(BOOL)autoRemove;

+ (void)showPackageRankViewWith:(NSString *)url param:(NSDictionary *)dic;

+ (void)hiddenPackageRankView;

+ (void)hiddenPackage;

@end

NS_ASSUME_NONNULL_END
