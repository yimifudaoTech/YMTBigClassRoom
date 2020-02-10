//
//  YMTChatInfo.h
//  AFNetworking
//
//  Created by mystarains on 2019/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTChatInfo : NSObject

@property (nonatomic, copy) NSString *identifierNick;
@property (nonatomic, copy) NSString *headurl;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *role;
@property (nonatomic, copy) NSString *myClass;
@property (nonatomic, copy) NSString *chatRoomId;

@property (nonatomic, copy) NSString *url;

/** 获取当前对象对应的json字符串 */
- (NSString *)jsonString;


@end

NS_ASSUME_NONNULL_END
