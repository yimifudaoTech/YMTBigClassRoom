//
//  YMFlowSettings.h
//  Pods-YMSocket_Example
//
//  Created by Caffrey on 2019/1/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMFlowSettings : NSObject

@property (readonly, class) int productID;
@property (readonly, class) NSString *cgiPath;
@property (readonly, class) int cmdId;
@property (readonly, class) int channel;

@end

NS_ASSUME_NONNULL_END
