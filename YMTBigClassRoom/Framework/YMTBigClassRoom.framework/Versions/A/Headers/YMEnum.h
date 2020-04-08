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
     * SDK接口调用成功
     */
    YMRoomErrorCode_MethodCall_Success = 0,
    /**
     * SDK接口调用错误：未知错误
     */
    YMRoomErrorCode_MethodCall_Unknown = 1,
    /**
     * SDK接口调用错误：没有初始化
     */
    YMRoomErrorCode_MethodCall_Not_Initialized = 2,
    /**
     * SDK接口调用错误：参数错误
     */
    YMRoomErrorCode_MethodCall_Bad_Parameters = 3,
    /**
     * SDK接口调用错误：教室状态错误
     */
    YMRoomErrorCode_MethodCall_Room_StateError = 4,
    /**
     * SDK通用错误码：成功
     */
    YMRoomErrorCode_Common_Success = 100,
    /**
     * SDK通用错误码：未知错误
     */
    YMRoomErrorCode_Common_UnknownError = 101,
    /**
     * SDK通用错误码：网络错误
     */
    YMRoomErrorCode_Common_NetworkError = 102,
    /**
     * SDK通用错误码：机构ID不匹配
     */
    YMRoomErrorCode_Common_AppIdNotMatch = 103,
    /**
     * 进入教室错误：未知错误
     */
    YMRoomErrorCode_JoinRoom_UnknownError = 1000,
    /**
     * 进入教室错误：ip列表获取失败
     */
    YMRoomErrorCode_JoinRoom_GetServerIPListFail = 1001,
    /**
     * 进入教室错误：domain信息获取失败
     */
    YMRoomErrorCode_JoinRoom_GetDomainInfoFail = 1002,
    /**
     * 进入教室错误：教室信息获取失败
     */
    YMRoomErrorCode_JoinRoom_GetRoomInfoFail = 1003,
    /**
     * 进入教室错误：房间不存在
     */
    YMRoomErrorCode_JoinRoom_RoomNotExist = 1004,
    /**
     * 进入教室错误：课程已结束
     */
    YMRoomErrorCode_JoinRoom_RoomHasFinished = 1005,
    /**
     * 进入教室错误：非法用户
     */
    YMRoomErrorCode_JoinRoom_InvalidUserId = 1006,
    /**
     * 进入教室错误：socket连接超时
     */
    YMRoomErrorCode_JoinRoom_SocketConnectTimeout = 1007,
    /**
     * 进入教室错误：指令同步失败
     */
    YMRoomErrorCode_JoinRoom_SocketCommandSyncFail = 1008,
    /**
     * 进入教室错误：enterRoom指令失败
     */
    YMRoomErrorCode_JoinRoom_SocketEnterRoomFail = 1009,
    
    /**
     * 查看录播：未知错误
     */
    YMRoomErrorCode_PlayRecord_UnknownError = 2000,
    /**
     * 查看录播：获取录播信息失败
     */
    YMRoomErrorCode_PlayRecord_GetRecordPlayInfoFail = 2001,
    /**
     * 查看录播：轨迹文件下载失败
     */
    YMRoomErrorCode_PlayRecord_DownloadTrailFileFail = 2002,
    /**
     * 查看课件：未知错误
     */
    YMRoomErrorCode_CheckCourseware_UnknownError = 3000,
    /**
     * 查看课件：获取课件信息失败
     */
    YMRoomErrorCode_CheckCourseware_GetCourseListFail = 3001,
    /**
     * 教室内错误：未知错误
     */
    YMRoomErrorCode_InRoom_UnknownError = 4000,
    /**
     * 教室内错误：用户被踢掉
     */
    YMRoomErrorCode_InRoom_UserKickOut = 4001,
    /**
     * 教室内错误：Socket掉线
     */
    YMRoomErrorCode_InRoom_SocketTimeout = 4002,
    /**
     * 获取课堂评价配置信息失败
    */
    YMRoomErrorCode_InRoom_GetCommentConfigFail = 4200,
    /**
     * 提交课堂评价失败
    */
    YMRoomErrorCode_InRoom_SubmitCommentFail = 4201,
    /**
     *用户关闭课堂评价
    */
    YMRoomErrorCode_InRoom_UserCloseComment = 4202,
    /**
     * 获取Token失败
     */
    YMRoomErrorCode_LoginFail = 5000,
};

// 角色
typedef NS_ENUM(NSInteger, YMRoleType) {
    YMRoleTypeTeacher = 1,
    YMRoleTypeStudent = 2,
    YMRoleTypeTeacherAide = 3,
    YMRoleTypeAudit = 4
};

#endif /* YMEnum_h */
