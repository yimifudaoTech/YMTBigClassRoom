//
//  YMWebviewNativeBridgeProtocol.h
//  YMTCloudClassroom
//
//  Created by yimi on 2020/2/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YMWebviewNativeBridgeProtocol <NSObject>

- (void)openCamera:(void(^)(BOOL result, NSString *errorMsg, NSString *imageUrl))callback;

- (void)openAlbum:(void(^)(BOOL result, NSString *errorMsg, NSString *imageUrl))callback;

@end

NS_ASSUME_NONNULL_END
