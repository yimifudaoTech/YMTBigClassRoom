//
//  YMMockView.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/10.
//

#import <UIKit/UIKit.h>
#import <YMTCloudClassroom/YMTSCServerHeader.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMMockView : NSObject

@property (nonatomic, copy) void(^mockCommandSelectBlock)(YMTSCCommandConvertType commandType, NSString *actionType);
@property (nonatomic, strong)NSMutableArray *dataSource;

- (void)showFloatMockBtn;

- (void)hideView;

@end

NS_ASSUME_NONNULL_END
