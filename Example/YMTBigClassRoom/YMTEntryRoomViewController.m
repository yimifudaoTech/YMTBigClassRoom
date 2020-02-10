//
//  YMTClassRoomDemoViewController.m
//  student
//
//  Created by SendomZhang on 19/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMTEntryRoomViewController.h"
#import <YMTBigClassRoom/YMRoomModel.h>
#import <YMTBigClassRoom/YMTHTTPSessionManager.h>
#import "NSObject+YYModel.h"
#import <QMUIKit/QMUIKit.h>
#import <YYModel/NSObject+YYModel.h>
#import <ReactiveObjC/ReactiveObjC.h>
#import <YMTBigClassRoom/YMTBigClassSDKManager.h>

static const CGFloat YMTEntryRoomViewControlleriPhoneCornerRadius = 25.0f;
static NSString * const YMTUserDefaultKey_LessonId = @"YMTUserDefaultKey_LessonId";
#define APP_ID_JUREN @""
#define APP_KEY_JUREN @""

// 精锐1v1
#define APP_ID_JINGRUI @""
#define APP_KEY_JINGRUI @""
// 溢米
#define APP_ID_YIMI @""
#define APP_KEY_YIMI @""

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
@property (weak, nonatomic) IBOutlet UIButton *loginButton;
@property (weak, nonatomic) IBOutlet QMUITextField *adtUserIdentity;
@property (nonatomic,copy) NSString * token;
@property (nonatomic,assign) YMRoleType roleType;
@property (nonatomic,strong) NSString *identityType;

@end

@implementation YMTEntryRoomViewController

#pragma mark - Life Cycyle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"demo";
    self.roleType = YMRoleTypeStudent;
    self.identityType = @"学生";
    self.classRoomType = 0;
    self.numTextField.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.uidtextfield.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.adtUserIdentity.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.groupidtextfield.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    
    self.numTextField.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.uidtextfield.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.adtUserIdentity.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.groupidtextfield.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    NSString *lessonId = [[NSUserDefaults standardUserDefaults]objectForKey:YMTUserDefaultKey_LessonId];
    if(lessonId) {
        self.numTextField.text = lessonId;
    }
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
- (IBAction)roleSwitchAction:(UIButton *)sender {
    NSArray *envArray = @[@"学生",@"旁听"];
    __block QMUIDialogSelectionViewController *roleVc = [[QMUIDialogSelectionViewController alloc] init];
    roleVc.items = envArray;
    __weak typeof(roleVc) weakRoleVC = roleVc;
    roleVc.didSelectItemBlock = ^(__kindof QMUIDialogSelectionViewController * _Nonnull aDialogViewController, NSUInteger itemIndex) {
        switch (itemIndex) {
            case 0:
                self.roleType = YMRoleTypeStudent;
                [sender setTitle:@"角色：学生" forState:UIControlStateNormal];
                break;
            case 1:
                self.roleType = YMRoleTypeAudit;
                [sender setTitle:@"角色：旁听" forState:UIControlStateNormal];
                break;
            default:
                break;
        }
        [weakRoleVC hide];
    };
    [roleVc show];
}
- (IBAction)identityAction:(UIButton *)sender {
    NSArray *envArray = @[@"学生",@"家长"];
    __block QMUIDialogSelectionViewController *roleVc = [[QMUIDialogSelectionViewController alloc] init];
    roleVc.items = envArray;
    __weak typeof(roleVc) weakRoleVC = roleVc;
    roleVc.didSelectItemBlock = ^(__kindof QMUIDialogSelectionViewController * _Nonnull aDialogViewController, NSUInteger itemIndex) {
        switch (itemIndex) {
            case 0:
                self.identityType = @"学生";
                [sender setTitle:@"身份：学生" forState:UIControlStateNormal];
                break;
            case 1:
                self.identityType = @"家长";
                [sender setTitle:@"身份：家长" forState:UIControlStateNormal];
                break;
            default:
                break;
        }
        [weakRoleVC hide];
    };
    [roleVc show];
}

- (IBAction)entryAction:(id)sender {
    if (!self.numTextField.text.length) {
        [QMUITips showInfo:@"房间号为空" inView:self.view hideAfterDelay:1.0];
        return;
    }
    [QMUITips showLoadingInView:self.view];
    
    NSString *nickName = [NSString stringWithFormat:@"iOS-%@",self.uidtextfield.text?:@"-"];
    
    [[NSUserDefaults standardUserDefaults] setObject:self.numTextField.text forKey:YMTUserDefaultKey_LessonId];

    YMSDKUserInfo *userModel = [[YMSDKUserInfo alloc]init];
    userModel.roomID = self.numTextField.text;
    userModel.token = self.token;
    userModel.userID = self.uidtextfield.text?:@"";
    userModel.groupId = self.groupidtextfield.text?:@"";
    userModel.headUrl = @"http://static.yimifudao.com/static-files/user_pics/stu_head_pic/male.png";
    userModel.role = self.roleType;
    userModel.identity = self.identityType;
    userModel.nickName = nickName;
    userModel.bussinessData = @"";
    userModel.relatedUserId = self.adtUserIdentity.text?:@"";
    userModel.userIdentity = self.roleType==YMRoleTypeAudit?userModel.userID:@"";

    [[YMTBigClassSDKManager shareManager] joinCloudRoom:userModel appViewController:self result:^(BOOL success, YMTRoomInfoCode code, UIViewController * _Nullable vc) {
        [QMUITips hideAllTips];
        if (!success) {
//            [QMUITips showError:@"进入失败"];
        }
        if (vc) {
            NSLog(@"成功！");
        }
    }];
}

- (IBAction)envChangeAction:(id)sender {
    NSString *envString = [YMTHTTPSessionManager shareManager].envString;
    NSArray *envArray = @[@"Release", @"Sit01", @"Sit03"];
    NSArray *envEnumArray = @[@(YMTRoomEnvironment_Release), @(YMTRoomEnvironment_Sit01), @(YMTRoomEnvironment_Sit03)];
    
    __block QMUIDialogSelectionViewController *vc = [[QMUIDialogSelectionViewController alloc] init];
    vc.items = envArray;
    vc.selectedItemIndex = [envArray indexOfObject:envString];
    vc.didSelectItemBlock = ^(__kindof QMUIDialogSelectionViewController * _Nonnull aDialogViewController, NSUInteger itemIndex) {
        YMTRoomEnvironment env = [envEnumArray[itemIndex] unsignedIntegerValue];
        [[YMTBigClassSDKManager shareManager]setSwitchEnv:env];
        [QMUITips showInfo:@"即将关闭，重新启动"];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            exit(0);
        });
    };
    [vc show];

}

- (IBAction)recordedButton:(id)sender {
    if (!self.numTextField.text.length && self.uidtextfield.text.length) {
        BOOL isSucc = [[YMTBigClassSDKManager shareManager] clearCache:self.uidtextfield.text];
        [QMUITips showError:isSucc ?@"删除成功":@"删除失败"];
        return;
    }
    if (self.numTextField.text.length && self.uidtextfield.text.length) {
        [[YMTBigClassSDKManager shareManager] recordPlay:self roomID:self.numTextField.text token:self.token userid:self.uidtextfield.text];
    }else {
        [QMUITips showError:@"请输入相关参数"];
    }
}

- (IBAction)switchRoomType:(id)sender {
    NSArray *envArray = @[@"精锐", @"巨人", @"溢米"];
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
    if(self.classRoomType == 1){
        appId = APP_ID_JUREN;
        appKey = APP_KEY_JUREN;
    }else if (self.classRoomType == 2) {
        appId = APP_ID_YIMI;
        appKey = APP_KEY_YIMI;
    }
    [[YMTBigClassSDKManager shareManager]registerSDKWithAppID:appId AppKey:appKey result:^(BOOL success, YMTRoomInfoCode code) {
        
    }];
    [[YMTBigClassSDKManager shareManager]enableCrashReport:YES];
}


// 查看课件
- (IBAction)coursewareButtonAction:(id)sender {
    if (self.numTextField.text.length && self.uidtextfield.text.length) {
        [QMUITips showLoadingInView:self.view];
        [[YMTBigClassSDKManager shareManager] courseWare:self roomId:self.numTextField.text token:self.token userId:self.uidtextfield.text result:^(BOOL success, YMTRoomInfoCode code, NSString * _Nullable errorMessage) {
            [QMUITips hideAllTips];
            if (!success) {
                [QMUITips showError:errorMessage];
            }
        }];
    }else {
        [QMUITips showError:@"请输入相关参数"];
    }
}
// 登录
- (IBAction)loginButtonAction:(id)sender {
    if (!self.uidtextfield.text.length) {
        [QMUITips showError:@"请输入相关参数"];
        return;
    }
    [[YMTBigClassSDKManager shareManager] loginWithUserID:self.uidtextfield.text result:^(BOOL success, YMTRoomInfoCode code, NSString * _Nullable token) {
        if (success) {
            self.token = token;
            [QMUITips showSucceed:@"登录成功"];
        }else {
            if (code == YMRoomErrorCode_Common_NetworkError) {
                [QMUITips showError:@"当前无网络，请检查网络连接"];
            }else if (code == YMRoomErrorCode_Common_AppIdNotMatch) {
                [QMUITips showError:@"机构不存在"];
            }else if (code == YMRoomErrorCode_MethodCall_Bad_Parameters) {
                [QMUITips showError:@"参数错误"];
            }else {
                [QMUITips showError:@"获取Token失败"];
            }
        }
    }];
}

@end
