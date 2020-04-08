//
//  YMTPlaceholderTextView.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/1/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMTPlaceholderTextView : UITextView

/**占位文字*/
@property (nonatomic,copy)NSString * placeholder;
/**占位文字颜色*/
@property (nonatomic,strong)UIColor * placeholderColor;

@end

NS_ASSUME_NONNULL_END
