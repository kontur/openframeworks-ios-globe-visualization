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
    
    ofSetColor(255);
    
    sphere.enableNormals();
    sphere.enableTextures();
    
    ofTexture tex = textureImage.getTextureReference();
    
    //tex.bind();
    sphere.mapTexCoordsFromTexture(tex);
    //tex.draw(0, 0);
    tex.bind();
    
    ofRotateX(180);
    
    sphere.draw();
    textureImage.unbind();
    
    
    ofSetColor(150, 255, 100);
    sphere.drawNormals(5);
    sphere.drawAxes(150);
    
    ofSetColor(0, 50, 75);
    sphere.drawWireframe();

    
    ofPopMatrix();
    
}

void globe::setTexture(string path) {
    textureImage.loadImage(path);
    textureImage.mirror(false, true); // vertical, horizontal
}