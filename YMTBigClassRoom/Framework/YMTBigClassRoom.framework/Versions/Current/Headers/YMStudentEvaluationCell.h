//
//  YMStudentEvaluationCell.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/1/8.
//

#import <UIKit/UIKit.h>
#import "YMSystemMacro.h"

NS_ASSUME_NONNULL_BEGIN

@class YMFormEditModel;

typedef void(^evaluationEndEditCallBack)(YMFormEditModel * model);

@interface YMStudentEvaluationCell : UITableViewCell
// 列表数据模型
@property (nonatomic,strong)YMFormEditModel * evaluationModel;
// 回调Block
@property (nonatomic,copy)evaluationEndEditCallBack evaluationCellBlock;

@end

NS_ASSUME_NONNULL_END
