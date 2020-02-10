//
//  SDSCMineCatalogGOModel.h
//  student
//
//  Created by 顾鹏凌 on 2018/9/12.
//  Copyright © 2018年 YiMi. All rights reserved.
//

//#import <JsonExchangeModel/JsonExchangeModel.h>
#import "YMEnum.h"

typedef NS_ENUM(NSInteger, AVCourseWareOperation) {
    AVCourseWareOperation_None = 0,
    AVCourseWareOperation_Play,
    AVCourseWareOperation_Pause,
    AVCourseWareOperation_Stop
};

typedef NS_ENUM(NSInteger, YMClassRoomType) {
    YMClassRoomType_1V1 = 0,
    YMClassRoomType_1V6 = 1,
    YMClassRoomType_1V12 = 2,
    YMClassRoomType_BigClass = 3
};

typedef NS_ENUM(NSInteger, YMCourseWareType) {
    YMCourseWareType_Normal = 1,
    YMCourseWareType_AV = 2,
};

//小班课根据课件id查询课件接口
@interface SCCloudDiskFileDetailModel : NSObject
@property (copy, nonatomic) NSString *fileId;//课件id
@property (strong, nonatomic) NSArray <NSString *> *images;//课件图片数组
@property (copy, nonatomic) NSString *name;//课件名称
@property (copy, nonatomic) NSString *path;//原始文件路径
@property (copy, nonatomic) NSString *suffix;//文件类型
@property (copy, nonatomic) NSString *boardId;

@property (assign, nonatomic) AVCourseWareOperation avOperation;
@property (assign, nonatomic) NSTimeInterval seekTime;
/** 课件json数据 */
@property (copy, nonatomic) NSString *jsonData;
/**
 将课件数据插入到字典中

 @param model 课件数据
 @param key 课件ID
 */
+ (void)insetModelToDicWithModel:(SCCloudDiskFileDetailModel *)model key:(NSString *)key;

/**
 从字典中获取对应的课件数据

 @param key 课件ID
 @return 课件数据
 */
+ (SCCloudDiskFileDetailModel *)readModelFromDicWithKey:(NSString *)key;

@end


//进入教室配置信息获取
@interface YMRoomDomainModel : NSObject
@property (copy, nonatomic) NSString *domain;
@property (copy, nonatomic) NSString *domainType;
@property (copy, nonatomic) NSString *tcpPort;
@property (copy, nonatomic) NSString *httpPort;
@end

@interface YMRoomIpListModel : NSObject
@property (copy, nonatomic) NSString *ID;
@property (copy, nonatomic) NSString *serverName;
@property (copy, nonatomic) NSString *serverArea;
@property (copy, nonatomic) NSString *serverIp;
@property (copy, nonatomic) NSString *serverLimit;
@property (copy, nonatomic) NSString *serverWarn;
@property (copy, nonatomic) NSString *isValid;
@property (copy, nonatomic) NSString *isp;
@property (copy, nonatomic) NSString *createById;
@property (copy, nonatomic) NSString *createByName;
@property (copy, nonatomic) NSString *createByTime;
@property (copy, nonatomic) NSString *updateById;
@property (copy, nonatomic) NSString *updateByName;
@property (copy, nonatomic) NSString *updateByTime;
@property (copy, nonatomic) NSString *deleteFlag;
@end

//小班课声网配置
@interface YMRoomAgoraAuthModel : NSObject
@property (copy, nonatomic) NSString *channelKey;
@property (copy, nonatomic) NSString *channelName;
@property (copy, nonatomic) NSString *recordingKey;
@property (copy, nonatomic) NSString *token;
@property (copy, nonatomic) NSString *uid;
@property (copy, nonatomic) NSString *agoraAppid;
@end

@interface YMRoomUserExtraInfo : NSObject

@property (copy, nonatomic) NSString *systemInfo;
@property (copy, nonatomic) NSString *userName;
@property (copy, nonatomic) NSString *videoId;

@end

//用户信息
@interface YMRoomUserModel : NSObject
@property (copy, nonatomic) NSString *headImage;
@property (copy, nonatomic) NSString *phone;
@property (copy, nonatomic) NSString *userId;
@property (copy, nonatomic) NSString *userName;
@property (copy, nonatomic) NSString *uid;
@property (copy, nonatomic) NSString *userType;
@property (assign, nonatomic) YMRoleType roleType;
@property (assign, nonatomic) BOOL isOnline;
@property (assign, nonatomic) BOOL isCurrentRoomUser;
@property (assign, nonatomic) NSInteger medalNumber;

@property (strong, nonatomic) YMRoomUserExtraInfo *extraInfo;

+ (YMRoleType)transferCommandUserType:(NSString *)userType;

@end

//v1.0 进入教室
@interface YMRoomModel : NSObject
@property (strong, nonatomic) YMRoomAgoraAuthModel *agoraAuth;
@property (copy, nonatomic) NSDictionary <NSString *,YMRoomUserModel *> *usersDic;
@property (strong, nonatomic) YMRoomUserModel *teacher;

@property (copy, nonatomic) NSString *currentUserId;
@property (copy, nonatomic) NSString *currentUid;
@property (copy, nonatomic) NSString *endTime;
@property (copy, nonatomic) NSString *liveroomId;
@property (copy, nonatomic) NSString *startTime;
@property (copy, nonatomic) NSString *title;
@property (copy, nonatomic) NSString *chatRoomId;
@property (copy, nonatomic) NSString *nickName;
@property (copy, nonatomic) NSString *groupId;
@property (copy, nonatomic) NSString *headurl;
@property (copy, nonatomic) NSString *type;
@property (copy, nonatomic) NSString *token;
@property (copy, nonatomic) NSString *h5CoursewarePreloadUrl;
@property (copy, nonatomic) NSString *userType;
@property (copy, nonatomic) NSString *roleType;
@property (copy, nonatomic) NSString *relatedUserId;
@property (copy, nonatomic) NSString *userIdentity;

@property (strong, nonatomic) YMRoomDomainModel *domain;
@property (strong, nonatomic) NSArray <YMRoomIpListModel *> *ipList;
@property (strong, nonatomic) NSMutableArray *dnsIPList;

- (YMRoomUserModel *)obtainUserFromUserId:(NSString *)userId;
- (YMRoomUserModel *)obtainUserFromUid:(NSString *)uid;
- (NSArray<NSString *> *)randomRollResources;
@end

