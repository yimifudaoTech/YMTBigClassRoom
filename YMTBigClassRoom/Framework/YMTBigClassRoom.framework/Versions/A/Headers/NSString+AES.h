//
//  NSString+AES.h
//  AES
//
//  Created by mac on 19/9/16.
//  Copyright © 2019年 Bear. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (AES)

/**< 加密方法 */
- (NSString*)aci_encryptWithAES;

/**< 解密方法 */
- (NSString*)aci_decryptWithAES;

@end
