//
//  YMFormEditModel.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMFormEditModel : NSObject

/**控件名称*/
@property (nonatomic,copy)NSString * title;
/**类型 radio、text、textView*/
@property (nonatomic,copy)NSString * type;
/**输入框placholder*/
@property (nonatomic,copy)NSString * placeHolderStr;
/**是否必填*/
@property (nonatomic,strong)NSNumber * requried;
/**枚举明细*/
@property (nonatomic,strong)NSMutableArray * enums;
/**最小值*/
@property (nonatomic,strong)NSNumber * minCount;
/**最大值*/
@property (nonatomic,strong)NSNumber * maxCount;
/**表单参数*/
@property (nonatomic,copy)NSString * name;
/**表单的参数值*/
@property (nonatomic,copy)NSString * value;
/**是否选中*/
@property (nonatomic,assign)BOOL selectedStatus;

@end

NS_ASSUME_NONNULL_END
