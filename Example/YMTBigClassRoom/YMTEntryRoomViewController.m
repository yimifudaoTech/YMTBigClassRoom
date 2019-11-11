//
//  YMTClassRoomDemoViewController.m
//  student
//
//  Created by SendomZhang on 19/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMTEntryRoomViewController.h"

#import <YMTBigClassRoom/SDSCMineCatalogGOModel.h>
#import <YMTBigClassRoom/YMTHTTPSessionManager.h>
#import "NSObject+YYModel.h"
#import <QMUIKit/QMUIKit.h>
#import <YYModel/NSObject+YYModel.h>
#import <ReactiveObjC/ReactiveObjC.h>

#import <YMTBigClassRoom/YMTBigClassSDKManager.h>

static const CGFloat YMTEntryRoomViewControlleriPhoneCornerRadius = 25.0f;
static NSString * const YMTUserDefaultKey_LessonId = @"YMTUserDefaultKey_LessonId";
#define APP_ID_JUREN @"7169a6c5ab5b4eeba2ca37b831fb9239"
#define APP_KEY_JUREN @"fTvEfrTdSsP3uqZj"

// 精锐1v1
#define APP_ID_JINGRUI @"kiFBIeLYvxOuWFgwWOy1XFFFehdA2ovo"
#define APP_KEY_JINGRUI @"L6X0TIPFLQGkwEKM";

@interface YMTEntryRoomViewController ()

@property (weak, nonatomic) IBOutlet QMUITextField *numTextField;
@property (weak, nonatomic) IBOutlet QMUITextField *uidtextfield;
@property (weak, nonatomic) IBOutlet QMUITextField *groupidtextfield;
@property (weak, nonatomic) IBOutlet UITextField *envInputTextField;
@property (weak, nonatomic) IBOutlet UIButton *envChangeButton;
@property (weak, nonatomic) IBOutlet UITextField *useridTextField;
@property (weak, nonatomic) IBOutlet UITextField *roomidTextField;
@property (weak, nonatomic) IBOutlet UIButton *enterRoomButton;
@property (weak, nonatomic) IBOutlet UIButton *recorderButtom;
@property (nonatomic, assign)NSInteger classRoomType;
@property (weak, nonatomic) IBOutlet UIButton *coursewareButton;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;

@end

@implementation YMTEntryRoomViewController

#pragma mark - Life Cycyle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"demo";
    self.classRoomType = 0;
    self.numTextField.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.uidtextfield.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.groupidtextfield.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    
    self.numTextField.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.uidtextfield.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.groupidtextfield.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    NSString *lessonId = [[NSUserDefaults standardUserDefaults]objectForKey:YMTUserDefaultKey_LessonId];
    if(lessonId) {
        self.numTextField.text = lessonId;
    }
    self.numTextField.text = @"377038947370405888";
    self.versionLabel.text = [NSString stringWithFormat:@"v%@", [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]];
    RACSignal<NSNumber *> *roomIDEnable = [self.numTextField.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return @(value.length ? YES : NO);
    }];
    
    RACSignal<NSNumber *> *IDEnable = [self.uidtextfield.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return @(value.length ? YES : NO);
    }];
    
    RACSignal<NSNumber *> *groupIDEnable = [self.groupidtextfield.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return @(value.length ? YES : NO);
    }];
    
    RACSignal<NSNumber *> *enterRoomEnable = [RACSignal combineLatest:@[ roomIDEnable, IDEnable, groupIDEnable ] reduce:^(NSNumber * roomIDEnable, NSNumber *IDEnable, NSNumber *groupIDEnable) {
        return @(roomIDEnable.boolValue && IDEnable.boolValue && groupIDEnable.boolValue);
     }];
    
    RACSignal<NSNumber *> *recorderEnable = [RACSignal combineLatest:@[roomIDEnable, IDEnable] reduce:^(NSNumber * roomIDEnable, NSNumber *IDEnable) {
        return @(roomIDEnable.boolValue && IDEnable.boolValue);
     }];
    
    RACSignal<NSNumber *> * viewCourseWareEnable = [RACSignal combineLatest:@[roomIDEnable, IDEnable] reduce:^(NSNumber * roomIDEnable, NSNumber *IDEnable) {
       return @(roomIDEnable.boolValue && IDEnable.boolValue);
    }];
    
    RAC(self.enterRoomButton, enabled) = enterRoomEnable;
    RAC(self.recorderButtom, enabled) = recorderEnable;
    RAC(self.coursewareButton, enabled) = viewCourseWareEnable;
    
    [self initClassRoom];
}

- (void)viewWillAppear:(BOOL)animated {
    NSString *envString = [YMTHTTPSessionManager shareManager].envString;
    self.envInputTextField.text = envString;
}

- (BOOL)shouldAutorotate {
    return YES;
}

//返回支持的方向
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskLandscape;
}

#pragma mark - Delegate

#pragma mark UITextFieldDelegate

- (void)textFieldDidBeginEditing:(UITextField *)textField {
    textField.layer.borderWidth = 1;
    textField.layer.borderColor = UIColorMakeWithHex(@"#ff5500").CGColor;
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
    textField.layer.borderColor = [UIColor clearColor].CGColor;
}

#pragma mark - Action Method

- (IBAction)entryAction:(id)sender {
    if (!self.numTextField.text.length) {
        [QMUITips showInfo:@"房间号为空" inView:self.view hideAfterDelay:1.0];
        return;
    }
    [QMUITips showLoadingInView:self.view];
    
    NSString *nickName = [NSString stringWithFormat:@"iOS-%@",self.uidtextfield.text?:@"-"];
    
    [[NSUserDefaults standardUserDefaults] setObject:self.numTextField.text forKey:YMTUserDefaultKey_LessonId];
    [[YMTBigClassSDKManager shareManager] joinCloudRoomWithRoomID:self.numTextField.text userID:self.uidtextfield.text?:@"" groupId:self.groupidtextfield.text?:@""
                                                          headUrL:@"http://static.yimifudao.com/static-files/user_pics/stu_head_pic/male.png" userRole:2 nickName:nickName bussinessData:@"" result:^(BOOL success, YMTRoomInfoCode code, UIViewController * _Nullable vc) {

                                                              [QMUITips hideAllTips];
                                                              if (!success) {
                                                                  [QMUITips showError:@"进入失败"];
                                                              }
                                                              
        if (vc) {
            NSLog(@"成功！");
        }
    }];
}

- (IBAction)envChangeAction:(id)sender {

    NSString *envString = [YMTHTTPSessionManager shareManager].envString;
    NSArray *envArray = @[@"Release", @"Sit01"];
    
    __block QMUIDialogSelectionViewController *vc = [[QMUIDialogSelectionViewController alloc] init];
    vc.items = envArray;
    vc.selectedItemIndex = [envArray indexOfObject:envString];
      __weak typeof(vc) weakVC = vc;
    vc.didSelectItemBlock = ^(__kindof QMUIDialogSelectionViewController * _Nonnull aDialogViewController, NSUInteger itemIndex) {
        [YMTHTTPSessionManager.shareManager changeEnv:aDialogViewController.items[itemIndex]];
        [QMUITips showInfo:@"即将关闭，重新启动"];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            exit(0);
        });
    };
    [vc show];

}

- (IBAction)recordedButton:(id)sender {

    if (!self.numTextField.text.length && self.uidtextfield.text.length) {

        BOOL isSucc = [[YMTBigClassSDKManager shareManager] wasRecordedFilesDeletedSuccessfullyWithUserid:self.uidtextfield.text];

        [QMUITips showError:isSucc ?@"删除成功":@"删除失败"];
        return;
    }

    if (self.numTextField.text.length && self.uidtextfield.text.length) {
        [[YMTBigClassSDKManager shareManager] recordPlayToken:self roomID:self.numTextField.text userid:self.uidtextfield.text];
    }else {
        [QMUITips showError:@"请输入相关参数"];
    }
}

- (IBAction)switchRoomType:(id)sender {

    NSArray *envArray = @[@"1对1", @"大班课"];
    
    QMUIDialogSelectionViewController *vc = [[QMUIDialogSelectionViewController alloc] init];
    vc.items = envArray;
    __weak typeof(vc) weakVC = vc;
    __weak typeof(self) weakSelf = self;
    vc.selectedItemIndex = self.classRoomType;
    vc.didSelectItemBlock = ^(__kindof QMUIDialogSelectionViewController * _Nonnull aDialogViewController, NSUInteger itemIndex) {
        weakSelf.classRoomType = itemIndex;
        [weakSelf initClassRoom];
        [weakVC hide];
    };
    [vc show];
}

- (void)initClassRoom {
    NSString *appId = APP_ID_JINGRUI;
    NSString *appKey = APP_KEY_JINGRUI;
    if(self.classRoomType != 0){
        appId = APP_ID_JUREN;
        appKey = APP_KEY_JUREN;
    }
    [[YMTBigClassSDKManager shareManager]registerSDKWithAppID:appId AppKey:appKey result:^(BOOL success, YMTRoomInfoCode code) {
        
    }];
    [[YMTBigClassSDKManager shareManager]enableCrashReport:YES];
}


// 查看课件
- (IBAction)coursewareButtonAction:(id)sender {
    if (self.numTextField.text.length && self.uidtextfield.text.length) {
        [QMUITips showLoadingInView:self.view];
        [[YMTBigClassSDKManager shareManager] courseWare:self roomId:self.numTextField.text userId:self.uidtextfield.text result:^(BOOL success, YMTRoomInfoCode code, NSString * _Nullable errorMessage) {
            [QMUITips hideAllTips];
            if (!success) {
                [QMUITips showError:errorMessage];
            }
        }];
    }else {
        [QMUITips showError:@"请输入相关参数"];
    }
}

@end
