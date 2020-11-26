//
//  BaseButton.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/26.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ButtonStyle) {
    ButtonStyleFilled,
    ButtonStyleBorder,
    ButtonStyleDash,
};

NS_ASSUME_NONNULL_BEGIN

@interface BaseButton : UIButton
@property (nonatomic, strong, readonly) CALayer* layerBackground;
@property (nonatomic, assign) ButtonStyle buttonStyle;
@property (nonatomic, strong) UIColor* normalColor;
@property (nonatomic, strong) UIColor* disableColor;
@end

NS_ASSUME_NONNULL_END
