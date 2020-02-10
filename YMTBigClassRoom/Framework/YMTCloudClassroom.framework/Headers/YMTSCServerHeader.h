//
//  GPLSCServerHeader.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2018/11/23.
//  Copyright © 2018 YiMi. All rights reserved.
//

#ifndef YMTSCServerHeader_h
#define YMTSCServerHeader_h

typedef NS_ENUM(NSInteger, YMTSCCommandConvertType) {
    YMTSCCommandConvertTypeNone,
    YMTSCCommandConvertTypeEnterRoom,       //进入教室
    YMTSCCommandConvertTypeEnterFailed,     //进入教室失败
    YMTSCCommandConvertTypeACK,             //ack消息
    YMTSCCommandConvertTypeKickOut,         //踢出
    YMTSCCommandConvertTypeSynFin,          //同步完成
    YMTSCCommandConvertTypeUsersStatus,     //教室内成员状态
    YMTSCCommandConvertTypeExitRoom,        //退出教室
    YMTSCCommandConvertTypeStartClass,      //开始上课
    
    YMTSCCommandConvertTypeMuteAll,         // 静音
    YMTSCCommandConvertTypeAuth,            // 授权
    YMTSCCommandConvertTypePageContol,      // 翻页 1，加页 2， 删页 3
    YMTSCCommandConvertTypeCourseDoc,       // 文档课件
    YMTSCCommandConvertTypeCourseAudio,     // 音视频课件
    YMTSCCommandConvertTypeTrail,           // 画笔橡皮
    YMTSCCommandConvertTypeCursor,          // 教鞭
    YMTSCCommandConvertTypePageZoom,        // 滚动课件，放大缩小课件
    YMTSCCommandConvertTypeOperation,       // 清屏 撤销
    YMTSCCommandConvertTypeRandomRoll,      // 随机选人
    YMTSCCommandConvertTypeTobeFirstAnswer, // 开始抢答
    YMTSCCommandConvertTypeDoTimer,         // 计时
    YMTSCCommandConvertTypeReward,          // 奖励
    YMTSCCommandConvertTypeFinish,          // 结束课程
    YMTSCCommandConvertTypePlayAnimation,   // 播放当前页面的动画
    YMTSCCommandConvertTypeRedPackageRain,   // 开始抢红包
    YMTSCCommandConvertTypeRedPackageRainFinsh,   // 抢红包结束
    YMTSCCommandConvertTypeUpDown,           // 上下台
    YMTSCCommandConvertTypeQuestion,         // 答题器
    YMTSCCommandConvertTypeAnswerQuestion,   //发送答案
    YMTSCCommandConvertTypeDrawShape,        //绘制几何图形
    YMTSCCommandConvertTypeWindowUpdate,     //窗口更新
    YMTSCCommandConvertTypeImage,      //绘制图片
    YMTSCCommandConvertTypeH5Question, //H5结构化课件答题指令
};

#endif /* GPLSCServerHeader_h */
