//
//  UIViewController+ImagePicker.h
//  navyblue
//
//  Created by xieyan on 15/9/11.
//  Copyright (c) 2015年 xieyan. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef  NS_ENUM(NSInteger, XYZImagePickerType){
    XYZImagePickerTypePhoto,
    XYZImagePickerTypeAlbum,
//    XYZImagePickerType,
//    XYZImagePickerType,
};
static NSString* XYZImagePickerImageKey = @"XYZImagePickerImageKey";
static NSString* XYZImagePickerBase64Key = @"XYZImagePickerBase64Key";
static NSString* XYZImagePickerImageTypeKey = @"XYZImagePickerImageTypeKey";



@interface UIViewController (UIViewController_ImagePicker)<UIImagePickerControllerDelegate,UINavigationControllerDelegate>
@property(nonatomic,strong)UIImagePickerController* XYZImagePicker;
@property(nonatomic,strong)void(^XYZImagePickerResponse)(id response);
-(void)XYZpresentImagePickertype:(XYZImagePickerType)type CallBack:(void(^)(id message))callback;

-(void)XYZMediaSelectAlbum:(void(^)(id message))album Photo:(void(^)(id message))photo Audio:(void(^)(id message))audio Vedio:(void(^)(id message))vedio;


//-(void)XYZMediaSelectAlbum:(void (^)(id))album;
//-(void)XYZMediaSelectPhoto:(void(^)(id message))photo;
//-(void)XYZMediaSelectAudio:(void(^)(id message))audio;

@end