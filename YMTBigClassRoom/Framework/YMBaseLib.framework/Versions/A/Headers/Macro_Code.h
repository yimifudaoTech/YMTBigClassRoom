//
//  Macro_Code.h
//  YiMiApp
//
//  Created by xieyan on 16/3/14.
//  Copyright © 2016年 xieyan. All rights reserved.
//

#ifndef Macro_Code_h
#define Macro_Code_h
#define FalseReturn(_code_) if(_code_){}else{return;}
#define TrueReturn(_code_) if(_code_){return;}


#define INSTANCETYPE(_CLASS_,_INSTANCE_) _CLASS_* instance = (_CLASS_*)_INSTANCE_;
#define INSTANCETYPE_NAME(_CLASS_,_INSTANCE_,_NAME_) _CLASS_* _NAME_ = (_CLASS_*)_INSTANCE_;
#endif /* Macro_Code_h */
