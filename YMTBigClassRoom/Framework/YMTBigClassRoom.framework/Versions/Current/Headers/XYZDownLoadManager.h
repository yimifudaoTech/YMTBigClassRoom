//
//  XYZDownLoadManager.h
//  YiMiApp
//
//  Created by xieyan on 16/4/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import "AFURLSessionManager.h"
#import "XYZStorage.h"
#define XYZDownLoader [XYZDownLoadManager Instance]
@interface XYZDownLoadManager : AFURLSessionManager
@property(nonatomic,strong)AFHTTPRequestSerializer * requestSerializer;

+(instancetype)Instance;
-(NSURLSessionDownloadTask*)xyzDownLoad:(NSString*)url prma:(NSDictionary*)parma path:(NSURL*)pathUrl;
-(NSURLSessionDownloadTask*)xyzDownLoad:(NSString*)url prma:(NSDictionary*)parma path:(NSURL*)pathUrl progress:(void (^)(NSProgress *downloadProgress)) downloadProgressBlock;
-(NSURLSessionDownloadTask*)xyzDownLoad:(NSString*)url prma:(NSDictionary*)parma path:(NSURL*)pathUrl progress:(void (^)(NSProgress *downloadProgress)) downloadProgressBlock complete:(void(^)(NSURLResponse * response, NSURL * filePath, NSError * error))complete;

-(NSURLSessionDownloadTask*)xyzDownLoadWithPostOrGet:(NSString *)type url:(NSString*)url prma:(NSDictionary*)parma path:(NSURL*)pathUrl progress:(void (^)(NSProgress *downloadProgress)) downloadProgressBlock complete:(void(^)(NSURLResponse * response, NSURL * filePath, NSError * error))complete;

-(NSURLSessionDownloadTask*)xyzDownLoadCourse:(NSString*)url parma:(NSDictionary*)parma User:(NSString*)user lesson:(NSString*)lesson type:(CourseRecordType)type progress:(void (^)(NSProgress *downloadProgress)) downloadProgressBlock  complete:(void(^)(NSURLResponse * response, NSURL * filePath, NSError * error))complete;
-(NSURLSessionDownloadTask*)xyzDownLoadCourse:(NSString*)url parma:(NSDictionary*)parma User:(NSString*)user lesson:(NSString*)lesson type:(CourseRecordType)type progress:(void (^)(NSProgress *downloadProgress)) downloadProgressBlock;
-(NSURLSessionDownloadTask*)courseIsDownLoadingReturn:(NSString*)url parma:(NSDictionary*)parma;
@end
