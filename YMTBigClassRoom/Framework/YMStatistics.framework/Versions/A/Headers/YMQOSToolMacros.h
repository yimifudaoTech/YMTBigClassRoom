//
//  YMQOSToolMacros.h
//  YMPingbackSDK
//
//  Created by yimi on 2019/5/28.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMQOSToolMacros_h
#define YMQOSToolMacros_h


//定义投递接口
#define URL_QOS_PROTOBUF @"https://galaxy-bp-prod.yimifudao.com/buryPoint/ios"
//教室信息字端名定义
#define QOS_KEY_LESSONID @"lessonId"
#define QOS_KEY_LESSONTYPE @"lessonType"
#define QOS_KEY_SERVERIP @"serverIp"
#define QOS_KEY_USERIP @"userIp"
#define QOS_KEY_USERID @"userID"
#define QOS_KEY_USERTYPE @"usertype"
#define QOS_KEY_CLASSTYPE @"classType"



/**
 定义公司类型
 
 - QOS_COMPANY_DEFAULT: 默认值
 - QOS_COMPANY_YIMI: 溢米
 - QOS_COMPANY_JUREN: 巨人
 */
typedef NS_ENUM(int32_t, QOS_COMPANY) {
    QOS_COMPANY_DEFAULT = 0,
    QOS_COMPANY_YIMI = 1,
    QOS_COMPANY_JUREN = 2,
    QOS_COMPANY_JRONLINE = 3
};



/** 课程类型 */
typedef NS_ENUM(int32_t, QOS_LESSONTYPE) {
    
    QOS_LESSONTYPE_DEFAULT = 0,
    
    /** 试听课 */
    QOS_LESSONTYPE_AUDITION = 1,
    
    /** 正常课 */
    QOS_LESSONTYPE_ORDER = 2,
    
    /** 标准试听课 */
    QOS_LESSONTYPE_AUDITION_U = 3,
    
    /** 普通试听课 */
    QOS_LESSONTYPE_AUDITION_N = 4,
};


/** 日志类型 */
typedef NS_ENUM(int32_t, QOS_LOGTYPE) {
    QOS_LOGTYPE_DEFAULT = 0,
    /** 点击 */
    QOS_LOGTYPE_CLICK = 1,
    
    /** 页面跳转 */
    QOS_LOGTYPE_PV = 2,
    
    /** 上课心跳信息 */
    QOS_LOGTYPE_HEARTBEAT = 3,
    
    /** 对应APP级别日志，启动崩溃等 */
    QOS_LOGTYPE_APP = 4,
    
    /** 页面刷新 */
    QOS_LOGTYPE_REFRESH = 5,
    
    /** 搜索 */
    QOS_LOGTYPE_SEARCH = 6,
};


/** 用户类型 */
typedef NS_ENUM(int32_t, QOS_USERTYPE) {
    QOS_USERTYPE_DEFAULT = 0,
    QOS_USERTYPE_STU = 1,
    QOS_USERTYPE_TEA = 2,
    QOS_USERTYPE_CC = 3,
    QOS_USERTYPE_CR = 4,
    QOS_USERTYPE_AUDIT = 5,
};

typedef NS_ENUM(int32_t, QOS_CLASSTYPE) {
    QOS_CLASSTYPE_1V1 = 1,
    QOS_CLASSTYPE_1VN = 2,
    QOS_CLASSTYPE_1V6 = 3,
    QOS_CLASSTYPE_UNKNOWN = 4
    
 
};


#endif /* YMQOSToolMacros_h */
