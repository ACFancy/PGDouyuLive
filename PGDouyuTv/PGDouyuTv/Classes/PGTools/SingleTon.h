//
//  SingleTon.h
//  PGDouyuTv
//
//  Created by 恭喜发财 on 16/9/13.
//  Copyright © 2016年 PGWizard. All rights reserved.
//

#ifndef SingleTon_h
#define SingleTon_h

#if __OBJC__

#define SingleTonInterface(prefix, name) +(instancetype)share##name;

#if __has_feature(objc_arc) //(ARC 单例)

#define SingleTonImplement(prefix, name) static prefix##name *_instance = nil;\
+ (instancetype)share##name {\
 _instance = [[self alloc] init];\
 return _instance;\
}\
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone {\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
if(_instance == nil) {\
_instance = [super allocWithZone:zone];\
}\
});\
return _instance;\
}\
\
- (instancetype)copyWithZone:(NSZone *)zone {\
return _instance;\
}\
\
- (instancetype)mutableCopyWithZone:(NSZone *)zone {\
    return _instance;\
}

#else //(非ARC 单例)

#define SingleTonImplement(prefix, name) static prefix##name *_instance = nil;\
+ (instancetype)share##name {\
_instance = [[self alloc] init];\
}\
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone {\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
    if(_instance == nil) {\
        _instance = [super allocWithZone:zone];\
    }\
});\
return _instance;\
}\
\
- (instancetype)copyWithZone:(NSZone *)zone {\
    return _instance;\
}\
\
- (instancetype)mutableCopyWithZone:(NSZone *)zone {\
    return _instance;\
}\
\
- (oneway void)release {\
}\
\
- (instancetype)retain {\
    return  _instance;\
}\
\
- (NSUInteger)retainCount {\
    return NSUIntegerMax;\
}

#endif
#endif


#endif /* SingleTon_h */
