//
//  YMAuthCommand.h
//  AFNetworking
//
//  Created by yimi on 2019/10/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMAuthCommand : NSObject
@property (nonatomic,strong) NSString* uid;
@property (nonatomic,strong) NSString* up;
@property (nonatomic,strong) NSString* trail;
@property (nonatomic,strong) NSString* audio;
@property (nonatomic,strong) NSString* video;

@end

NS_ASSUME_NONNULL_END
