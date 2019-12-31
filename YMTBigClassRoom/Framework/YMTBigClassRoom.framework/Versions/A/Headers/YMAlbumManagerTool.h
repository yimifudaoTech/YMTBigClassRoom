//
//  YMAlbumManagerTool.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/25.
//

// 获取系统相册照片
#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

NS_ASSUME_NONNULL_BEGIN

// 组照片回调
typedef void(^photoGroupCallBack)(NSArray* photoGroups);

@interface YMAlbumManagerTool : NSObject

+ (instancetype)shareAlbumManager;

- (void)getAllPictureGroups:(photoGroupCallBack)groupsCallBack;

/**
 获取某个相册的所有照片
 */
- (NSArray *)getAllPHAssetWithAssetCollection:(PHAssetCollection*)assetCollection;

/**
 获取系统的所有照片不分组
 */
- (void)getAllPHAssetFromAlbum:(void(^)(NSMutableArray * phassets))allPhassetCallback;
- (void)getShowImageSize:(CGSize)targetSize PHAsset:(PHAsset *)asset resultHandler:(void(^)(UIImage * image))resultHandler;
- (void)getImageWithCachingImageManager:(PHCachingImageManager *)imageManager phAsset:(PHAsset *)asset targetSize:(CGSize)targetSize resultHandler:(void(^)(UIImage * image))resultHandler;
/**
 选择的照片 PHAsset
 */
@property (nonatomic,strong) NSMutableArray * selectArray;

@end

NS_ASSUME_NONNULL_END
