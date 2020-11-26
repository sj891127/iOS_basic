//
//  BaseTextField.m
//  iOSBasic
//
//  Created by shenjie on 2020/11/26.
//

#import "BaseTextField.h"

@implementation BaseTextField

- (id)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
        
    }
    return self;
}

//控制placeHolder的颜色、字体
- (void) drawPlaceholderInRect:(CGRect)rect{
    [_placeHolderColor setFill];
    NSMutableParagraphStyle *style = [[NSMutableParagraphStyle alloc] init];
    style.lineBreakMode = NSLineBreakByTruncatingTail;
    style.alignment = self.textAlignment;
    NSDictionary* attr = [NSDictionary dictionaryWithObjectsAndKeys:
                          style, NSParagraphStyleAttributeName,
                          self.font, NSFontAttributeName,
                          _placeHolderColor, NSForegroundColorAttributeName,
                          nil];
    CGRect bounds   = self.bounds;
    CGSize size     = [self.placeholder boundingRectWithSize:CGSizeMake(bounds.size.width, bounds.size.height)
                                                     options:NSStringDrawingUsesLineFragmentOrigin
                                                  attributes:attr
                                                     context:nil].size;
    if (self.textAlignment == NSTextAlignmentLeft ||
        self.textAlignment == NSTextAlignmentCenter) {
        rect.origin.x = 0.0f;
    } else if (self.textAlignment == NSTextAlignmentRight) {
        rect.origin.x = bounds.size.width - size.width;
    }
    rect.size.width = size.width;
    [[self placeholder] drawInRect:rect withAttributes:attr];
}

@end
