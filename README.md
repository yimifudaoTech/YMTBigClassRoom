# YMTBigClassRoom

[![CI Status](https://img.shields.io/travis/zhangqian/YMTBigClassRoom.svg?style=flat)](https://travis-ci.org/zhangqian/YMTBigClassRoom)
[![Version](https://img.shields.io/cocoapods/v/YMTBigClassRoom.svg?style=flat)](https://cocoapods.org/pods/YMTBigClassRoom)
[![License](https://img.shields.io/cocoapods/l/YMTBigClassRoom.svg?style=flat)](https://cocoapods.org/pods/YMTBigClassRoom)
[![Platform](https://img.shields.io/cocoapods/p/YMTBigClassRoom.svg?style=flat)](https://cocoapods.org/pods/YMTBigClassRoom)

# 接入指南

- ## 快速接入溢米直播云
本文介绍如何接入溢米直播云，快速实现在线课堂互动直播。        
### demo体验
溢米直播云 在 Github 上提供一个开源的在线课堂互动直播示例项目 [YMLiveCloudDemo](https://github.com/yimifudaoTech/YMTBigClassRoom)。在实现相关功能前，你可以下载并查看源代码。
### 前提条件
- Xcode 9.0 或以上版本
- 支持 iOS 8.0 或以上版本的 iOS 设备
- 需要申请对应的appId和AppKey
- 需要接入溢米直播云后台系统，实现教室的创建，获取教室ID
### 准备开发环境
本节介绍如何将YMCloudLiveSDK集成到你的项目中，可以选择如下任意一种方法进行集成：        
#### 方法一：使用cocoaPods 自动集成
1. 开始前确保你已安装 Cocoapods。参考 [Getting Started with CocoaPods](https://guides.cocoapods.org/using/getting-started.html#getting-started) 安装说明。      
2. 在 Terminal 里进入项目根目录，并运行 pod init 命令。项目文件夹下会生成一个 Podfile 文本文件。    
3. 打开 Podfile 文件，修改文件为如下内容。注意将 Your App 替换为你的 Target 名称


```
platform :ios, '9.0' use_frameworks!
target 'Your App' do
 pod 'YMTBigClassRoom', '0.1.23'
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

### 接入溢米直播云教室
#### 1. 溢米云直播在线教室的交互流程
- iOS APP->>(溢米)云教室: registerSDK()
- (溢米)云教室->>iOS APP: 返回初始化结果
- iOS APP->>(溢米)云教室: 登录（appID、sercet、房间ID）
- (溢米)云教室->>(溢米)API: 获取教室通行token
- (溢米)API->>(溢米)云教室: 返回溢米教室通行token
- (溢米)云教室->>iOS APP: 回调结果返回 APP
- iOS APP->>(溢米)云教室:joinCloudRoom()进入教室（appID、溢米token、房间ID）
- (溢米)云教室->>iOS APP:返回结果
- iOS APP->>(溢米)云教室:leaveCloudRoom()退出房间
- (溢米)云教室-->>(溢米)API:退出房间
- (溢米)云教室->>iOS APP:返回退出结果
- iOS APP->>(溢米)云教室:recordPlay()播放录播
- (溢米)云教室-->>(溢米)API:下载录播信息
- (溢米)云教室->>iOS APP:返回结果

2. 导入类
在项目中导入YMTBigClassSDKManager类

```
#import <YMTBigClassRoom/YMTBigClassSDKManager.h>
```
3. 初始化SDK

```
/**
 初始化sdk

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
4. 用户登录

```
/**
 登录,调用login 触发onLogin,获取YiMiToken

 @param roomID 房间ID
 @param userID 用户ID
 @param result 结果回调
 */
- (void)loginRoomWithRoomID:(NSString *)roomID userID:(NSString *)userID result:(YMTBigClassRoomLoginRoomResult)result;

/**
 登录回调
*/
typedef void(^YMTBigClassRoomRegisterResult)(BOOL success, YMTRoomInfoCode code);
```
5. 加入房间
```
/**
 加入教室,如果成功自动开发房间
 @param roomID 房间ID
 @param userID 用户ID
 @param groupId 用户分组ID
 @param headUrl 用户头像
 @param yimiToken 登录获取的token
 @param role 1=老师、2=学生 3=班主任
 @param nickName 用户昵称或者名字
 @param bussinessData 自定义业务json数据
 @param result onJoinCloudRoom 回调
 */
- (void)joinCloudRoomWithRoomID:(NSString *)roomID userID:(NSString *)userID groupId:(NSString *)groupId
                        headUrL:(NSString *)headUrl token:(NSString *)yimiToken userRole:(NSUInteger)role nickName:(NSString *)nickName bussinessData:(NSString *)bussinessData result:(YMTBigClassRoomJoinRoomResult)result;
/**
  加入教室回调
  typedef void(^YMTBigClassRoomJoinRoomResult)(BOOL success, YMTRoomInfoCode code, UIViewController * _Nullable vc);
*/

```
6. 退出教室

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
7. 销毁教室

```
/**
 房间销毁,释放和教室相关的信息
 */
- (void)destroy;
```
8. 进入录播回放

```
/**
 录播回放

 @param YiMiToken 登录返回的token
 @param viewParent 传递视图展示层
 @param roomId 房间Id
 @param userid 用户Id
 */
- (void)recordPlayToken:(NSString *)YiMiToken viewParent:(UIViewController *)viewParent roomID:(NSString *)roomId userid:(NSString *)userid;
```
9. 相关错误码定义

```
/**
  云教室错误码定义
*/
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
    YMTRoomInfoCodeRecord_File_Download_Failed = 301
};
```



## Author

xiangping, ping.xiang@yimifudao.com

## License

YMTBigClassRoom is available under the MIT license. See the LICENSE file for more info.


