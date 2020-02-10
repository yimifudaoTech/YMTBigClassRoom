//
//  YMLiveModule.h
//  teacher
//
//  Created by mystarains on 2019/8/6.
//  Copyright © 2019 YiMi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YMLiveModuleProtocol.h"

@interface YMLiveModule : NSObject<YMLiveModuleProtocol>

@property (nonatomic,weak) id<YMLiveModuleDataSource> dataSource;
@property (nonatomic,weak) id<YMLiveModuleDelegate> delegate;

@end

