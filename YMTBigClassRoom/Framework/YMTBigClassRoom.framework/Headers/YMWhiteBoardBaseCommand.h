//
//  YMBaseCommand.h
//  AFNetworking
//
//  Created by yimi on 2019/10/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMWhiteBoardBaseCommand : NSObject
@property (nonatomic,strong) NSString* boardId;
@property (nonatomic,strong) NSString* itemId;
@property (nonatomic,strong) NSString* type;
@property (nonatomic,strong) NSString* pageId;
@property (nonatomic,strong) NSString* dockId;
@end

NS_ASSUME_NONNULL_END
