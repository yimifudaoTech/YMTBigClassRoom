//
//  YMTHTTPMacros.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/2/15.
//

#ifndef YMTHTTPMacros_h
#define YMTHTTPMacros_h

// 云教室环境定义
typedef NS_ENUM(NSUInteger, YMTRoomEnvironment) {
    YMTRoomEnvironment_Sit01,
    YMTRoomEnvironment_Sit02,
    YMTRoomEnvironment_Sit03,
    YMTRoomEnvironment_Sit04,
    YMTRoomEnvironment_Release,
};

typedef NS_ENUM(NSInteger, YMTHttpSessionManagerType) {
    YMTHttpSessionManagerTypeDefault = 0, // 默认
    YMTHttpSessionManagerTypeCustom
};

#endif /* YMTHTTPMacros_h */
