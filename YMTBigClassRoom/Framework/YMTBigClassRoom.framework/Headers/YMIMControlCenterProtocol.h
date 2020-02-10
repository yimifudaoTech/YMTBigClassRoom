//
//  YMIMControlCenterProtocol.h
//  Pods
//
//  Created by yimi on 2019/12/27.
//

#ifndef YMIMControlCenterProtocol_h
#define YMIMControlCenterProtocol_h
#import <YMTCloudClassroom/YMTSCServerHeader.h>

@protocol YMIMControlCenterProtocol <NSObject>

- (void)sendCommand:(NSDictionary *)commandContent commandType:(YMTSCCommandConvertType)type;

@end


#endif /* YMIMControlCenterProtocol_h */
