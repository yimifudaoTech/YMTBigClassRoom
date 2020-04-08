//
//  YMSystemInfo.h
//  YiMiApp
//
//  Created by xieyan on 15/9/25.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YMSystemInfo : NSObject

// 获取设备当前网络IP地址 不包含流量的
+ (NSString *)getIpAddresses;
// 获取设备当前网络IP地址 包含流量的
+ (NSString *)getIPAddress:(BOOL)preferIPv4;
+ (NSString *)getCarrierInfo;
+ (NSString *)getAppBuildVersion;//2202
+ (NSString *)getAppVersion;//2.2.2202
+ (NSString *)getDeviceModel;
+ (NSString *)fetchSSIDInfo;
+ (NSString *)getIDFA;  //QOSSDK

+ (NSString *)getSysInfo;
+ (NSString *)getTimeStemp;
//@"yyyy-MM-dd HH:mm:ss"
+ (NSString *)getNowTimeFor_Time;

/** 是否iPhoneX及以上设备 */
+ (BOOL)isAboveiPhoneX;
/** 获取当前的电池电量 */
+ (NSString *)getCurrentBatteryValue;
/** 获取是否正在充电（USB是否连接）  */
+ (BOOL)getChargingState;

@end
