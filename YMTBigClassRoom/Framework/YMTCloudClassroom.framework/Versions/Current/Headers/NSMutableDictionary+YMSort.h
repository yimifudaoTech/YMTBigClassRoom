//
//  NSMutableDictionary+YMSort.h
//  YMTCloudClassroom
//
//  Created by yimi on 2019/12/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableDictionary (YMSort)

@property (nonatomic, strong) NSMutableArray *sortedKeyArray;

- (void)YMSort_setObject:(id)anObject forKey:(id<NSCopying>)aKey;

- (void)YMSort_removeObjectForKey:(id)aKey;

- (void)YMSort_removeAllObjects;

- (void)YMSort_bringObjectToFront:(id)aKey;

- (void)YMSort_enumerateKeysAndObjectsUsingBlock:(void (NS_NOESCAPE ^)(id key, id obj, BOOL *stop))block;

- (NSMutableArray *)YMSort_getAllValue;

@end

NS_ASSUME_NONNULL_END
