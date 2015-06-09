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
    renderTexture = true;
    
    //sphere.enableNormals();
    sphere.enableTextures();
}

void globe::update() {
    
}

void globe::draw() {
    
    
    ofPushMatrix();
    
    ofSetColor(255);
    
    if (renderTexture) {
	    textureImage.getTextureReference().bind();
    }
    
    ofRotateX(180);
    
    // enable solid surface and backface culling in Open GL
    glEnable(GL_CULL_FACE); // Cull back facing polygons
    glCullFace(GL_FRONT);
    
    sphere.draw();
    
    if (renderTexture) {
	    textureImage.unbind();
    }
    
    
    ofSetColor(150, 255, 100);
    //sphere.drawNormals(5);
    sphere.drawAxes(150);
    
    ofSetLineWidth(0.5);
    ofSetColor(0, 50, 75, 50);
    sphere.drawWireframe();

    
    ofPopMatrix();
    
}

void globe::setTexture(string path) {
    textureImage.loadImage(path);
    textureImage.mirror(false, true); // vertical, horizontal
}

void globe::setTextureRendering(bool render) {
    renderTexture = render;
}