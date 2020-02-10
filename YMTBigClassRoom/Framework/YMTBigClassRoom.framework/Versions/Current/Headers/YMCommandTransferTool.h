//
//  YMCommandTransferTool.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/27.
//

#import <Foundation/Foundation.h>
#import <YMTCloudClassroom/YMWhiteBoardSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMCommandTransferTool : NSObject

+ (YMDrawTrailModel *)transferTrailCommandToModel:(NSDictionary *)commandDic;

+ (YMDrawGraphModel *)transferGraphCommandToModel:(NSDictionary *)commandDic;

+ (YMDrawImageModel *)transferImageCommandToModel:(NSDictionary *)commandDic;

+ (NSMutableDictionary *)transferTrailModelToCommand:(YMDrawTrailModel *)trailModel;

+ (NSMutableDictionary *)transferGraphModelToCommand:(YMDrawGraphModel *)graphModel;

+ (NSMutableDictionary *)transferImageModelToCommand:(YMDrawImageModel *)imageModel;


@end

NS_ASSUME_NONNULL_END
