//
//  YMBigClassViewForGroupRoom.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2016/11/8.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <YMTCloudClassroom/YMTSingleGroupDB.h>
#import <YMTCloudClassroom/YMTRoomLessonPlanM.h>
#import "YMTCloudClassroom/YMWhiteBoardModule.h"
#import "YMCourseWareLayer.h"
#import "NSString+Empty.h"
#import "UIView+Geometry.h"
#import "UIColor+Create.h"

typedef NS_ENUM(NSUInteger, YMTUserStatusKindType) {
    YMTUserStatusKindTypeUnknow,
    YMTUserStatusKindTypeTeacher,
    YMTUserStatusKindTypeStudentA,
    YMTUserStatusKindTypeStudentB,
    YMTUserStatusKindTypeAuditor
};

@interface YMBigClassViewForGroupRoomAsyncData : NSObject
@property(nonatomic, assign) BOOL isCorrect; //是否批改

@property(nonatomic, assign) BOOL isCorrectOpen;   //是否展示批改面板
@property(nonatomic, assign) BOOL isAnswerParsing; //答案解析是否打开
@property(nonatomic, assign) BOOL isQuestion;      //是否开始答题

/** 记录当前选中的讲义模型 */
@property(nonatomic, strong) YMTRoomLessonPlanM *selectLessonPlanModel;
/** 记录当前选中的栏目模型 */
@property(nonatomic, strong) YMTColumnInfoItems *selectColumnInfoItem;
/** 记录当前显示题目模型 */
@property(nonatomic, strong) YMTQuestionInfoDto *selectQuestionInfoDto;
/** 记录当前显示的子体模型 */
@property(nonatomic, strong) YMTQuestionInfoDto *selectChildQuestionInfoDto;

/** 记录当前显示的题目ID */
@property(nonatomic, copy) NSString *currentQuestionID;

@end

@interface YMBigClassViewForGroupRoom : UIView
@property(nonatomic, strong) NSString *keyDocId;
@property(nonatomic, assign) NSInteger nowPage;
@property(nonatomic, assign, readonly) YMTUserStatusKindType userStatusType;

@property(nonatomic, strong) YMBigClassViewForGroupRoomAsyncData *asyncRoomData;

//业务层
@property(strong, nonatomic) id<YMWhiteBoardProtocol> whiteBoardModule;
@property (strong, nonatomic) YMCourseWareLayer *coursewareLayer;
//数据层
@property(strong, nonatomic) YMTSingleGroupDB *DB;
@property(strong, nonatomic) NSMutableArray *arrData;

@property(nonatomic, assign) BOOL is16_9version;
@property(nonatomic, assign) BOOL isResetting;
@property(nonatomic, assign) BOOL isSmallClass;

- (instancetype)initWithFrame:(CGRect)frame userStatus:(YMTUserStatusKindType)userStatus;

- (void)setHidden:(BOOL)hidden;

@end
