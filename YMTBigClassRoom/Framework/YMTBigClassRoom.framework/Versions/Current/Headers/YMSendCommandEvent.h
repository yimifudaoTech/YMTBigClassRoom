//
//  YMSendCommandEvent.h
//  YMTBigClassRoom
//
//  Created by yimi on 2019/12/29.
//

#import <Foundation/Foundation.h>
#import "QTEventBus.h"
#import <YMTCloudClassroom/YMTSCServerHeader.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMSendCommandEvent : NSObject<QTEvent>

@property (nonatomic, strong) NSDictionary *commandContent;
@property (nonatomic, assign) YMTSCCommandConvertType commandType;

@end

NS_ASSUME_NONNULL_END
