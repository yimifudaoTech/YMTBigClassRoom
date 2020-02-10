//
//  YMTAnswerConfig.h
//  Pods
//
//  Created by mystarains on 2019/9/12.
//

#ifndef YMTAnswerConfig_h
#define YMTAnswerConfig_h

typedef NS_ENUM(NSUInteger, YMAnswerType) {
    YMAnswerTypeTimeOut = 0,
    YMAnswerTypeCancle = 1,
    YMAnswerTypeForceStop = 2,
    YMAnswerTypeCommit = 3
};

typedef void(^YMTAnswerResult)(NSString * _Nullable itemId,NSString * _Nullable itemAnswer, YMAnswerType type, NSString * _Nullable stuAnswer, NSInteger answerTime);

typedef void(^YMTStopAnswerResult)(NSString * _Nullable itemAnswer, NSString * _Nullable stuAnswer, NSInteger answerTime);


#endif /* YMTAnswerConfig_h */
