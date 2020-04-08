//
//  TestToolCollectionViewCell.h
//  YMTBigClassRoom
//
//  Created by yimi on 2020/3/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestToolCollectionViewCell : UICollectionViewCell
@property (unsafe_unretained, nonatomic) IBOutlet UILabel *nameLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UISwitch *stateSwitch;

@end

NS_ASSUME_NONNULL_END
