//
//  ZQPlayerAudioView.h
//  YiMiApp
//
//  Created by 顾鹏凌 on 2016/12/9.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZQPlayerAudioView : UIView
//GPL_H_SINGLETON(ZQPlayerAudioView);
/** 注释 */
@property (copy, nonatomic) void(^ZQPlayerAudioViewPlayEndBlock)();
@end
