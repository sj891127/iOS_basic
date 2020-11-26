//
//  BaseButton.m
//  iOSBasic
//
//  Created by shenjie on 2020/11/26.
//

#import "BaseButton.h"
#import <QuartzCore/QuartzCore.h>

@implementation BaseButton

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.layer.masksToBounds = YES;
        self.layer.cornerRadius = 2.0f;
        self.enabled = YES;
        self.disableColor = [UIColor grayColor];
    }
    return self;
}

- (void) setButtonStyle:(ButtonStyle)buttonStyle {
    _buttonStyle = buttonStyle;
    switch (_buttonStyle) {
            case ButtonStyleFilled:
            self.backgroundColor = self.normalColor;
            [self setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
            self.layer.borderColor = [UIColor clearColor].CGColor;
            self.layer.borderWidth = 0.0f;
            break;
            case ButtonStyleBorder:
            self.backgroundColor = [UIColor colorWithWhite:1.0f alpha:0.2f];
            self.layer.borderColor = self.normalColor.CGColor;
            self.layer.borderWidth = 0.5f;
            self.layer.cornerRadius = 2.0f;
            self.layer.masksToBounds = YES;
            break;
        default:
            break;
    }
}


- (void)setEnabled:(BOOL)enabled {
    [super setEnabled:enabled];
    if (enabled) {
        self.buttonStyle = _buttonStyle;
        [self setBackgroundColor:self.normalColor];
    } else {
        if (self.buttonStyle == ButtonStyleFilled) {
            [self setBackgroundColor:self.disableColor];
        } else {
            [self setBackgroundColor:[UIColor clearColor]];
        }
    }
}

@end
