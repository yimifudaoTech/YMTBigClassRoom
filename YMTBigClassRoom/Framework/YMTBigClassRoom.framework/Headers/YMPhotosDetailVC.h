//
//  YMPhotosDetailVC.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/25.
//

#import <UIKit/UIKit.h>
#import "YMAlbumManagerTool.h"

NS_ASSUME_NONNULL_BEGIN

@interface YMPhotosDetailVC : UIViewController

@property (nonatomic,assign) BOOL isLandscapeRight;

- (instancetype)initWithPhotoAssetCollection:(PHAssetCollection *)assetCollection;
- (instancetype)initWithPhotoPHAssets:(NSArray*)phssets;
/**
 选择好图片后回调Block
 */
@property (nonatomic,copy) void(^photosCallBack)(NSMutableArray * phassets);
// 是否选择一张图片
@property (nonatomic,assign)BOOL radio;

@end

NS_ASSUME_NONNULL_END
