//
//  YMCallTraceCore.h
//  YMBaseLib
//
//  Created by yimi on 2020/3/23.
//

#ifndef YMCallTraceCore_h
#define YMCallTraceCore_h

#include <stdio.h>
#include <objc/objc.h>

typedef struct {
    __unsafe_unretained Class cls;
    SEL sel;
    uint64_t time; // us (1/1000 ms)
    int depth;
} ymCallRecord;

extern void ymCallTraceStart();
extern void ymCallTraceStop();

extern void ymCallConfigMinTime(uint64_t us); //default 1000
extern void ymCallConfigMaxDepth(int depth);  //default 3

extern ymCallRecord *ymGetCallRecords(int *num);
extern void ymClearCallRecords();



#endif /* YMCallTraceCore_h */
