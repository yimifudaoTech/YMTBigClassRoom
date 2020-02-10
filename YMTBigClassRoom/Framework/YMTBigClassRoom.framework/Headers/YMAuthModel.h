//
//  YMAuthModel.h
//  YMTBigClassRoom
//
//  Created by mac on 2020/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 用户权限
typedef NS_OPTIONS(NSInteger, YMAuthName){
    YMAuthName_None          = 0,
    YMAuthName_Updown        = 1,
    YMAuthName_Trail         = 1 << 1,
    YMAuthName_DrawGraph     = 1 << 2,
    YMAuthName_DrawImage     = 1 << 3,
    YMAuthName_SelectMode    = 1 << 4,
    YMAuthName_Audio         = 1 << 5,
    YMAuthName_Video         = 1 << 6,
    YMAuthName_Erase         = 1 << 7,
    YMAuthName_ClassExercise = 1 << 8,
    YMAuthName_Evaluate      = 1 << 9
};

typedef NS_ENUM(NSInteger, YMAuthStatus) {
    YMAuthStatus_Enable = 0,
    YMAuthStatus_Interrupt = 1,
    YMAuthStatus_ShutDown = 2
};

@interface YMAuthModel : NSObject

@property (nonatomic,assign) YMAuthName authName;
@property (nonatomic,assign) YMAuthStatus authStatus;

@end

NS_ASSUME_NONNULL_END
