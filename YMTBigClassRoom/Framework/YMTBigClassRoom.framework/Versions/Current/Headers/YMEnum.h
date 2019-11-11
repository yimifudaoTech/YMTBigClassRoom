//
//  YMEnum.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/11/3.
//

#ifndef YMEnum_h
#define YMEnum_h

// 云教室错误码定义
// YMTRoomInfoCode:错误定义
typedef NS_ENUM(NSUInteger, YMTRoomInfoCode) {
    /**
     * 成功
     */
    YMTRoomInfoCodeSuccess,
    /**
     * 登录失败
     */
    YMTRoomInfoCodeLoginFailed = 100,
    /**
     * 进入房间失败
     */
    YMTRoomInfoCodeJoinRoomFailed = 101,
    /**
     * 房间秘钥错误
     */
    YMTRoomInfoCodeRoomSecretError = 102,
    /**
     * token 失效
     */
    YMTRoomInfoCodeTokenInvalid = 201,
    /**
     * 录播文件下载失败
     */
    YMTRoomInfoCodeRecord_File_Download_Failed = 301,
    /**
     * 课件获取失败
     */
    YMTRoomInfoCodeFetch_Courseware_Failed = 401
};

// 云教室环境定义
typedef NS_ENUM(NSUInteger, YMTRoomEnvironment) {
    YMTRoomEnvironment_Sit01,
    YMTRoomEnvironment_Sit02,
    YMTRoomEnvironment_Sit03,
    YMTRoomEnvironment_Sit04,
    YMTRoomEnvironment_Release,
};

#endif /* YMEnum_h */
