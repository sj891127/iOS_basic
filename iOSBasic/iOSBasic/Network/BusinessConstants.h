//
//  BusinessConstants.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/12.
//

#ifndef BusinessConstants_h
#define BusinessConstants_h

#define  NetErrorMessage @"请检查您的网络!"
#define  Notification_AuthFail      @"Notification_AuthFail"

@protocol BusinessHelper <NSObject>
@required
- (NSDictionary * _Nonnull)getHeadersByInfo:(NSString *_Nullable)info;
@end

#endif /* BusinessConstants_h */
