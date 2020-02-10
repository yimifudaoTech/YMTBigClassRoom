//
//  windowUpdateCommand.h
//  AFNetworking
//
//  Created by yimi on 2019/10/23.
//

#import "YMWhiteBoardBaseCommand.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMWindowUpdateCommandType) {
    YMWindowUpdateCommandTypeMove,
    YMWindowUpdateCommandTypeMin,
    YMWindowUpdateCommandTypeClose,
    YMWindowUpdateCommandTypeMax
};

static NSDictionary <NSString * ,NSNumber *> * YMWindowUpdateCommandTypeAndNameDictionary() {
    static NSDictionary *_commandTypeDictionary;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _commandTypeDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
                                  @(YMWindowUpdateCommandTypeMove),         @"move",
                                  @(YMWindowUpdateCommandTypeMin),          @"min",
                                  @(YMWindowUpdateCommandTypeClose),        @"close",
                                  @(YMWindowUpdateCommandTypeMax),          @"max",
                                  nil];
    });
    
    return _commandTypeDictionary;
};

@interface YMWindowUpdateCommand : YMWhiteBoardBaseCommand
@property (nonatomic,strong) NSString* recWidth;
@property (nonatomic,strong) NSString* recHeight;
@property (nonatomic,strong) NSString* recX;
@property (nonatomic,strong) NSString* recY;

- (double)getRecWidthValue;

- (double)getRecHeightValue;

- (double)getRecXValue;

- (double)getRecYValue;

- (YMWindowUpdateCommandType)getTypeValue;

@end

NS_ASSUME_NONNULL_END
