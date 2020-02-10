//
//  SKRoomDeviceTestNetView.h
//  SKDemo
//
//  Created by Yangsenkai on 2017/7/4.
//  Copyright © 2017年 yangsenkai. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^YMRoomDeviceNetCallBack)(BOOL finished);

@interface YMRoomDeviceTestNetView : UIView

@property (nonatomic, copy) NSString *detectAddress;

+ (instancetype)roomDeviceTestNetView;

- (void)showRoomDeviceTestNetViewSuccess:(YMRoomDeviceNetCallBack)callBack;

- (void)doDetectTask;

@end
