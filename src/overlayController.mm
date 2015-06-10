//
//  overlay.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 09/06/15.
//
//

#include "ofApp.h"
#include "overlayController.h"
#include "ofxiPhoneExtras.h"

/**
 * UI layer using native UIKit components to interact with the OF open GL layer
 */
@implementation overlayController

ofApp *myApp;

-(void)viewDidLoad {
    // assign reference to the ofApp object to interact with it
    myApp = (ofApp*)ofGetAppPtr();
}

-(IBAction)numberSliderHandler:(id)sender {
    UISlider *sliderObj = sender;
    ofLog() << (int)[sliderObj value];
    myApp->setMaxConnections([sliderObj value]);
}

-(IBAction)textureSwitchHandler:(id)sender {
    UISwitch *switchObj = sender;
    ofLog() << [switchObj isOn];
    myApp->toggleTexture([switchObj isOn]);
}

@end