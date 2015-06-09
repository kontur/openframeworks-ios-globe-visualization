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

@interface overlay : UIViewController

@property(retain, nonatomic) IBOutlet UISlider *numberSlider;
@property(retain, nonatomic) IBOutlet UISwitch *textureSwitch;
@property(retain, nonatomic) IBOutlet UISearchBar *locationSearch;

@end
#endif /* defined(__GlobeVisualization__overlay__) */
