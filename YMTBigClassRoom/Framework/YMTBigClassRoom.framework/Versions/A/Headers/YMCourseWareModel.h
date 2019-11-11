//
//  YMCourseWareModel.h
//  YMTBigClassRoom
//
//  Created by juwanli on 2019/10/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMCourseWareModel : NSObject

// 课件Id
@property (nonatomic,copy)NSString * courseId;
// 名称
@property (nonatomic,copy)NSString * name;
// 课件类型
@property (nonatomic,copy)NSString * docType;
// 路径
@property (nonatomic,copy)NSString * path;
// 日期
@property (nonatomic,copy)NSString * date;

@property (nonatomic,strong)NSNumber * type;

@property (nonatomic,strong)NSNumber * endPage;

@property (nonatomic,strong)NSNumber * totalPage;

@property (nonatomic,strong)NSNumber * status;

@property (nonatomic,copy)NSString * jsonData;

@property (nonatomic,copy)NSString * tgtUrl;

@end

NS_ASSUME_NONNULL_END
