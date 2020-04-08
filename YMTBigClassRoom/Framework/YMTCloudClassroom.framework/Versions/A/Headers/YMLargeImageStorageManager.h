//
//  YMLargeImageStorageManager.h
//  YMTCloudClassroom
//
//  Created by juwanli on 2020/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YMLargeImageStorageManager : NSObject

/**
 缓存中是否存在key
 @param key 字符串描述，如果为nil，返回NO
 @return 是否包含在缓存中
 */
- (BOOL)containsObjectForKey:(NSString *)key;

/**
缓存中是否存在key
@param key 字符串描述，如果为nil，返回NO
@param block 回调 返回结果
*/
- (void)containsObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, BOOL contains))block;
/**
 获取缓存的对象
 @param key 字符串描述，如果为nil，返回nil'
 @return 返回key关联的value
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

- (void)objectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, id<NSCoding> object))block;
/**
 设置value到缓存中
 @param object  缓存的可以对应的value
 @param key 缓存的key
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

/**
 删除缓存
 @param key 缓存bvalue对应的key
 */
- (void)removeObjectForKey:(NSString *)key;
/**
 删除所有的缓存内容
 */
- (void)removeAllObjects;

@end

NS_ASSUME_NONNULL_END
