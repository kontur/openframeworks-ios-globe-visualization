//
//  overlayView.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 09/06/15.
//
//

#include "overlayView.h"

@interface PassthroughView : UIView
@end

@implementation PassthroughView
-(BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event {
    for (UIView *view in self.subviews) {
        if (!view.hidden && view.alpha > 0 && view.userInteractionEnabled && [view pointInside:[self convertPoint:point toView:view] withEvent:event])
            return YES;
    }
    return NO;
}
@end