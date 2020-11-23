//
//  CommonConstants.h
//  iOS_basic
//
//  Created by shenjie on 2020/11/2.
//

#ifndef CommonConstants_h
#define CommonConstants_h

#pragma mark - Common
#define AppBundleIdentifier     [[NSBundle mainBundle] bundleIdentifier]
#define AppBundleVersion        [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define iOSVersion              [[[UIDevice currentDevice] systemVersion] floatValue]
#define AppDocumentDirectory    [NSString stringWithFormat:@"%@/Documents",NSHomeDirectory()]
#define AppCacheDirectory       [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
#define AppLibraryDirectory     [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject]
#define AppStorageDirectory     [NSSearchPathForDirectoriesInDomains(NSApplicationSupportDirectory, NSUserDomainMask, YES) lastObject]

#endif /* CommonConstants_h */
