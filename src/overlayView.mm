//
//  overlayView.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 09/06/15.
//
//

#include "overlayView.h"
#include "ofApp.h"

/**
 * This view is only used to override the pointInside to allow clicking
 * through the view to the below OF open GL layer
 */
@implementation overlayView

/**
 * pointInside check override passing touch events in the middle through
 */
-(BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event {
    return (point.y > 50 && point.y < 900) ? NO : YES;
}
@end