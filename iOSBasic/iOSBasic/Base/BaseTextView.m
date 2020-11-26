//
//  BaseTextView.m
//  iOSBasic
//
//  Created by shenjie on 2020/11/26.
//

#import "BaseTextView.h"

@implementation BaseTextView

- (id)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
        
    }
    return self;
}

- (void)drawRect:(CGRect)rect{
    if ([_placeHolder length] > 0) {
        if (_uiPlaceHolder == nil ) {
            _uiPlaceHolder = [[UILabel alloc] initWithFrame:CGRectMake(8.0f, 8.0f, self.bounds.size.width - 16, 0.0f)];
            _uiPlaceHolder.numberOfLines = 0;
            [_uiPlaceHolder setFont:self.font];
            [_uiPlaceHolder setBackgroundColor:[UIColor clearColor]];
            _uiPlaceHolder.textColor = [UIColor lightGrayColor];
            _uiPlaceHolder.alpha = 0;
            [self addSubview:_uiPlaceHolder];
        }
        [_uiPlaceHolder setText:_placeHolder];
        [_uiPlaceHolder sizeToFit];
        [self sendSubviewToBack:_uiPlaceHolder];
    }
    if ([self.text length] == 0 && [_placeHolder length] > 0) {
        _uiPlaceHolder.alpha = 1.0f;
    }
    [super drawRect:rect];
}

- (void)setText:(NSString *)text {
    [super setText:text];
    [self textChanged];
}

- (void)textChanged {
    if ([_placeHolder length] == 0) {
        return;
    }
    [_uiPlaceHolder setAlpha:([self.text length] == 0)];
}

@end
