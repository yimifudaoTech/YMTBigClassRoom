//
//  SKRoomDeviceTestCameraView.h
//  SKDemo
//
//  Created by Yangsenkai on 2017/7/4.
//  Copyright © 2017年 yangsenkai. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^YMRoomDeviceCameraCallBack)(BOOL finished);

@interface YMRoomDeviceTestCameraView : UIView

@property (weak, nonatomic) IBOutlet UIView *viewVedio;

+ (instancetype)roomDeviceTestCameraView;

- (void)showRoomDeviceAlertViewSuccess:(YMRoomDeviceCameraCallBack)callBack;

+ (BOOL)checkCameraAuthorizationStatus;

@end
