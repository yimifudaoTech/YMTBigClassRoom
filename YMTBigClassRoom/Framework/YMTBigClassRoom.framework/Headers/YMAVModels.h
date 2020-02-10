//
//  YMAVModels.h
//
//  Created by 顾鹏凌 on 2016/10/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//


/**
 socket 播放器控制指令
 */
@interface YMAVControl : NSObject

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
/** 课件id */
@property (copy, nonatomic) NSString* dockId;
///** 下载状态 */
//@property (assign,  nonatomic) MCDownloadState downloadState;
///** 下载的本地路径 */
//@property (copy,    nonatomic) NSString *filePath;

@end


@interface YMAVModels : NSObject

@end



