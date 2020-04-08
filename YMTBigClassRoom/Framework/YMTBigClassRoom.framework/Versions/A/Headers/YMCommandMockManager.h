//
//  YMCommandMockManager.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/10.
//

#import <Foundation/Foundation.h>

@class YMTSCSendMsgEntity;
@class YMRoomModel;

NS_ASSUME_NONNULL_BEGIN

typedef void (^YMMockCommandBlock)(YMTSCSendMsgEntity *content);


@interface YMCommandMockManager : NSObject

@property (nonatomic, copy) YMMockCommandBlock mockCommand;
@property (nonatomic, strong) YMRoomModel *roomModel;



- (void)showCommandMockView;

- (void)hideCommandMockView;

- (void)setDocId:(NSString *)docId;
@end

NS_ASSUME_NONNULL_END
