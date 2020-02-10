//
//  YMWhiteBoardEvent.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/1/2.
//

#import <Foundation/Foundation.h>
#import "QTEventBus.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMWhiteBoardEventType) {
    YMWhiteBoardEventType_PageChange
};



@interface YMWhiteBoardEvent<ObjectType> : NSObject<QTEvent>

@property (nonatomic, assign) YMWhiteBoardEventType eventType;

@property (nonatomic, strong) NSMutableDictionary* eventContent;

+ (instancetype)eventWithType:(YMWhiteBoardEventType)type andContent:(NSMutableDictionary *)content;
@end

NS_ASSUME_NONNULL_END
