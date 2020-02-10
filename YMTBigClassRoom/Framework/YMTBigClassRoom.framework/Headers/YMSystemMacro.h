//
//  YMSystemMacro.h
//  YiMiApp
//
//  Created by xieyan on 15/9/15.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#ifndef YiMiApp_Macro_System_h
#define YiMiApp_Macro_System_h
#define Device [UIDevice currentDevice]
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 屏幕尺寸
#define KScreenW [UIScreen mainScreen].bounds.size.width

#define KScreenH [UIScreen mainScreen].bounds.size.height
/*****************  屏幕适配  ******************/
#define iphoneX (KScreenH == 812)
#define iphone6p (KScreenH == 736)
#define iphone6 (KScreenH == 667)
#define iphone5 (KScreenH == 568)
#define iphone4 (KScreenH == 480)
#define SafeAreaTopHeight (KScreenH == 812.0 ? 88 : 64)
#define SafeAreaBottomHeight ([UIScreen mainScreen].bounds.size.height == 812.0 ? 34 : 0)

#define KIsFourScreen ([[kUserInfo platform] isEqualToString:@"iPhone 5"] || [[kUserInfo platform] isEqualToString:@"iPhone 5c"] || [[kUserInfo platform] isEqualToString:@"iPhone 5s"] || [[kUserInfo platform] isEqualToString:@"iPhone SE"]) ? 1 : 0

#define kisAboveiPhoneX [XYZSystemInfo isAboveiPhoneX]

// 屏幕尺寸
#define RSScreenW [UIScreen mainScreen].bounds.size.width
#define RSScreenH [UIScreen mainScreen].bounds.size.height

#define IsIOS8 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0 ? YES : NO)
//获得屏幕的宽高
#define  kScreenWidth  (IsIOS8 ? [UIScreen mainScreen].bounds.size.width : [UIScreen mainScreen].bounds.size.height)
#define  kScreenHeight (IsIOS8 ? [UIScreen mainScreen].bounds.size.height : [UIScreen mainScreen].bounds.size.width)


// 获取Dock的高度
#define kDockHeight(orientation) (UIInterfaceOrientationIsLandscape(orientation)?kScreenWidth:(kScreenHeight - 20))


#endif
