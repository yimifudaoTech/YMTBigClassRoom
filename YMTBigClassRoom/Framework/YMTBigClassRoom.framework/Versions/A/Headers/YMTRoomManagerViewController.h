//
//  YMTRoomManagerViewController.h
//  student
//
//  Created by mac on 2019/7/9.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SDSCMineCatalogGOModel.h"


NS_ASSUME_NONNULL_BEGIN

@interface YMTRoomManagerViewController : UIViewController

@property (strong, nonatomic) SDSCMineGoAgoraRoomModel *roomModel;

- (void)openRoom;

- (void)setVideoInitPosition:(CGSize)position;

- (void)setRoomViewPosition:(CGSize)position;

- (void)enableWhiteBoard:(BOOL)enable;

- (void)enableCourseWare:(BOOL)enable;

- (void)enableAudio:(BOOL)enable;

- (void)enableVideo:(BOOL)enable;

- (void)enableToolbar:(BOOL)enable;

- (void)exit;

- (void)getRoomView;

@end

NS_ASSUME_NONNULL_END
