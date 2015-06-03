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
    ofFill();
    ofDrawSphere(ofGetWidth() * .5, ofGetHeight()* .5, 0, 125);
    textureImage.unbind();
}

void globe::setTexture(string path) {
    textureImage.loadImage(path);
    

    //texture.loadData(textureImage.getPixels(), textureImage.getWidth(), textureImage.getHeight(), GL_RGB);
}