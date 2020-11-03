//
//  SingletonSynthesizer.h
//  iOS_basic
//
//  Created by shenjie on 2020/11/2.
//

#ifndef SYNTHESIZE_ARC_SINGLETON_FOR_CLASS

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#define SYNTHESIZE_ARC_SINGLETON_FOR_CLASS_HEADER(SINGLETONCLASSNAME)    \
+ (instancetype)sharedInstance;


#define SYNTHESIZE_ARC_SINGLETON_FOR_CLASS(SINGLETONCLASSNAME)    \
\
static volatile id sharedInstance##SINGLETONCLASSNAME = nil;    \
\
+ (void)initialize \
{ \
    if ([self isSubclassOfClass:[SINGLETONCLASSNAME class]]) \
    { \
        static dispatch_once_t once##SINGLETONCLASSNAME;\
        dispatch_once(&once##SINGLETONCLASSNAME, ^{\
            sharedInstance##SINGLETONCLASSNAME = [[self alloc] init];\
        });\
    } \
} \
\
+ (instancetype)sharedInstance    \
{    \
return sharedInstance##SINGLETONCLASSNAME; \
}    \

#endif
