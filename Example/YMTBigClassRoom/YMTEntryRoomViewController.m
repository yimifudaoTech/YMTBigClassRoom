//
//  YMTClassRoomDemoViewController.m
//  student
//
//  Created by SendomZhang on 19/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMTEntryRoomViewController.h"

#import <YMTBigClassRoom/YMTHTTPSessionManager.h>
#import "NSObject+YYModel.h"
#import <QMUIKit/QMUIKit.h>
#import <YYModel/NSObject+YYModel.h>

#import <YMTBigClassRoom/YMTBigClassSDKManager.h>

static const CGFloat YMTEntryRoomViewControlleriPhoneCornerRadius = 25.0f;

@interface YMTEntryRoomViewController ()

@property (weak, nonatomic) IBOutlet QMUITextField *numTextField;
@property (weak, nonatomic) IBOutlet QMUITextField *uidtextfield;
@property (weak, nonatomic) IBOutlet QMUITextField *groupidtextfield;
@property (weak, nonatomic) IBOutlet UITextField *envInputTextField;
@property (weak, nonatomic) IBOutlet UIButton *envChangeButton;
@property (weak, nonatomic) IBOutlet UITextField *useridTextField;
@property (weak, nonatomic) IBOutlet UITextField *roomidTextField;

@end

@implementation YMTEntryRoomViewController

#pragma mark - Life Cycyle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"demo";
    
    self.numTextField.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.uidtextfield.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    self.groupidtextfield.layer.cornerRadius = YMTEntryRoomViewControlleriPhoneCornerRadius;
    
    self.numTextField.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.uidtextfield.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
    self.groupidtextfield.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
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
    
    [[YMTBigClassSDKManager shareManager] joinCloudRoomWithRoomID:self.numTextField.text userID:self.uidtextfield.text?:@"" groupId:self.groupidtextfield.text?:@""
                                                          headUrL:@"http://static.yimifudao.com/static-files/user_pics/stu_head_pic/male.png" token:@"nil" userRole:2 nickName:nickName bussinessData:@"" result:^(BOOL success, YMTRoomInfoCode code, UIViewController * _Nullable vc) {
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
    
    QMUIDialogSelectionViewController *vc = [[QMUIDialogSelectionViewController alloc] init];
    vc.items = envArray;
    vc.selectedItemIndex = [envArray indexOfObject:envString];
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
        [[YMTBigClassSDKManager shareManager] recordPlayToken:@"" viewParent:self roomID:self.numTextField.text userid:self.uidtextfield.text];
    }else {
        [QMUITips showError:@"认真点"];
    }
}

@end
