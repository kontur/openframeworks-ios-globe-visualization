//
//  globe.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#include "globe.h"

globe::globe() {
}

void globe::update() {
    
}

void globe::draw() {
    textureImage.bind();
    
    //ofSetSphereResolution(16);
    ofDrawSphere(0, 0, 0, 100);
    
    textureImage.unbind();
}

void globe::setTexture(string path) {
    textureImage.loadImage(path);
}