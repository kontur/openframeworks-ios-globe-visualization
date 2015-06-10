//
//  overlay.h
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 09/06/15.
//
//

#ifndef __GlobeVisualization__overlay__
#define __GlobeVisualization__overlay__

#include <stdio.h>
#import <UIKit/UIKit.h>

@interface overlayController : UIViewController

@property(retain, nonatomic) IBOutlet UISlider *numberSlider;
@property(retain, nonatomic) IBOutlet UISwitch *textureSwitch;

@end
#endif /* defined(__GlobeVisualization__overlay__) */
