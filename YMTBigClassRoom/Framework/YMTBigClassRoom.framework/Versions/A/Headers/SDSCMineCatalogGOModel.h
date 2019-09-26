//
//  SDSCMineCatalogGOModel.h
//  student
//
//  Created by 顾鹏凌 on 2018/9/12.
//  Copyright © 2018年 YiMi. All rights reserved.
//

//#import <JsonExchangeModel/JsonExchangeModel.h>

#import "HSUserAuth.h"
#import "HSSmallClassRoomConfig.h"

typedef NS_ENUM(NSInteger, AVCourseWareOperation) {
    AVCourseWareOperation_None = 0,
    AVCourseWareOperation_Play,
    AVCourseWareOperation_Pause,
    AVCourseWareOperation_Stop
};

//小班课根据课件id查询课件接口
@interface SCCloudDiskFileDetailModel : NSObject
@property (copy, nonatomic) NSString *fileId;//课件id
@property (strong, nonatomic) NSArray <NSString *> *images;//课件图片数组
@property (copy, nonatomic) NSString *name;//课件名称
@property (copy, nonatomic) NSString *path;//原始文件路径
@property (copy, nonatomic) NSString *suffix;//文件类型

@property (assign, nonatomic) AVCourseWareOperation avOperation;
@property (assign, nonatomic) NSTimeInterval seekTime;
/** 课件json数据 */
@property (nonatomic, copy) NSString *jsonData;
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
@interface SCAgoraDomainModel : NSObject
@property (copy, nonatomic) NSString *domain;
@property (copy, nonatomic) NSString *domainType;
@property (copy, nonatomic) NSString *tcpPort;
@property (copy, nonatomic) NSString *httpPort;
@end

@interface SCAgoraIpListModel : NSObject
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
@interface SCAgoraRoomAgoraAuthModel : NSObject
@property (copy, nonatomic) NSString *channelKey;
@property (copy, nonatomic) NSString *channelName;
@property (copy, nonatomic) NSString *recordingKey;
@property (copy, nonatomic) NSString *token;
@property (copy, nonatomic) NSString *uid;
@end

// socket IM 返沪用户的状态
@interface HSSCSocketUserModel : NSObject

@property (nonatomic, assign) NSUInteger uid;
@property (nonatomic, assign) BOOL isOnline;
@property (nonatomic, assign) NSString *userType;

@end

@interface ExtraInfo : NSObject

@property (copy, nonatomic) NSString *systemInfo;
@property (copy, nonatomic) NSString *userName;
@property (copy, nonatomic) NSString *videoId;

@end

//用户信息
@interface SCAgoraRoomUserModel : NSObject
@property (copy, nonatomic) NSString *headImage;
@property (copy, nonatomic) NSString *phone;
@property (copy, nonatomic) NSString *userId;
@property (copy, nonatomic) NSString *userName;
@property (copy, nonatomic) NSString *uid;

@property (strong, nonatomic) ExtraInfo *extraInfo;

@property (copy, nonatomic) NSString *userType;
@property (assign, nonatomic) BOOL isOnline;

@property (nonatomic, strong) HSUserAuth *userAuth;
@property (nonatomic, assign) NSInteger medalNumber;

@property (nonatomic, assign) BOOL isCurrentRoomUser;

- (void)refreshAuthWithConfig:(NSDictionary *)config;
- (void)setMuteEnabel:(BOOL)mute;
- (NSDictionary *)rosterStateDictionary;
- (NSDictionary *)topviewStateDictionary;
- (NSDictionary *)bottomviewStateDictionary;

- (BOOL)muteEnable;
- (BOOL)videoEnable;

@end

//v1.0 进入教室
@interface SDSCMineGoAgoraRoomModel : NSObject
@property (strong, nonatomic) SCAgoraRoomAgoraAuthModel *agoraAuth;
@property (copy, nonatomic) NSDictionary <NSString *,SCAgoraRoomUserModel *> *usersDic;
@property (strong, nonatomic) SCAgoraRoomUserModel *teacher;

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

@property (strong, nonatomic) SCAgoraDomainModel *domain;
@property (strong, nonatomic) NSArray <SCAgoraIpListModel *> *ipList;
@property (strong, nonatomic) NSMutableArray *dnsIPList;

@property (nonatomic, copy) NSString *currentAVFileId;

- (SCAgoraRoomUserModel *)obtainUserFromUserId:(NSString *)userId;
- (SCAgoraRoomUserModel *)obtainUserFromUid:(NSString *)uid;
- (void)muteAllToStudent:(BOOL)mute;
- (NSArray<NSString *> *)randomRollResources;
@end

@interface SDSCMineLiveRoomModel : NSObject

/** 进入教室的URL */
@property (copy, nonatomic) NSString *entryUrl;
/**  服务器地址 */
@property (copy, nonatomic) NSString *host;
/** 服务器端口号 */
@property (strong, nonatomic) NSNumber *port;
/**  用户昵称  */
@property (copy, nonatomic) NSString *nickname;
/** 进入房间的密码  */
@property (copy, nonatomic) NSString *password;
/** 教室号 */
@property (copy, nonatomic) NSString *serial;
/** 用户ID */
@property (strong, nonatomic) NSString *userid;
@end

@interface SDSCMineCatalogGOModel : NSObject
@property (nonatomic, copy) NSString *recordPath;//录制件地址
@property (nonatomic, copy) NSString *path;// "string,路径"
@property (nonatomic, copy) NSString *fileName;//"string,文件名" 在预览课件中是name
@property (nonatomic, copy) NSString *fileType;//"string,文件类型" 在预览课件中是docType
@property (nonatomic, copy) NSString *countDown;//"long,倒计时"
@property (nonatomic, copy) NSString *endCountDown;
@property (nonatomic, copy) NSString *startCountDown;
@property (nonatomic, copy) NSString *type;//"int,类型，10：课件，11：讲义，12：教案，13：作业，14：素材，20：试卷。100：房间，101：录播"
@property (nonatomic, strong) NSArray *images;
@property (nonatomic, strong) SDSCMineLiveRoomModel *liveRoom;

@end
