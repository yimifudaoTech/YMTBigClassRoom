//
//  YMTRedPackageView.h
//  AFNetworking
//
//  Created by SendomZhang on 2/9/2019.
//

#import <UIKit/UIKit.h>

@class YMTRedPackageGetCount;

NS_ASSUME_NONNULL_BEGIN

@interface YMTRedPackageView : UIView

/*
 param 里面是抢红包需要的
 {
 "token": "xxxxx",
 "version": "v1",
 "lid": "12345",
 "uid": "678910",
 "redPacketNum": 1,// 红包id
 "currentPacketNum":2,// 当前红包id
 "groupId":1
 }
 */

- (instancetype)initWithBeginTimer:(NSTimeInterval)beginTimer redPackageRainTimer:(NSTimeInterval)rainTimer param:(NSDictionary *)param;

- (void)hiddenRedPackage;

/// 如何获取红包数量策略类
@property (nonatomic, strong, readwrite) YMTRedPackageGetCount *getCountTool;

@end

NS_ASSUME_NONNULL_END
