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
    
    dome.setRadius(9000);
}

void globe::update() {
    
}

void globe::draw() {

    ofPushMatrix();
    
    ofRotateX(180);
    // enable solid surface and backface culling in Open GL
    glEnable(GL_CULL_FACE); // Cull back facing polygons
    glCullFace(GL_FRONT);
    
    if (renderTexture) {
        ofSetColor(255);
        textureImage.getTextureReference().bind();
        sphere.draw();
        textureImage.unbind();
    } else {
        ofSetColor(0, 150, 255, 150);
        sphere.draw();
    }
    
    
    //ofSetColor(150, 255, 100);
    //sphere.drawNormals(5);
    //sphere.drawAxes(150);
    
    ofSetLineWidth(0.5);
    ofSetColor(0, 50, 75, 50);
    sphere.drawWireframe();
    
    glCullFace(GL_BACK);
    ofSetColor(255);
    domeTexture.getTextureReference().bind();
    dome.draw();
    domeTexture.unbind();
    
    ofPopMatrix();
}

void globe::setTexture(string path) {
    textureImage.loadImage(path);
    textureImage.mirror(false, true); // vertical, horizontal
}

void globe::setDomeTexture(string path) {
    domeTexture.loadImage(path);
}

void globe::setTextureRendering(bool render) {
    renderTexture = render;
}