//
//  BaseTextView.h
//  iOSBasic
//
//  Created by shenjie on 2020/11/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BaseTextView : UITextView
@property (nonatomic, strong) UILabel *uiPlaceHolder;
@property (nonatomic, strong) NSString *placeHolder;
@end

NS_ASSUME_NONNULL_END
