//
//  SKRoomDeviceAlertView.h
//  SKDemo
//
//  Created by Yangsenkai on 2017/7/4.
//  Copyright © 2017年 yangsenkai. All rights reserved.
//

typedef NS_ENUM(NSInteger,YMRoomDeviceTestType) {
    YMRoomDeviceTestTypeMicro,
    YMRoomDeviceTestTypeCamera,
    YMRoomDeviceTestTypeWifi,
    YMRoomDeviceTestTypeStartTest,
     YMRoomDeviceTestTypeClose
};

#import <UIKit/UIKit.h>

typedef void(^YMRoomDeviceTestTypeCallBack)(YMRoomDeviceTestType type);

@interface YMRoomDeviceAlertView : UIView

+ (instancetype)roomDeviceAlertView;

- (void)showRoomDeviceAlertViewCallBack:(YMRoomDeviceTestTypeCallBack)callBack;

@end
