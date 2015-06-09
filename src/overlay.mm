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

-(IBAction)numberSliderHandler:(id)sender {
    UISlider *sliderObj = sender;
    //myApp->radius = [sliderObj value];
    ofLog() << [sliderObj value];
}

-(IBAction)textureSwitchHandler:(id)sender {
    UISwitch *switchObj = sender;
    ofLog() << [switchObj isOn];
    myApp->toggleTexture([switchObj isOn]);
}

-(IBAction)locationSearchHandler:(id)sender {
    UISearchBar *searchBarObj = sender;
    ofLog() << [searchBarObj text];
}

@end