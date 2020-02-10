//
//  YMTDeviceSettingView.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/21.
//  Copyright © 2019 zhangqian. All rights reserved.
//

typedef NS_ENUM(NSInteger,DeviceSettingType) {
    DeviceSettingTypeClose = 0,
    DeviceSettingTypeDeviceTest,
    DeviceSettingTypeTechnicalSupport,
    DeviceSettingTypeExitRoom
};

typedef NS_ENUM(NSInteger,DisplayModuleType) {
    DisplayModuleTypeAll = 0,
    DisplayModuleTypeMicAndCamera = 1,
    DisplayModuleTypeDevice = 2
};

#import <UIKit/UIKit.h>

typedef void(^DeviceSettingCallBack)(DeviceSettingType type);

NS_ASSUME_NONNULL_BEGIN

@interface YMTDeviceSettingView : UIView

+ (instancetype)deviceSettingView;

- (void)showDeviceSettingViewCallBack:(DeviceSettingCallBack)callBack displayModuleType:(DisplayModuleType )displayModuleType;


@end

NS_ASSUME_NONNULL_END
