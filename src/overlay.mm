//
//  overlay.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 09/06/15.
//
//

#include "ofApp.h"
#include "overlay.h"
#include "ofxiPhoneExtras.h"

@implementation overlay

ofApp *myApp;

-(void)viewDidLoad {
    myApp = (ofApp*)ofGetAppPtr();
}

-(IBAction)radiusSliderHandler:(id)sender {
    UISlider *sliderObj = sender;
    //myApp->radius = [sliderObj value];
}

-(IBAction)fillSwitchHandler:(id)sender {
    UISwitch *switchObj = sender;
    //myApp->hasFill = [switchObj isOn];
}

@end