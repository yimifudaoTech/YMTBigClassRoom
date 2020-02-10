//
//  YMTDeviceTestManager.h
//  YMTBigClassRoom_Example
//
//  Created by mystarains on 2019/9/21.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YMTCloudClassroom/YMTDeviceSettingView.h>
#import <YMTCloudClassroom/YMRoomDeviceAlertView.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTDeviceTestManager : NSObject

@property (nonatomic, assign) DisplayModuleType displayModuleType;

+ (instancetype)shareManager;

- (void)setDetectAddress:(NSString *)detectAddress;

- (void)showDeviceTestAlertCallBack:(YMRoomDeviceTestTypeCallBack)callBack;

- (void)showDeviceSettingViewCallBack:(DeviceSettingCallBack)callBack;

- (void)showDeviceTestType:(YMRoomDeviceTestType)type finish:(void(^)(BOOL finished))callBack;

@end

NS_ASSUME_NONNULL_END
