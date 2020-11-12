//
//  RequestManager.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#import <Foundation/Foundation.h>
#import "NetworkConstants.h"
#import "SingletonSynthesizer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RequestManager : NSObject
@property (nonatomic, weak) id<NetworkHelper> _Nullable delegate;


SYNTHESIZE_ARC_SINGLETON_FOR_CLASS_HEADER(RequestManager)

/// 配置请求域名 （只需要配置一次）
- (void)configEviroment:(Environment)envType;


/**
 网络请求
 
 @param method 请求连接
 @param parameters 参数
 @param headers  请求头
 @param progress 进度
 @param success 成功回调
 @param failure 失败回调
 */
- (void)ManagePOST:(NSString *_Nullable)method
        parameters:(nullable id)parameters
           headers:(nullable NSDictionary *)headers
          progress:(nullable void (^)(NSProgress * _Nullable uploadProgress))progress
           success:(nullable void (^)(NSURLSessionDataTask * _Nullable task, id _Nullable responseObject))success
           failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))failure;
@end

NS_ASSUME_NONNULL_END
