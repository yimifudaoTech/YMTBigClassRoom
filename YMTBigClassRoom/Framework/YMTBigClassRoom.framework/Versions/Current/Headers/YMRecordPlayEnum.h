//
//  YMRecordPlayEnum.h
//  YiMiApp
//
//  Created by mystarains on 2019/8/21.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMRecordPlayEnum_h
#define YMRecordPlayEnum_h

/**
 *  播放器界面操作
 *
 */
typedef NS_ENUM(NSInteger, YMRecordPlayerViewClickType) {
    YMRecordPlayerViewClickTypeBack,
    YMRecordPlayerViewClickTypePlay,
    YMRecordPlayerViewClickTypePause,
    YMRecordPlayerViewClickTypeStop,
    YMRecordPlayerViewClickTypeProgressChange,
    YMRecordPlayerViewClickTypeAdjustRate,
};

/**
 *  解析层协议
 *
 */
typedef NS_ENUM(NSInteger, YMCommandConvertType) {
    YMCommandConvertTypeNone,
    /**
     *  教师端，学生端，控制选项
     */
    
    //control
    YMCommandConvertType_control_Magicface,//魔法表情
    YMCommandConvertType_control_ZoomInOut,//放大缩小
    YMCommandConvertType_control_Cursor,//教鞭
    YMCommandConvertType_control_FinishClass,//完成课程
    YMCommandConvertType_control_Settinginfo,//音视频设置信息
    YMCommandConvertType_control_AVControl,//播放器音视频控制
    YMCommandConvertType_control_ChangeAudioResponse,//学生端切换通道响应
    
    YMCommandConvertType_control_OpenAnswerParsing, //打开答案解析命令
    YMCommandConvertType_control_CloseAnswerParsing, //关闭答案解析命令
    YMCommandConvertType_control_OpenCorrect, //打开批改窗体 （学生，老师都可以发送）
    YMCommandConvertType_control_Correct, //批改命令（老师端发送,老师被抢麦后是接收）
    YMCommandConvertType_control_CloseCorrect, //关闭批改面板
    YMCommandConvertType_control_Network,
    YMCommandConvertType_control_CloseDoSyncAnswerBorad, // 老师关闭手写答题版
    YMCommandConvertType_control_OpenDoSyncAnswerBorad, // 老师打开手写答题版
    YMCommandConvertType_control_syncWriteReportFinished, // 填写课堂报告
    
    //auth
    YMCommandConvertType_auth_RequestAudioAuth,  // 申请麦克风权限
    YMCommandConvertType_auth_ResponseAudioAuth, // 响应申请麦克风权限
    YMCommandConvertType_auth_GotoPage,//翻页授权
    YMCommandConvertType_auth_GotoPageRequest,//请求翻页
    YMCommandConvertType_auth_ExitRequest,//请求推出教室
    YMCommandConvertType_auth_Exit,//退出授权
    YMCommandConvertType_auth_Control,//学生端操作授权
    YMCommandConvertType_auth_EnterRoomRequest,//B学生请求加入课堂
    YMCommandConvertType_auth_EnterRoom,//是否授权B加入课堂
    
    YMCommandConvertType_auth_FinishReq,//是否授权结束课程（学生使用）
    YMCommandConvertType_auth_FinishResp,//授权结束课程反馈（老师用）
    
    YMCommandConvertType_auth_SwitchMicrophone,//上麦老师填写试听课报告后转麦发送
    
    //draw
    YMCommandConvertType_draw_Trail,//橡皮画笔
    YMCommandConvertType_draw_Undo,//撤消
    YMCommandConvertType_draw_Redo,//反撤消
    YMCommandConvertType_draw_Clear,//清屏操作
    YMCommandConvertType_draw_Courware,//课件
    YMCommandConvertType_draw_Picture,//照片
    
    
    YMCommandConvertType_draw_Polygon, //多边形
    YMCommandConvertType_draw_Ellipse, //椭圆
    
    YMCommandConvertType_draw_AnswerQuestionTrack, // 学生教室内答题同步书写轨迹到老师的命令
    
    
    //3.0 教室新命令
    YMCommandConvertType_draw_LessonPlan, //新增点击讲义发送命令
    YMCommandConvertType_draw_Column, //新增点击栏目发送命令
    YMCommandConvertType_draw_Question, //新增发送练习题命令
    YMCommandConvertType_draw_QuestionAnswer, //新增提交练习题命令
    YMCommandConvertType_draw_AutoPicture, //新增传递自动转图片之后发送的讲义图片命令
    YMCommandConvertType_draw_StopQuestion, //老师结束练习命令
    YMCommandConvertType_draw_AnswerPicture, //学生提交答案图片
    YMCommandConvertType_draw_QuestionAnswerFailed, //学生提交答案失败
    
    YMCommandConvertType_draw_ImportReport, // 试听课导入课堂报告
    YMCommandConvertType_draw_ImportHomework, // 课堂作业导入课堂命令
    
    //page
    YMCommandConvertType_page_Goto,//跳到某一页
    YMCommandConvertType_page_Insert,//插入页
    YMCommandConvertType_page_Delete,//删除页
    YMCommandConvertType_page_playAnimation,//播放页面动画
    
    
    
    //server&&system
    YMCommandConvertTypeSynchronize,
    YMCommandConvertTypeOnlineState,
    YMCommandConvertTypeResponse,
    YMCommandConvertTypeEnterRoom,
    YMCommandConvertTypeExitRoom,
    YMCommandConvertTypeDisconnect,
    YMCommandConvertTypeStartClass,
    YMCommandConvertTypeStartFailed,//开始上课失败
    YMCommandConvertTypeEnterFailed,
    YMCommandConvertTypeStartPlay,
    YMCommandConvertTypeChangeCmd,  //切换服务器，语音，翻页
    YMCommandConvertTypeChangeKickOut,//在其他设备登录
    YMCommandConvertTypeChangeReLogin,//重新登录 UDP专用
    YMCommandConvertTypeTotalTime,//服务器返回的上课时间
    YMCommandConvertTypeException,//上课异常
    YMCommandConvertTypeC2CDelay,//QOSSDK
    YMCommandConvertTypeCurrentVideoSpanResponse, // 腾讯V2通道录播分段号返回
    
    //system
    YMCommandConvertTypeHeartBeat,
    YMCommandConvertTypeChangeAudio,
    YMCommandConvertTypeDeviceInfos,
    YMCommandConvertTypeAudioQuality,  //语音质量
    YMCommandConvertTypeServerDelay,   //网络延迟
    YMCommandConvertTypeHomePressed,   //按住home键推到后台
    YMCommandConvertTypeCurrentDelay,  //当前延时
    YMCommandConvertTypeStatistics,    //设备负载：cpu、内存、存储卡信息 deviceLoad 等收集日志相关
    YMCommandConvertTypeRequestCurrentVideoSpan, // 请求腾讯V2通道录播分段号
    
    // answer
    YMCommandConvertType_Answer_Sync,  // 同步做题的答案
    YMCommandConvertType_Answer_Undo,  // 手写板答题重新绘制
    YMCommandConvertType_Answer_Redo,  // 手写板答题撤销
    YMCommandConvertType_Answer_Clear  // 手写板答题清除
};


#endif /* YMRecordPlayEnum_h */
