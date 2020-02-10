//
//  YMStorage.h
//  YiMiApp
//
//  Created by xieyan on 15/9/15.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger,CourseRecordType) {
    CourseRecordTypeNone,
    CourseRecordTypeAudio,
    CourseRecordTypeTrail,
    CourseRecordTypeAll,
};
@interface YMStorage : NSObject

+(NSDictionary*)getCachedDic:(NSString*)cacheKey;
+(void)cacheDic:(NSDictionary*)dic forkey:(NSString*)key;




+(void)courseRecordDelete_User:(NSString*)user lesson:(NSString*)lesson;
+(BOOL)courseRecordExist_User:(NSString*)user lesson:(NSString*)lesson type:(CourseRecordType)type;
+(NSURL*)courseRecordDownloadPath_User:(NSString*)user lesson:(NSString*)lesson type:(CourseRecordType)type;

//  获取当前登录用户录播文件夹路径(research使用)
+ (NSString *)getCurrentUserSandboxPathWithUserID:(NSString *)userID;
@end
