//
//  YMTQOSMacros.h
//  YMTBigClassRoom
//
//  Created by mac on 2019/11/13.
//

#ifndef YMTQOSMacros_h
#define YMTQOSMacros_h
#import <YMStatistics/YMPingbackSDK.h>

#define YMClassroomPingback [YMPingbackSDK sharedInstance:@"YMClassroom"]

/**
 QOSDK_APP 溢慧云教室内问题反馈
 */
#define YMTQOS_FeedBackFunction              @"XBKCloudClassroom_student_click_feedback"
#define YMTQOS_ClassName                     @"className"
#define YMTQOS_HelpUser                      @"help_user"
#define YMTQOS_HelpContent                   @"help_content"

/**
 QOSDK_APP 溢慧云教室内接收、加载课件
 */
#define YMTQOS_StartCourseware  @"startCourseware"
#define YMTQOS_EndCourseware    @"endCourseware"

#endif /* YMTQOSMacros_h */
