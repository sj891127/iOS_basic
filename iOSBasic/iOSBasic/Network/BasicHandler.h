//
//  BasicHandler.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#import <Foundation/Foundation.h>
#import <iOSBasic/RequestManager.h>
#import <iOSBasic/BusinessConstants.h>
NS_ASSUME_NONNULL_BEGIN

#define AuthFailCode    1002

@interface BasicHandler : NSObject
SYNTHESIZE_ARC_SINGLETON_FOR_CLASS_HEADER(BasicHandler)
@property (nonatomic, weak) id<BusinessHelper> _Nullable delegate;
- (void)sendRequest:(NSString * _Nonnull)method
           postBody:(NSDictionary * _Nullable)postBody
    responseDataCls:(Class _Nullable)responseDataCls
         completion:(RequestCompletion _Nullable)completion;
@end

NS_ASSUME_NONNULL_END
