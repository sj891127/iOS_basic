//
//  TabViewControllerProtocol.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/4.
//

#ifndef TabViewControllerProtocol_h
#define TabViewControllerProtocol_h

@protocol TabViewControllerProtocol <NSObject>
@required
- (NSString *)tabTitle;
- (UIImage *)tabImage;
- (UIImage *)tabSelectedImage;
@optional
- (NSString *)tabBadge;
- (UIColor *)tabBadgeColor;
@end

#endif /* TabViewControllerProtocol_h */
