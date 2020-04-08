//
//  YMCloudClassroomInfo.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/18.
//


#import <Foundation/Foundation.h>
#import "YMRoomModel.h"

@interface YMCloudClassroomInfo : NSObject

@property (nonatomic, strong) NSString *roomId;
@property (nonatomic, assign) YMClassRoomType classType;
@property (nonatomic, strong) NSString *serverIp;

@end
