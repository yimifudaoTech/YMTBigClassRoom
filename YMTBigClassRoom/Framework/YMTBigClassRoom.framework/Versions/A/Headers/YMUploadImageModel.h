//
//  YMUploadImageModel.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMUploadImageModel : NSObject
/**
 上传的图片对象
 */
@property (nonatomic,strong) UIImage * uploadImage;

/**
 图片的路径 根据不同的课件类型定义
 */
@property (nonatomic,copy) NSString * osPath;

@end

NS_ASSUME_NONNULL_END
