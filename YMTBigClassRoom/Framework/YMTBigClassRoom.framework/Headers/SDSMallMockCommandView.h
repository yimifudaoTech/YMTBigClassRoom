//
//  SDSMallMockCommandView.h
//  student
//
//  Created by Caffrey on 2019/5/28.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <YMTCloudClassroom/YMTSCServerHeader.h>
#import <YMTCloudClassroom/YMTSCEntityDatas.h>
#import "YMRoomModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^MockCommandBlock)(YMTSCSendMsgEntity *content);

@interface SDSMallMockCommandView : UIView

+ (void)showMockCommandViewWithRoomModel:(YMRoomModel *)model view:(UIView *)view mockCommandBlock:(MockCommandBlock)mockCommand;
+ (void)hide;
+ (void)setDocId:(NSString *)docId;

@property (nonatomic, copy) MockCommandBlock mockCommand;
@property (nonatomic, strong) YMRoomModel *roomModel;


@end

NS_ASSUME_NONNULL_END