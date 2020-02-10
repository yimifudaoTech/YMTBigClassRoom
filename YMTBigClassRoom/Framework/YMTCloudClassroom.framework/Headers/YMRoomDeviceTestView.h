//
//  SKRoomDeviceTestView.h
//  SKDemo
//
//  Created by Yangsenkai on 2017/7/4.
//  Copyright © 2017年 yangsenkai. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^YMRoomDeviceMicroCallBack)(BOOL finished);

@interface YMRoomDeviceTestView : UIView

+ (instancetype)roomDeviceTestView;

- (void)showRoomDeviceAlertViewSuccess:(YMRoomDeviceMicroCallBack)callBack;

+ (BOOL)checkMicroAuthorizationStatus;

@end
