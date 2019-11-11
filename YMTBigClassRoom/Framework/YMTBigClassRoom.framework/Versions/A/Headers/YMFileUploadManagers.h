//
//  YMFileUploadManagers.h
//  YiMiLib
//
//  Created by mac on 2019/3/4.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMUploadImageModel.h"
#import <YMTCloudClassroom/YMTChannelInfoHeader.h>

typedef void (^uploadFileCallBack)(NSInteger code, NSMutableDictionary * _Nullable uploadImageUrlInfos);

@interface YMFileUploadManagers : NSObject

+ (YMFileUploadManagers *_Nullable)sharedInstance;

/**
 图片上传方法

 @param userId            用户ID
 @param data              imageData
 @param imageCount        图片上传总数量  1：单张上传   >2:批量上传
 @param path              oss路径  bos文件名
 @param uploadProgress    进度
 @param requestCallBack   回调  1:成功  0:失败
 */
- (void)uploadPicturesWithUserId:(NSString *_Nullable)userId data:(NSData *_Nullable)data imageCount:(NSInteger )imageCount path:(NSString *_Nullable)path  uploadProgress:(void (^_Nullable)(CGFloat progress, NSString* _Nullable url))uploadProgress requestCallBack:(ChannelDataCallBack _Nullable )requestCallBack;

/**
 图片上传方法
 @param userId                                用户ID
 @param imagesArray                     图片对象集合
 @param uploadProgress              进度
 @param uploadFileCallBack     回调  1:成功  0:失败
*/
- (void)uploadPicturesWithUserId:(NSString *_Nullable)userId imagesArray:(NSMutableArray *_Nullable)imagesArray uploadProgress:(void(^_Nullable)(CGFloat progress, NSString * _Nullable url))uploadProgress uploadFileCallBack:(uploadFileCallBack _Nullable )uploadFileCallBack;

@end


