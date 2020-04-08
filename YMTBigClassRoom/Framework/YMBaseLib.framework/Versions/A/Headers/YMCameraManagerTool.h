//
//  YMCameraManagerTool.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/2/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMCameraManagerTool : NSObject

+ (instancetype)shareCameraManager;
/** 是否横屏 默认为NO*/
@property (nonatomic,assign) BOOL landscapeRight;

- (void)showCameraCompletion:(void(^)(UIImage *image))completion;

@end

NS_ASSUME_NONNULL_END
