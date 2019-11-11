//
//  YMAuthorizationTool.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/25.
//

//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YMAuthorizationStatus) {
    YMAuthorizationStatusAuthorized = 0, //用户已授权
    YMAuthorizationStatusDenied,         //拒绝
    YMAuthorizationStatusRestricted,     //应用没有相关权限，且当前用户无法改变这个权限，如家长控制
    YMAuthorizationStatusNotSupport      //硬件等不支持
};

typedef NS_ENUM(NSUInteger, YMMediaType) {
    YMMediaTypeAlbum = 0,    //相册
    YMMediaTypeCamera,       //相机
    YMMediaTypeRecord       //麦克风
};

@interface YMAuthorizationTool : NSObject

/**
 请求相册访问权限
 @param callback  返回授权状态
 */
+ (void)requestImagepickerAuthorization:(void(^)(YMAuthorizationStatus status))callback;

/**
 请求相机权限
 @param callback 返回授权状态
 */
+ (void)requestCameraAuthorization:(void(^)(YMAuthorizationStatus status))callback;

/**
 请求录音权限
 @param callback 返回授权状态
 */
+ (void)requestRecordAuthorization:(void(^)(YMAuthorizationStatus status))callback;


@end

NS_ASSUME_NONNULL_END
