//
//  NetworkConstants.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#ifndef NetworkConstants_h
#define NetworkConstants_h

#pragma mark - Env
typedef NS_ENUM(NSInteger,Environment) {
    EnvironmentDev,     // 开发
    EnvironmentPre,     // 预发
    EnvironmentOnline   // 正式
};

@protocol NetworkHelper <NSObject>
@required
- (NSString * _Nonnull)getDomainByEnv:(Environment)env;
@end

#pragma mark - Block
typedef void(^RequestCompletion) (id _Nullable responseObject, NSString * _Nullable errorMeaasge,NSInteger code);

#endif /* NetworkConstants_h */
