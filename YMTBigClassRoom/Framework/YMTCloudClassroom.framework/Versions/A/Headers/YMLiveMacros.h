//
//  YMLiveMacros.h
//  YiMiApp
//
//  Created by Caffrey on 2019/4/18.
//  Copyright © 2019 YiMi. All rights reserved.
//

#ifndef YMLiveMacros_h
#define YMLiveMacros_h

/** 弱引用 */
#define YMLive_WEAKSELF __weak typeof(self)weakSelf = self;
#define YMLive_STRONGSELF __strong typeof(weakSelf)self = weakSelf;

static NSString *const kYMLiveLogTAG = @"YMLive";

#endif /* YMLiveMacros_h */
