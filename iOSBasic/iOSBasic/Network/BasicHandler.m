//
//  BasicHandler.m
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#import "BasicHandler.h"
#import <YYKit/YYKit.h>
#import "ResponseModel.h"

@implementation BasicHandler
SYNTHESIZE_ARC_SINGLETON_FOR_CLASS(BasicHandler)
#pragma mark - Public
- (void)sendRequest:(NSString * _Nonnull)method
           postBody:(NSDictionary * _Nullable)postBody
    responseDataCls:(Class _Nullable)responseDataCls
         completion:(RequestCompletion _Nullable)completion {
    NSDictionary *headers = nil;
    if ([self.delegate respondsToSelector:@selector(getHeadersByInfo:)]) {
        headers = [self.delegate getHeadersByInfo:method];
    }
    [[RequestManager sharedInstance] ManagePOST:method
                                       parameters:postBody
                                          headers:headers
                                         progress:nil
                                          success:^(NSURLSessionDataTask * _Nullable task, id  _Nullable responseObject) {
        ResponseModel *baseModel = [ResponseModel modelWithJSON:responseObject];
        if(baseModel.code == 200) {
            id dataModel = baseModel.data;
            if (responseDataCls!=NULL) {
                dataModel = [responseDataCls modelWithJSON:baseModel.data];
            }
            if (completion) {
                completion(dataModel?:baseModel.data, nil, baseModel.code);
            }
        }else {
            if(completion) {
                completion(nil, baseModel.message?:NetErrorMessage, baseModel.code);
            }
            if (baseModel.code == AuthFailCode) {
                [[NSNotificationCenter defaultCenter] postNotificationName:Notification_AuthFail object:nil];
            }
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error) {
        if (completion) {
            completion(nil, NetErrorMessage, error.code);
        }
    }];
}
@end
