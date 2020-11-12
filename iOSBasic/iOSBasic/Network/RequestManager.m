//
//  RequestManager.m
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#import "RequestManager.h"
#import "AFHTTPSessionManager.h"

@interface RequestManager()

@property (nonatomic, copy) NSString                * domainString;
@property (nonatomic, strong) AFHTTPSessionManager  * manager;

@end

@implementation RequestManager
SYNTHESIZE_ARC_SINGLETON_FOR_CLASS(RequestManager)

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.manager = [AFHTTPSessionManager manager];
        self.manager.requestSerializer = [AFJSONRequestSerializer serializer];
        self.manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    }
    return self;
}

#pragma mark - Public
// 配置请求域名 （只需要配置一次）
- (void)configEviroment:(Environment)envType {
    if ([self.delegate respondsToSelector:@selector(getDomainByEnv:)]) {
        self.domainString = [self.delegate getDomainByEnv:envType];
    }
}

/**
 网络请求
 
 @param URLString 请求连接
 @param parameters 参数
 @param progress 进度
 @param success 成功回调
 @param failure 失败回调
 */
- (void)ManagePOST:(NSString *_Nullable)method
        parameters:(nullable id)parameters
           headers:(NSDictionary *)headers
          progress:(nullable void (^)(NSProgress * _Nullable uploadProgress))progress
           success:(nullable void (^)(NSURLSessionDataTask * _Nullable task, id _Nullable responseObject))success
           failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))failure{
    NSLog(@"requestHeaders===%@", headers);
    NSString *url = [NSString stringWithFormat:@"%@%@", self.domainString?self.domainString:@"", method];
    [self.manager POST:url
            parameters:parameters
               headers:headers
              progress:progress
               success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:responseObject options:NSJSONReadingMutableContainers error:nil];
        NSLog(@"接口打印 ：\nurl---- %@\nrequest：【%@】\nResult --- %@ ", url, parameters,dic);
        if (success) {
            dispatch_async(dispatch_get_main_queue(), ^{
                success(task, responseObject);
            });
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        signal(SIGPIPE, SIG_IGN);
        NSLog(@"****【POST】【url = %@】\nrequest：【%@】\nerror：【%@】****",url,parameters,error.description);
        if (failure) {
            dispatch_async(dispatch_get_main_queue(), ^{
                failure(task, error);
            });
        }
    }];
}

@end
