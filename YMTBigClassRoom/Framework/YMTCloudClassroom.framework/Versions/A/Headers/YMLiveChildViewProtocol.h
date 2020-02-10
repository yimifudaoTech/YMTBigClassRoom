//
//  YMLiveChildViewProtocol.h
//  YMTCloudClassroom
//
//  Created by mac on 2019/10/24.
//


#import "YMLiveViewConfig.h"

#ifndef YMLiveChildViewProtocol_h
#define YMLiveChildViewProtocol_h

@protocol YMLiveChildViewProtocol <NSObject>

- (UIView *)getCanvasView;

- (void)setRoleType:(YMLiveRoleType)roleType;

- (void)setVolume:(CGFloat)volume;

- (void)setMicState:(YMLiveUserMicState)micState;

- (void)setUserCameraStatus:(YMLiveUserCameraState)userCameraStatus;

- (void)setUserName:(NSString *)name;

@end





#endif /* YMLiveChildViewProtocol_h */
