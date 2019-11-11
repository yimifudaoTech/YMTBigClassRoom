//
//  YMTViewController.m
//  YMTCloudClassroom
//
//  Created by zhangqian on 07/30/2019.
//  Copyright (c) 2019 zhangqian. All rights reserved.
//

#import "YMTLoginViewController.h"

//#import "YMTHTTPSessionManager.h"
#import <YMTBigClassRoom/YMTHTTPSessionManager.h>
#import <YMTBigClassRoom/YMTBigClassSDKManager.h>

#import <QMUIKit/QMUIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <coobjc/coobjc.h>
#import <ReactiveObjC/ReactiveObjC.h>

#import <CommonCrypto/CommonDigest.h>

#import <Masonry/Masonry.h>

@interface YMTLoginViewController ()<UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet QMUITextField *accountTextField;
@property (weak, nonatomic) IBOutlet QMUITextField *pswTestField;
@property (weak, nonatomic) IBOutlet UIButton *loginButton;
@property (weak, nonatomic) IBOutlet UILabel *tostLabel;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;
@property (weak, nonatomic) IBOutlet UIImageView *logoImgView;
@property (weak, nonatomic) IBOutlet UIButton *logoBtn;
@property (weak, nonatomic) IBOutlet UIView *rightView;
@property (weak, nonatomic) IBOutlet UIImageView *loginLogo;

@end

@implementation YMTLoginViewController

#pragma mark - LifeCycle
- (void)viewDidLoad {
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.accountTextField.layer.cornerRadius = 27.0f;
    self.pswTestField.layer.cornerRadius = 27.0f;
    
    self.accountTextField.textInsets = UIEdgeInsetsMake(0, 20, 0, 0);
    self.pswTestField.textInsets = UIEdgeInsetsMake(0, 20, 0, 0);
    
    NSString *account = [[NSUserDefaults standardUserDefaults] objectForKey:@"account"];
    NSString *psw = [[NSUserDefaults standardUserDefaults] objectForKey:@"psw"];
    if (account) {
        self.accountTextField.text = account;
    }
    if (psw) {
        self.pswTestField.text = psw;
    }

    [self bindRAC];
    
    self.logoImgView.contentMode = UIViewContentModeLeft | UIViewContentModeScaleAspectFit;
}

- (void)viewDidLayoutSubviews{
    [super viewDidLayoutSubviews];
    
    @weakify(self);
    [self.logoImgView mas_makeConstraints:^(MASConstraintMaker *make) {
       
        make.left.top.bottom.mas_equalTo(0);
        make.width.mas_equalTo(self.view.qmui_width * 0.5);
    }];
    
    [self.rightView mas_makeConstraints:^(MASConstraintMaker *make) {
       
        make.left.equalTo(self.logoImgView.mas_right);
        make.top.bottom.right.mas_equalTo(0);
    }];
    
    [self.loginLogo mas_makeConstraints:^(MASConstraintMaker *make) {
        
        if(IS_IPHONE){
            
            make.top.mas_equalTo(10);
            make.width.height.mas_equalTo(40);
        }else if(IS_IPAD){
            
            make.top.mas_equalTo(60);
            make.width.mas_equalTo(140);
            make.height.mas_equalTo(94);
        }
        make.centerX.equalTo(self.rightView).mas_equalTo(0);
    }];

    [self.logoBtn mas_makeConstraints:^(MASConstraintMaker *make) {
       
        make.left.right.width.height.equalTo(self.loginLogo);
    }];
    
    [self.accountTextField mas_makeConstraints:^(MASConstraintMaker *make) {
       
        if(IS_IPHONE){
            
            make.top.equalTo(self.loginLogo.mas_bottom).mas_equalTo(20);
            make.left.mas_equalTo(40);
            make.right.mas_equalTo(-40);
        }else if(IS_IPAD){
            make.top.equalTo(self.loginLogo.mas_bottom).mas_equalTo(110);
            make.left.mas_equalTo(80);
            make.right.mas_equalTo(-80);
        }
        make.height.mas_equalTo(53);
    }];
    
    [self.pswTestField mas_makeConstraints:^(MASConstraintMaker *make) {
        
        if(IS_IPHONE){
            
            make.top.equalTo(self.accountTextField.mas_bottom).mas_equalTo(20);
            make.left.mas_equalTo(40);
            make.right.mas_equalTo(-40);
        }else if(IS_IPAD){
            make.top.equalTo(self.accountTextField.mas_bottom).mas_equalTo(20);
            make.left.mas_equalTo(80);
            make.right.mas_equalTo(-80);
        }
        make.height.mas_equalTo(53);
    }];
    
    [self.loginButton mas_makeConstraints:^(MASConstraintMaker *make) {
       
        if(IS_IPHONE){
            
            make.top.equalTo(self.pswTestField.mas_bottom).mas_equalTo(20);
            make.left.mas_equalTo(40);
            make.right.mas_equalTo(-40);
        }else if(IS_IPAD){
            make.top.equalTo(self.pswTestField.mas_bottom).mas_equalTo(54);
            make.left.mas_equalTo(80);
            make.right.mas_equalTo(-80);
        }
        make.height.mas_equalTo(56);
    }];
    
    [self.tostLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.top.equalTo(self.loginButton.mas_bottom).mas_equalTo(10);
        make.centerX.equalTo(self.logoBtn);
    }];
    
    [self.versionLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        
        make.bottom.mas_equalTo(-10);
        make.centerX.equalTo(self.rightView).mas_equalTo(0);
    }];
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

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [self loginAction:nil];
    return YES;
}

#pragma mark - Action Method

#pragma mark Button Action

- (IBAction)loginButtonClick:(id)sender {

    //显示弹出框列表选择
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"选择环境"
                                                                   message:@"溢米辅导·云教室"
                                                            preferredStyle:UIAlertControllerStyleActionSheet];

    UIAlertAction* sitOneAction = [UIAlertAction actionWithTitle:@"SIT01" style:UIAlertActionStyleDefault
                                                         handler:^(UIAlertAction * action) {
                                                           [YMTBigClassSDKManager shareManager].switchEnv = YMTRoomEnvironment_Sit01;
                                                         }];
    UIAlertAction* sitTwoAction = [UIAlertAction actionWithTitle:@"SIT02" style:UIAlertActionStyleDefault
                                                         handler:^(UIAlertAction * action) {
                                                           [YMTBigClassSDKManager shareManager].switchEnv = YMTRoomEnvironment_Sit02;
                                                         }];
    UIAlertAction* sitThreeAction = [UIAlertAction actionWithTitle:@"SIT03" style:UIAlertActionStyleDefault
                                                         handler:^(UIAlertAction * action) {
                                                           [YMTBigClassSDKManager shareManager].switchEnv = YMTRoomEnvironment_Sit03;
                                                         }];
    UIAlertAction* sitFourAction = [UIAlertAction actionWithTitle:@"SIT04" style:UIAlertActionStyleDefault
                                                         handler:^(UIAlertAction * action) {
                                                           [YMTBigClassSDKManager shareManager].switchEnv = YMTRoomEnvironment_Sit04;
                                                         }];
    UIAlertAction* releaseAction = [UIAlertAction actionWithTitle:@"RELEASE" style:UIAlertActionStyleDefault
                                                         handler:^(UIAlertAction * action) {
                                                           [YMTBigClassSDKManager shareManager].switchEnv = YMTRoomEnvironment_Release;
                                                         }];
    [alert addAction:sitOneAction];
    [alert addAction:sitTwoAction];
    [alert addAction:sitThreeAction];
    [alert addAction:sitFourAction];
    [alert addAction:releaseAction];

    if (IS_IPAD) {
        alert.popoverPresentationController.sourceView = self.view;

        alert.popoverPresentationController.sourceRect = CGRectMake(SCREEN_WIDTH*0.75,SCREEN_HEIGHT*0.2,1.0,1.0);

    }

    [self presentViewController:alert animated:YES completion:nil];


}

- (IBAction)loginAction:(id)sender {
    [QMUITips showLoading:@"登陆中。。。" inView:self.view];

    co_launch(^{
        id response = await([self login]);
        [QMUITips hideAllTips];
        
        if (response) {
            [QMUITips showSucceed:@"登陆成功"];
            [[NSUserDefaults standardUserDefaults] setObject:self.accountTextField.text forKey:@"account"];
            [[NSUserDefaults standardUserDefaults] setObject:self.pswTestField.text forKey:@"psw"];
            [[NSUserDefaults standardUserDefaults] setObject:response[@"token"] forKey:@"token"];
            UIStoryboard *sb = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
            
            UIViewController *vc = [sb instantiateViewControllerWithIdentifier:@"YMTEntryRoomViewController"];
            [self showViewController:vc sender:nil];
            
        }else {
            [QMUITips showError:@"网络错误"];
        }
    });

}

static int envClickNum = 0;
    
- (IBAction)envChangeAction:(id)sender {
    if (envClickNum > 5) {
        
        envClickNum = 0;
    }
}
    
#pragma mark - Private Method

#pragma mark bindRAC

- (void)bindRAC {
    RAC(self, accountTextField.text) = [self.accountTextField.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return [value substringToIndex:value.length < 12 ? value.length : 11];
    }];
    
    RACSignal <NSNumber *> * accountEnable = [self.accountTextField.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return @(value.length == 11);
    }];
    
    RACSignal <NSNumber *> * pswEnable = [self.pswTestField.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return @(value.length >= 6);
    }];
    
    RAC(self,loginButton.enabled) = [RACSignal combineLatest:@[ pswEnable, accountEnable ] reduce:^(NSNumber *enable1, NSNumber *enable2) {
        return @(enable1.boolValue && enable2.boolValue);
    }];
}

#pragma mark login

- (COPromise *)login {
    
    return [COPromise promise:^(COPromiseFulfill  _Nonnull fullfill, COPromiseReject  _Nonnull reject) {
        
        NSDictionary *dic = @{@"mobileNo": self.accountTextField.text, @"password": [self md5StringFromData:[self.pswTestField.text dataUsingEncoding:NSUTF8StringEncoding]]/*, @"sysInfo": @"IOS", @"umengAppKey": @"5b29f1aff43e482cc400001e", @"appSource": @"YIMI", @"apiVersion":@"2.4", @"type": @"STU",@"isForce":@"1",@"from":@"1",@"deviceInfo":@"iOS12.3.1:iPad5,1:iPad mini 4 (A1538)",@"appVersion":@"4.8.1121",@"timestamp":[self getTimeStemp]*/};
        
        [[YMTHTTPSessionManager shareManager] fetch:@"user_login" method:@"" parameters:dic progress:nil result:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject, NSError * _Nonnull error) {
            if (responseObject) {
                fullfill(responseObject);
            }else {
                reject(error);
            }
        }];
    }];
}

#pragma mark 参数加密

//获取格式化时间
- (NSString *)getTimeStemp {
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];//创建一个日期格式化器
    [dateFormatter setDateFormat:@"yyyyMMddHHmmss"];//指定转date得日期格式化形HH必须大写不然会出现2017062608:12:32这情况
    NSString *strDate = [dateFormatter stringFromDate:date];
    return strDate;
}

- (NSString *)getSignWithDic:(NSDictionary *)dic {
    NSArray *arrKeys = [dic allKeys];
    arrKeys = [arrKeys sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        return [obj1 compare:obj2];
    }];
    
    //    NSLog(@"%@",arrKeys);
    NSString *str = @"";
    for (int i = 0; i < [arrKeys count]; i++) {
        NSString *key = [NSString stringWithFormat:@"%@",[arrKeys objectAtIndex:i]];
        NSString *value = [NSString stringWithFormat:@"%@",[dic objectForKey:key]];
        //        value = [NSString urlEncodedString:value];
        if (str.length > 0) {
            str = [str stringByAppendingFormat:@"&%@=%@", key, value];
        }else {
            str = [str stringByAppendingFormat:@"%@=%@", key, value];
        }
    }
    
    //NSLog(@"str:%@\nmd5:%@",str,[str md5Encrypt]);
    return [self md5EncryptFromStr:str];
}

/** 大写MD5*/
- (NSString *)md5EncryptFromStr:(NSString *)str {
    
    const char *cStr = [str UTF8String];
    unsigned char result[16];
    CC_MD5( cStr, (CC_LONG)strlen(cStr), result );
    return [NSString stringWithFormat:@"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}

- (NSString *)md5StringFromData:(NSData *)data {
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(data.bytes, (CC_LONG)data.length, result);
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}
#pragma mark 手机号

//判断是否为正确的手机号码
- (BOOL)checkIsPhoneNumber:(NSString *)number {
    NSString *phoneRegex = @"^(1[3-9])\\d{9}$";
    NSPredicate *phoneTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",phoneRegex];
    return [phoneTest evaluateWithObject:number];
}

@end
