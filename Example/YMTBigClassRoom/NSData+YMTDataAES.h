//
//  NSData+YMTDataAES.h
//  YMTBigClassRoom_Example
//
//  Created by SendomZhang on 12/9/2019.
//  Copyright © 2019 zhangqian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (YMTDataAES)

- (NSData *)AES256EncryptWithKey:(NSString *)key;
    
    
@end

NS_ASSUME_NONNULL_END
