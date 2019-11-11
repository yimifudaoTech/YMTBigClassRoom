//
//  HttpDataModels.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2016/10/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//

//#import <JsonExchangeModel/JsonExchangeModel.h>
#import "MCDownloadManager.h"

@interface IPModel : NSObject
@property (nonatomic, copy) NSString *ip;
@property (nonatomic, copy) NSString *port;
@property (nonatomic, copy) NSString *udpPort;
@property (nonatomic, assign) BOOL isTCPUsed;
@property (nonatomic, strong) NSMutableDictionary *dicPingResult;
@end

/**
 问题类型和紧急程度的item
 */
@interface SelectMenuItemModel : NSObject
@property (nonatomic, copy) NSString *name;
@end

/**
 问题类型和紧急程度
 */
@interface SelectMenuModel : NSObject
@property (nonatomic, strong) NSArray *urgencyLevel;//存放字典key name
@property (nonatomic, strong) NSArray *questionType;//存放字典key name
@property (nonatomic, copy)   NSString *desc;
@end

/**
 获取技术支持电话
 */
@interface TeachSupportPhoneModel : NSObject
@property (nonatomic, copy) NSString *tel;
@property (nonatomic, copy) NSString *turn;
@property (copy, nonatomic) NSString* desc;
@end

/**
 socket 播放器控制指令
 */
@interface AVControl : NSObject

/** url */
@property (nonatomic, copy) NSString *avUrl;
/** 控制类型 paly|pause|stop */
@property (nonatomic, copy) NSString *controlType;
/** 播放开始时间 */
@property (nonatomic, copy) NSString *startTime;
/** 视频类型 audio/video */
@property (nonatomic, copy) NSString *avType;
/** 视频名字 */
@property (copy, nonatomic) NSString* docName;
///** 下载状态 */
//@property (assign,  nonatomic) MCDownloadState downloadState;
///** 下载的本地路径 */
//@property (copy,    nonatomic) NSString *filePath;

@end

@interface THFunctionSwitchModel: NSObject
/** 声网通道是否可用 */
@property (nonatomic, copy) NSString *agora;
/** 腾讯通道是否可用 */
@property (nonatomic, copy) NSString *tencent;
/** 网易通道是否可用 */
@property (nonatomic, copy) NSString *wangyi;

@end

/**
 学生信息
 */
@interface StudentModel : NSObject
@property (nonatomic , strong) NSString  * headPicture;
@property (nonatomic , assign) NSInteger  userId ;
//@property (nonatomic, assign) NSInteger teacherId;
@property (nonatomic , strong) NSString  * mobileNo;
@property (nonatomic , strong) NSString  * realName ;
@property (nonatomic , strong) NSString  * type ;
@property (nonatomic , strong) NSString * isAuthorize;//默认值为@“0”，表示没授权
@property (nonatomic , assign) BOOL     isAuth_page;//默认值@“0”，表示没授权翻页

/** 麦克风是否打开 0 关闭 1 开启 */
@property (nonatomic, assign) BOOL isOpenMic;
/** 摄像头是否开启 0 关闭 1 开启 */
@property (nonatomic, assign) BOOL isOpenCamera;
/** 网络状态类型 0优，1良，2差 */
@property (nonatomic, copy) NSString *networkType;
/** 声音大小类型 0无 1低 2中 3高 */
@property (nonatomic, copy) NSString *volumeType;

@property (nonatomic, assign) BOOL isOnline;
/**  */
@property (nonatomic, strong) THFunctionSwitchModel* functionSwitch;

@property (nonatomic, strong) NSString *delay;

@property (nonatomic,copy) NSDictionary *networkState;

- (instancetype)initWithDic:(NSDictionary *)dic;

@end
/**
 socket 同步指令 Device
 */
@interface DeviceInfoModel : NSObject
@property (nonatomic, strong) NSString * sysInfo;
@property (nonatomic, strong) NSString * userId;
@end

typedef enum {
    SexMale,
    SexFemale
} Sex;

/*!
 login response data
 */
@interface LoginResponseData : NSObject
@property (nonatomic, assign) BOOL isInClassRoom;
//@property (nonatomic, assign) BOOL isLogin; // 是否已经登录
@property (nonatomic, assign) BOOL isRmbPwd;//是否记住密码
/** 生日 */
@property (nonatomic, strong) NSString * birthday;
/** 创建日期 */
@property (nonatomic, strong) NSString * createTime;
/** 地区ID */
@property (nonatomic, assign) NSInteger districtId;
/** 邮箱 */
@property (nonatomic, strong) NSString * email;
/** 头像图片地址 */
@property (nonatomic, strong) NSString * headUrl;
/** 老师端 教研端有值建议使用用户ID */
@property (nonatomic, assign) NSInteger ID;
/** 老师端 教研端有值建议使用用户ID */
@property (nonatomic, copy) NSString *teacherIDString;
/** 用户ID学生端建议使用 */
@property (nonatomic, assign) NSInteger userId;
/** 用户ID学生端建议使用 */
@property (nonatomic, strong) NSString * IDString;
/** 手机号 */
@property (nonatomic, strong) NSString * mobileNo;
/** 用户昵称 */
@property (nonatomic, strong) NSString * nickName;
/** md5过的密码 */
@property (nonatomic, strong) NSString * password;
/** 用户真实姓名 */
@property (nonatomic, strong) NSString * realName;
/** 角色ID */
@property (nonatomic, assign) NSInteger roleId;
/** 性别 (0男，1女) */
@property (nonatomic, assign) NSInteger sex;

@property (nonatomic, strong) NSString * ucClientNumber;
@property (nonatomic, strong) NSString * ucClientPwd;
@property (nonatomic, strong) NSString * userName;
@property (nonatomic, strong) NSString * loginPsw;

@property (nonatomic, strong) NSString * showName;


@property (nonatomic, strong) NSString * token;

@property (nonatomic, strong) NSNumber *provinceId;
@property (nonatomic, strong) NSNumber *cityId;
@property (nonatomic, copy)   NSString *school;

/** 希望学习的科目 */
@property (nonatomic, copy)   NSString *hopeCurriculum;
/** 学习年级 */
@property (nonatomic, strong) NSNumber *gradeId;
@property (nonatomic, copy)   NSString *gradeName;//接口转换后的数据
@property (nonatomic, copy)   NSString *myGradeName;//接口返回的原始数据

/** 0:未绑定QQ   1绑定了QQ*/
@property (nonatomic, strong) NSNumber *isQQBind;
@property (nonatomic, strong) NSNumber *isWXBind;

@property (nonatomic, assign) BOOL isCalendarRemind;

@property (nonatomic, strong) NSString *logTime;//登录客户端时间

@end



/**
 获取课程结束评价
 */
@interface LessonCommentConfig : NSObject
@property (nonatomic, strong) NSString * commentType;
@property (nonatomic, assign) BOOL       isRequired;
@property (nonatomic, strong) NSString * paramId;

/** 1-8字 */
@property (nonatomic, strong) NSString * paramTips;
@property (nonatomic, strong) NSString * paramTitle;
/** 1^8 */
@property (nonatomic, strong) NSString * paramValue;

@property (nonatomic, strong) NSString * chooseDetail;
/** 填写的内容 */
@property (nonatomic, copy) NSString *strInput;
@end



/**
 进入教室返回数据
 */
//@interface EnterRoomStudent : NSObject
//@property (strong, nonatomic) NSString *headPicture;
//@property (assign, nonatomic) NSInteger studentId;
//@property (strong, nonatomic) NSString *mobileNo;
//@property (strong, nonatomic) NSString *realName;
//@property (strong, nonatomic) NSString *type;
//@end
//@interface EnterRoomTeacher : GPLBaseModel
//@property (strong, nonatomic) NSString *headPicture;
//@property (strong, nonatomic) NSString *mobileNo;
//@property (strong, nonatomic) NSString *realName;
//@property (assign, nonatomic) NSInteger teacherId;
//@end
@interface EnterRoomResponseData : NSObject
@property (nonatomic, strong) NSString *qqSign;
@property (nonatomic, strong) NSString *qqNewSign;
@property (nonatomic, strong) NSString *endTime;
@property (nonatomic, assign) BOOL      hasMedia;
@property (nonatomic, assign) NSInteger lessonId;
@property (nonatomic, strong) NSString *startTime;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *title_short;
@property (nonatomic, strong) NSArray *student;
@property (nonatomic, strong) StudentModel *teacher;
/** 0 没开 1 开了 */
@property (nonatomic, copy) NSString *startFlag;
/** 学生结束课程有值跳转 */
@property (nonatomic, copy) NSString *linkUrl;

@property (nonatomic, strong) NSArray *ipList;//优选IP列表 [“192.168.1.1”,”192.168.1.2”]
/** 1：TCP 2：UDP,目前已没有UDP，只有TCP */
@property (nonatomic, assign) NSInteger socketFlag;
@property (nonatomic, assign) NSInteger lessonSecondCount;//上课总时长
@property (nonatomic, strong) NSArray *lessonPlans;//所有课程讲义信息
/**
 100,咨询支持总监,CCTO,I
 101,咨询,CC,I
 102,咨询支持经理,CCTM,I
 106,咨询副总裁,CCVP,I
 108,咨询总监,CCO,I
 109,咨询经理,CCM,I
 110,QA稽查,CCQA,
 111,在线客服,CCCS,
 200,教学部经理,TEACH_M,
 201,学科老师,TR,
 202,教学经理,TRM,
 203,教研经理,TRRM,
 204,教务专员,TROA,
 205,师资培训经理,TRTM,
 206,学科老师（公测）,TR_BETA,
 207,高级教研经理,STRRM,
 208,教研员,TRRS,
 300,运营经理,OD_M,O
 301,伙伴运营主管,OD_CPS,O
 302,直播运营主管,OD_LOS,O
 303,新媒体主管,MD_UMOS,
 304,市场经理,MD_MM,M
 305,合作伙伴,PARTNER,
 306,市场助理,MA,M
 307,市场主管,MS,M
 308,渠道总监,CD,C
 309,市场运营总监,CMO,
 310,运营实习生,OI,O
 311,渠道经理,CM,C
 312,BD经理,BDM,
 313,商务主管,BS,C
 314,社群运营,CO,O
 315,直播运营专员,OD_LOP,
 316,市场运营中心副总裁,MTD_VP,
 317,公关经理,PR,
 318,数据分析,DA,
 409,财务主管,FINANCE_S,
 410,财务总监,CFO,
 411,会计,ACC_OP,
 412,行政出纳,CASH_A,
 501,商务拓展,MD_BD,
 502,市场策划,MD_PR,
 600,客服总监,CRO,
 601,客服,CR,
 602,助理客服总监,CRO_S,
 608,客服支持总监,CRTO,
 609,客服经理,CRM,
 610,学员社区运营,OS,
 611,运营督导,OM,
 612,客服教务专员,CREC,
 901,技术支持,TECH_SUPPORT,
 902,系统管理员,ADMIN,
 903,产品经理,PM,
 1000,超级管理员,SUPER_ADMIN,
 2222,教学专员,TRO_ZHOU,
 */
@property (nonatomic, copy) NSString *nowRoleType; //角色类型 没啥用
@property (nonatomic, copy) NSString *userType;//依据 nowRoleType 类型有 audit旁听 teacher老师 assistent关单角色 student_A student_B

@property (nonatomic, assign) BOOL    offSingle; //是否课关单
@property (nonatomic, assign) BOOL    teaInClassRoomFlag;//"false/boolean/true在教室false不在、当前老师是否在教室"
@property (nonatomic,strong) NSString *lessonType; // 课程类型 （0表示试听 1付费试听课，10表示订单课）
@property (nonatomic,strong) NSString *reportFlag; // 是否有报告 （0没有，1有）
@property (nonatomic,strong) NSString *applicationType; // 试听课类型 （1 标准试听课 或者 0老版本试听课）
/** 是否有其他cc在教室 */
@property (nonatomic, assign) BOOL    ccEnterRoom;
/** 当前正在上课中的教师id */
@property (nonatomic, copy) NSString *classTeacherId;

- (BOOL)isStandardTryLesson;

@end



/*!
 *  @function	NSObject
 *  @abstrac    主要参照login接口
 *  @param      class
 *  @discussion 此类为专门放请求返回对象使用
 */


/*!
    Test BigTestModel : TestModel :
 */

@interface BigTestModel : NSObject

@property (nonatomic, strong) NSString *context;
@property (nonatomic, strong) NSArray *list;
@property (nonatomic, strong) NSString *fuck;
@end

@interface TestModel : NSObject
@property (nonatomic, strong) NSString *context;
@property (nonatomic, strong) NSNumber *age;
@property (nonatomic, assign) BOOL isSelected;
@end


typedef enum : NSUInteger {
    
    SKAudioVidioStatusNormal,
    SKAudioVidioStatusPlaying,
    SKAudioVidioStatusPause
    
} SKAudioVidioStatus;
/**
 音视频列表模型
 */
@interface MediaModel : NSObject

/** 新的音视频 文件名字也是这个 */
@property (copy,    nonatomic) NSString* docName;
@property (assign,  nonatomic) NSInteger docId;/**< 音视频id */
@property (copy,    nonatomic) NSString* fileUrl;/**< 音视频地址老版本地址 */
@property (assign,  nonatomic) NSInteger pageNo;/**< 音视频所属的页码(为0则属于课件) */
@property (assign,  nonatomic) NSInteger docFid;/**< 音视频所属的课件(为0则属于课堂) */
@property (copy,    nonatomic) NSString* mediaType;/**< 音视频所属的类型LESSON课堂DOC课件PAGE页面 */
@property (copy,    nonatomic) NSString* fileType;/**<  MP4*/

@property (assign,  nonatomic) MCDownloadState downloadState;/**< 下载状态 */
@property (copy,    nonatomic) NSString *filePath;/**< 下载的本地路径 */
@property (strong, nonatomic)  NSString *playTime;/**< 播放的时间 */
@property (nonatomic, assign) BOOL isSelected;

// 新的音视频

/** 新的音视频 MP4   MP3 */
//@property (copy, nonatomic) NSString* docType;
/** 新的音视频 原始资源url */
//@property (copy, nonatomic) NSString* originUrl;
/** 1为旧版本音视频， 0为新版本音视频 */
@property (copy, nonatomic) NSString* type;
@end


@interface RoomPenModel : NSObject
/** 线颜色 */
@property (copy,    nonatomic) NSString* lineColor;
/** 线宽度 */
@property (copy,  nonatomic) NSString* lineWidth;
/** 线颜色tag */
@property (nonatomic, assign) NSInteger penColorTag;
/** 线宽度tag */
@property (nonatomic, assign) NSInteger penWidthTag;

@end


@interface HttpDataModels : NSObject

@end



