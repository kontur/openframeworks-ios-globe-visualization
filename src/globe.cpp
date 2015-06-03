//
//  globe.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#include "globe.h"

globe::globe() {
    sphere.setRadius(100);
}

void globe::update() {
    
}

void globe::draw() {
    
    ofPushMatrix();
    
    textureImage.getTextureReference().bind();
    
    ofColor(0, 255, 255);
    sphere.drawNormals(2);
    sphere.drawAxes(150);
    sphere.drawWireframe();
    
    
    
    ofRotateX(180);
    
    sphere.draw();
    
    textureImage.unbind();
    
    ofPopMatrix();
    
}

void globe::setTexture(string path) {
    textureImage.loadImage(path);
    textureImage.mirror(false, true); // vertical, horizontal
}