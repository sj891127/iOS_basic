//
//  ResponseModel.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ResponseModel : NSObject
@property (nonatomic, assign) NSInteger      code;
@property (nonatomic,   copy) NSString     * message;
@property (nonatomic,   copy) NSDictionary * data;
@end

NS_ASSUME_NONNULL_END
