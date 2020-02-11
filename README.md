## 快速接入溢慧云iOS SDK
本文介绍如何接入溢慧云iOS SDK，快速实现在线课堂互动直播。
### 发版说明
#### 1.2.1.1版本       
该版本新增特性与修复问题详见下文。      
API变更：     
新增：    
- loginWithUserID       
用户登录接口，获取用户token，增加token校验机制。此版本暂时支持调用其他接口时不传递token参数，后续版本会不再支持非token机制接口调用。      

修改：
- joinCloudRoom     
进入房间接口，新增token参数，并将之前用户相关的参数统一到YMSDKUserInfo中，新增用户角色role，用户身份userIdentity,关联用户ID relatedUserId。
- recordPlay     
录播接口，新增token参数
- courseWare      
查看课件接口，新增token参数     

新增特性    
- 新增旁听功能，家长可以以旁听角色进入教室，家长的userId需要与学生的userId不一样；
- 新增课堂评价功能，课程结束时老师和学生可以对上课情况进行评价。     

改进：      
- 优化进入教室速度；
- 优化课件加载速度。   

修复：
- 修复部分白板轨迹，图形和图片绘制问题。

    
### demo体验
溢慧云SDK iOS端在 Github 上提供一个开源的在线课堂互动直播示例项目 [YMLiveCloudDemo](https://github.com/yimifudaoTech/YMTBigClassRoom)。在实现相关功能前，你可以下载并查看源代码。
### 前提条件
- Xcode 9.0 或以上版本
- 支持 iOS 8.0 或以上版本的 iOS 设备
- 需要申请对应的appId和appKey
- 需要接入溢慧云后台系统，实现教室的创建，获取教室ID
### 准备开发环境
本节介绍如何将YMCloudLiveSDK集成到你的项目中，可以选择如下任意一种方法进行集成：        
#### 方法一：使用cocoaPods 自动集成
1. 开始前确保你已安装 Cocoapods。参考 [Getting Started with CocoaPods](https://guides.cocoapods.org/using/getting-started.html#getting-started) 安装说明。      
2. 在 Terminal 里进入项目根目录，并运行 pod init 命令。项目文件夹下会生成一个 Podfile 文本文件。    
3. 打开 Podfile 文件，修改文件为如下内容。注意将 Your App 替换为你的 Target 名称


```
platform :ios, '9.0' use_frameworks!
target 'Your App' do
 pod 'YMTBigClassRoom', '1.2.0.1'
end
```
4. 在 Terminal 内运行 pod update 命令更新本地库版本。
5. 运行 pod install 命令安装YMCloudLiveSDK。成功安装后，Terminal 中会显示 Pod installation complete!，此时项目文件夹下会生成一个 xcworkspace 文件。
6. 打开新生成的 xcworkspace 文件。
#### 方法二：手动复制SDK 文件
暂时未提供此方式

#### 添加媒体权限
根据场景需要，在 info.plist 文件中，点击 + 图标开始添加如下内容，获取相应的设备权限：

Key | Type | Value
---|---|---
Privacy - Microphone Usage Description | String | 使用麦克风的目的
Privacy - Camera Usage Description | String | 使用摄像头的目的
Privacy - Photo Library Usage Description|String|上传图片需要访问相册
Privacy - Photo Library Additions Usage Description|String|保存图片需要访问相册

### 接入溢慧云教室

#### 1. 溢慧云教室的交互流程

- iOS APP->>(溢米)云教室: registerSDK()（appID、appKey）
- (溢米)云教室->>iOS APP: 返回初始化结果
- iOS APP->>(溢米)云教室: login()登录（userID）
- (溢米)云教室->>(溢米)API: 获取教室通行token
- (溢米)API->>(溢米)云教室: 返回溢米教室通行token
- (溢米)云教室->>iOS APP: 回调结果返回 APP
- iOS APP->>(溢米)云教室:joinCloudRoom()进入教室（userInfo）
- (溢米)云教室->>iOS APP:返回结果
- iOS APP->>(溢米)云教室:leaveCloudRoom()退出房间
- (溢米)云教室-->>(溢米)API:退出房间
- (溢米)云教室->>iOS APP:返回退出结果
- iOS APP->>(溢米)云教室:recordPlay()播放录播
- (溢米)云教室-->>(溢米)API:下载录播信息
- (溢米)云教室->>iOS APP:返回结果
- iOS APP->>(溢米)云教室:courseware()查看课件
- (溢米)云教室-->>(溢米)API:获取课件
- (溢米)云教室->>iOS APP:返回结果

#### 2. 导入相关类
在项目中导入YMTBigClassSDKManager类

```
#import <YMTBigClassRoom/YMTBigClassSDKManager.h>
```
#### 3. 初始化SDK

```
/**
 初始化SDK

 @param appID 业务后台分配
 @param appKey 业务后台分配
 @param result 结果回调
 */
- (void)registerSDKWithAppID:(NSString *)appID AppKey:(NSString *)appKey result:(YMTBigClassRoomRegisterResult)result;

/**
 SDK初始化回调
 */
typedef void(^YMTBigClassRoomRegisterResult)(BOOL success, YMTRoomInfoCode code);
```
#### 4. 用户登录

```
/**
 登录
 
 @param userID 用户ID
 @param result 结果回调
 */
- (void)loginWithUserID:(NSString *)userID result:(YMTBigClassRoomLoginRoomResult)result;

/**
 登录回调
 */
typedef void(^YMTBigClassRoomRegisterResult)(BOOL success, YMTRoomInfoCode code, NSString * _Nullable token);
```
#### 5. 进入教室
```
/**
 加入教室,如果成功自动开发房间
 
 @param userInfo    教室内用户信息模型
 @param parentView  传递视图展示控制器
 @param result      onJoinCloudRoom 回调
 */
- (void)joinCloudRoom:(YMSDKUserInfo *)userInfo appViewController:(UIViewController *)parentView result:(YMTBigClassRoomJoinRoomResult)result;

/**
  加入教室回调
 */
typedef void(^YMTBigClassRoomJoinRoomResult)(BOOL success, YMTRoomInfoCode code, UIViewController * _Nullable vc);
```
#### 6. 退出教室

```
/**
 退出教室

 @param result leaveCloudRoom 回调
 */
- (void)leaveCloudRoom:(YMTBigClassRoomLevelRoomResult)result;

/**
  退出教室回调
 */
typedef void(^YMTBigClassRoomLevelRoomResult)(BOOL success, YMTRoomInfoCode code);
```
#### 7. 销毁教室

```
/**
 房间销毁,释放和教室相关的信息
 */
- (void)destroy;
```
#### 8. 进入录播回放

```
/**
 录播回放

 @param viewParent  传递视图展示层
 @param roomId      房间Id
 @param token       用户token
 @param userid      用户Id
 */
- (void)recordPlay:(UIViewController *)viewParent roomID:(NSString *)roomId token:(NSString *)token userid:(NSString *)userid;
```
#### 9. 删除缓存数据和文件

```
/**
 删除缓存数据和文件
 
 @param userid 用户ID
 */
- (BOOL)clearCache:(NSString *)userid;
```
#### 10. 查看课件

```
/**
 查看课件
 
 @param  parentVC   传递展示的视图控制器
 @param  roomId     房间ID
 @param  token      用户token
 @param  userId     用户ID
 @param  result     查看课件回调
 */
- (void)courseWare:(UIViewController *)parentVC roomId:(NSString *)roomId token:(NSString *)token userId:(NSString *)userId result:(YMTRequestCallBackResult)resul;

/**
 查看课件回调
*/
typedef void(^YMTRequestCallBackResult)(BOOL success,YMTRoomInfoCode code, NSString * _Nullable errorMessage);
```
#### 11. 教室内用户信息模型

```
// 教室内用户信息数据模型
@interface YMSDKUserInfo : NSObject
/**
 * roomID  房间ID     必填项
 */
@property (nonatomic, strong) NSString *roomID;
/**
 * token   用户token  必填项
 */
@property (nonatomic, strong) NSString *token;
/**
 * 用户ID需要保证唯一性，家长旁听用户的用户ID需要与学生进行区分，如果用户账户没有做区分，建议在学生ID基础上通过一定规则生成
 * role    userID  用户ID     必填项
 */
@property (nonatomic, strong) NSString *userID;
/**
 * role    groupId 用户分组ID  必填项
 */
@property (nonatomic, strong) NSString *groupId;
/**
 * headUrl 用户头像    必填项
 */
@property (nonatomic, strong) NSString *headUrl;
/**
 * role    用户角色    必填项
 */
@property (nonatomic, assign) YMRoleType role;
/**
 * nickName 用户昵称或者名字    必填项
 */
@property (nonatomic, strong) NSString *nickName;
/**
 * bussinessData 自定义业务json数据    选填项
 */
@property (nonatomic, strong) NSString *bussinessData;
/**
 * relatedUserId 家长旁听原学生uid    选填项
 */
@property (nonatomic, strong) NSString *relatedUserId;
/**
 * userIdentity 用户身份，如家长    选填项
 */
@property (nonatomic, strong) NSString *userIdentity;

@end

/**
 角色类型定义
*/
typedef NS_ENUM(NSInteger, YMRoleType) {
    YMRoleTypeTeacher = 1,
    YMRoleTypeStudent = 2,
    YMRoleTypeTeacherAide = 3,
    YMRoleTypeAudit = 4
};
```

#### 12. 相关错误码定义

```
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
     * 用户关闭课堂评价
     */
    YMRoomErrorCode_InRoom_UserCloseComment = 4202,
    /**
     * 获取Token失败
     */
    YMRoomErrorCode_LoginFail = 5000,
};
```

