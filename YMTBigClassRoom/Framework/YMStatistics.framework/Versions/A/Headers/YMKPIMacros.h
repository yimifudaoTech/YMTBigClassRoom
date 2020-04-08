//
//  YMKPIMacros.h
//  Pods
//
//  Created by yimi on 2019/12/17.
//

#ifndef YMKPIMacros_h
#define YMKPIMacros_h

static NSString * const kYMKPI_LOGTAG = @"ymkpi";

static NSString * const kYMKPI_Target_EnterRoom = @"enterRoom";

static NSString * const kYMKPI_Target_ExitRoom = @"exitRoom";

static NSString * const kYMKPI_Target_H5Courseware = @"loadH5Courseware";

static NSString * const kYMKPI_Target_AVCourseware = @"loadAVCourseware";

static NSString * const kYMKPI_Target_UploadImage = @"uploadImage";

static NSString * const kYMKPI_Target_LoadImage = @"loadImage";

static NSString * const YMKPIEVENT_DES_START = @"start";

static NSString * const YMKPIEVENT_DES_DOING = @"doing";

static NSString * const YMKPIEVENT_DES_END = @"end";

typedef NS_ENUM(NSInteger, YMKPIEvent) {
    YMKPIEvent_Start,
    YMKPIEvent_DOING,
    YMKPIEvent_End
};

#endif /* YMKPIMacros_h */
