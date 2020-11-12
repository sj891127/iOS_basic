//
//  UIConstants.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/4.
//

#ifndef UIConstants_h
#define UIConstants_h

#pragma mark - System
#define AppScreenFrame              ((CGRect){{0, 0}, [[UIScreen mainScreen] bounds].size})
#define SCREEN_WIDTH                ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT               ([UIScreen mainScreen].bounds.size.height)
#define AppScale                    ([UIScreen mainScreen].scale)

#define StatusBarHeight             [[UIApplication sharedApplication] statusBarFrame].size.height
#define IphoneX                     [[[UIApplication sharedApplication] delegate] window].safeAreaInsets.bottom
#define NavigationBarHeight         44.0f
#define TopBarHeight                (StatusBarHeight+NavigationBarHeight)

#define TabBarHeight                49.0f
#define HomeIndicatorHeight         34.0f
#define BottomBarHeight             (TabBarHeight+IphoneX)
#define IsPad ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
#define PercenX_scale(value) (value /((IsPad?768.0f:375.0f)/[UIScreen mainScreen].bounds.size.width))
#define PercenY_scale(value) (value /((IsPad?1024.0f:667.0f)/[UIScreen mainScreen].bounds.size.height))

#pragma mark - Size
#pragma mark __________Spacing__________
#define Spacing_Left_Normal       15.f
#define Spacing_Right_Normal      MKSpacing_Left_Normal

#define Spacing_Items_Normal      10.f
#define Spaceing_Lines_Normal     10.f

#pragma mark - Font
#pragma mark __________Usual__________
#define Font_Headline             [UIFont systemFontOfSize:22 weight:UIFontWeightSemibold]

#pragma mark - Color
#pragma mark __________Usual_________
#define Color_333                 UIColorFromHex(0xFF333333)

#pragma mark __________Transformer__________
#define RGBA(r,g,b,a)               [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGB(r,g,b)                  [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define UIColorFromHex(hexValue)    [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:((float)((hexValue & 0xFF000000) >> 24))/255.0]

#endif /* UIConstants_h */
