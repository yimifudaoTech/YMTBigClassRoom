//
//  SKOSSClient.h
//  YiMiLib
//
//  Created by YangXiansen on 2018/1/11.
//  Copyright © 2018年 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AliyunOSSiOS/OSSService.h>

@interface SKOSSModel: NSObject
/** 临时ID */
@property (copy, nonatomic) NSString*keyId;
/** 临时秘钥 */
@property (copy, nonatomic) NSString*secret;
/** 上传照片过期验证 */
@property (copy, nonatomic) NSString*token;
/** 域名 */
@property (copy, nonatomic) NSString*endpion;
/** 上传照片路径前缀 */
@property (copy, nonatomic) NSString*bucketName;
/** 路径前拼接dev */
@property (copy, nonatomic) NSString*prefix;
/** 有需要存储图片 */
@property (nonatomic, strong) UIImage*img;
@end

typedef void(^OSSUploadCallBack)(NSError* error);

@interface SKOSSClient : OSSClient

- (SKOSSClient *)initClientWithModel:(SKOSSModel*)model;

/**
 上传照片
 
 @param objectKey 文件路径
 lessonWork/student/{timestamp}/{homeworkId}/{orderNumber}/photo/xxx.jpg  学生作业上传照片路径
 lessonWork/student/{timestamp}/{homeworkId}/{orderNumber}/image/xxx.jpg  学生作业手写图片路径
 lessonWork/teacher/{timestamp}/{homeworkId}/{orderNumber}/image/xxx.jpg  老师批注图片路径
 lessonWork/teacher/{timestamp}/{homeworkId}/{orderNumber}/voice/xxx.mp3  老师语音批注
 
 timestamp格式：2017-09-11
 homeworkId：家庭作业ID
 orderNumber: 题号
 @param imgaeData 图片
 */
-(void)requestAliYunOSSUploadFileWithBucketName:(NSString *)bucketName objectKey:(NSString*)objectKey imageData:(NSData*)imgaeData progress:(void(^)(CGFloat progress))progress success:(OSSUploadCallBack)success failure:(OSSUploadCallBack)failure;
@end



