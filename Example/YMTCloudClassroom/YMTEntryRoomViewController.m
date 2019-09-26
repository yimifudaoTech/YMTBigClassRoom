//
//  YMTClassRoomDemoViewController.m
//  student
//
//  Created by SendomZhang on 19/7/2019.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import "YMTEntryRoomViewController.h"

#import "SDSCMineCatalogGOModel.h"
//#import "YMTRoomManagerViewController.h"

//#import "NSObject+YYModel.h"
#import <QMUIKit/QMUIKit.h>


@interface YMTEntryRoomViewController ()

@property (weak, nonatomic) IBOutlet QMUITextField *numTextField;

@end

@implementation YMTEntryRoomViewController

#pragma mark - Life Cycyle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"demo";
    
    self.numTextField.layer.cornerRadius = 36.0f;
    
    self.numTextField.textInsets = UIEdgeInsetsMake(0, 34, 0, 0);
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

- (IBAction)whiteBoardAction:(id)sender {
    [self modifyModelWithComplete:^(SDSCMineGoAgoraRoomModel *model) {
        //        [QMUITips hideAllTips];
        if (!model) {
            return;
        }
//        YMTRoomManagerViewController *vc = [[YMTRoomManagerViewController alloc] init];
//        [vc enableVideo:NO];
//        [vc enableVideo:NO];
//        vc.roomModel = model;
//        [vc openRoom];
    }];

}

- (IBAction)entryAction:(id)sender {
    if (!self.numTextField.text.length) {
//        [QMUITips showInfo:@"房间号为空" inView:self.view hideAfterDelay:1.0];
        return;
    }
//    [QMUITips showLoadingInView:self.view];
    [self modifyModelWithComplete:^(SDSCMineGoAgoraRoomModel *model) {
//        [QMUITips hideAllTips];
        if (!model) {
            return;
        }
//        YMTRoomManagerViewController *vc = [[YMTRoomManagerViewController alloc] init];
//        vc.roomModel = model;
//        [vc openRoom];
    }];
}

#pragma mark - Private Method

- (void)modifyModelWithComplete:(void(^)(SDSCMineGoAgoraRoomModel *model))handle {
    dispatch_group_t group = dispatch_group_create();
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    NSString *classID = self.numTextField.text ?: @"";
    
    __block SDSCMineGoAgoraRoomModel *classModel;
    __block NSArray<NSString *> *IPLists;
    __block SCAgoraDomainModel *domainModel;
    __block NSString *serverIPString;
    
    dispatch_group_enter(group);
    dispatch_group_async(group, queue, ^{
        [self fetchIPLists:^(NSArray<NSString *> *ips, NSString *IPString) {
            IPLists = ips;
            serverIPString = IPString;
            dispatch_group_leave(group);
        }];
    });
    
    dispatch_group_enter(group);
    dispatch_group_async(group, queue, ^{
        [self fetchClassInfo:classID handle:^(SDSCMineGoAgoraRoomModel *object) {
            classModel = object;
            dispatch_group_leave(group);
        }];
    });
    
    dispatch_group_enter(group);
    dispatch_group_async(group, queue, ^{
        [self fetchPort:^(SCAgoraDomainModel *object) {
            domainModel = object;
            dispatch_group_leave(group);
        }];
    });
    
    dispatch_group_notify(group, queue, ^{
        
        classModel.dnsIPList = [NSMutableArray arrayWithArray:IPLists];
        [classModel.dnsIPList insertObject:serverIPString atIndex:0];
        classModel.domain = domainModel;
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            if (handle) {
                handle(classModel);
            }
        });
    });
}

#pragma mark fetch data
- (void)fetchIPLists:(void(^)(NSArray <NSString *> *ips, NSString *serverIPString))callback {
    //获取ip列表
//    NSDictionary *param = @{};
//    [SDHttp GETUrl:Url_SmallClassAgoraIpList_SD parma:param HeaderParma:[SDHttp dicWithSignWithSmallClassDic:param] response:^(id response, int code) {
//        if (code == 1 && response[@"data"]!=nil ) {
//            NSArray <NSString *> *ips = [(NSString *)response[@"data"][@"serverIp"] componentsSeparatedByString:@","];
//            callback(ips, (NSString *)response[@"data"][@"serverIp"]);
//            }else {
//                [NetWorkMessage returnFailed:response[@"message"]];
//                callback(nil,nil);
//            }
//        } failed:^(id response) {
//            callback(nil,nil);
//        } hudInview:nil];
};

- (void)fetchPort:(void(^)(SCAgoraDomainModel *object))callback {
    //获取端口号
//    NSDictionary *param = @{};
//    [SDHttp GETUrl:Url_SmallClassAgoraDomain_SD parma:param HeaderParma:[SDHttp dicWithSignWithSmallClassDic:param] response:^(id response, int code) {
//            if (response[@"data"]) {
//                SCAgoraDomainModel *model = [SCAgoraDomainModel yy_modelWithDictionary:response[@"data"]];
//                callback(model);
//            }else {
//                callback(nil);
//            }
//        } failed:^(id response) {
//            callback(nil);
//        } hudInview:nil];
};

- (void)fetchClassInfo:(NSString *)classID handle:(void(^)(SDSCMineGoAgoraRoomModel *object))callback {
//        NSMutableDictionary *param = [NSMutableDictionary dictionary];
//        param[@"executionPlanId"] = classID;
//        [SDHttp GETUrl:Url_SmallClassEnterRoom_SD parma:param  HeaderParma:[SDHttp dicWithSignWithSmallClassDic:param] response:^(id response, int code) {
//            if (code == 1 && response[@"data"]!= [NSNull null] && response[@"data"][@"liveRoomDto"]!= [NSNull null] && response[@"data"][@"platform"]!= [NSNull null]) {
//                NSNumber *platform = response[@"data"][@"platform"];
//                id value = response[@"data"][@"liveRoomDto1"];
//                if (!value) {
//                    value = response[@"data"][@"liveRoomDto"];
//                }
//                SDSCMineGoAgoraRoomModel *model = [SDSCMineGoAgoraRoomModel mj_objectWithKeyValues:value];
//                callback(model);
//            }else {
//                callback(nil);
//            }
//        } failed:^(id response) {
//            callback(nil);
//        } hudInview:self.view];
}

- (void)openhistory {
//        [CXUMstatistics countEvent:@"tea_kb_7"];
//        [self requestSmallClassVideoList:@{@"executionPlanId":@""} callback:^(NSNumber * platform) {
////            if (platform.integerValue == 1) {// 拓客云教室
////                [weakself jumpTkeduWithDetail:detail handleStatus:handleStatus];
////            } else {// 自研教室
//                [weakself pushClass:[SDSmallClassRecordsListVC class] parma:@{@"lessionid":[detail executionPlanId],VCTitleKey:[NSString stringWithFormat:@"%@",[detail title]]} callBack:nil];
////            }
//        }];
}

@end
