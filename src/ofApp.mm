#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    // various rendering intent settings
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    g.setTexture("earth2.bmp");
    
    m.setLatLng(ofVec2f(0, 0));
    m2.setLatLng(ofVec2f(60, 20));
    m3.setLatLng(ofVec2f(0, 20));
    m4.setLatLng(ofVec2f(30, 30));
    c.init(ofVec2f(60, 20), ofVec2f(0, 20));
    
    // start of with not rotation on the globe
    // note both the speed of rotation and the current rotation
    // are stored as a two direction vector
    rotation = ofVec2f(0);
    rotationSpeed = ofVec2f(0);
    rotationSpeedEasing = 0.9;
    
    // set initial zoom at 100%
    zoom = 1.0;
    newZoom = 1.0;
    zoomEasing = 0.75;
}

//--------------------------------------------------------------
void ofApp::update(){
    // calculate new rotation and zoom positions base on interaction

    // update the rotation by subtracting the current rotationSpeed
    // vector, then slowing ease the rotationSpeed down
    rotation = rotation - rotationSpeed;
    rotationSpeed *= 0.9;
    
    // update zoom in a gentle manner by easing it with a portion
    // of previous zoom state
    zoom = zoom * zoomEasing + (1 - newZoom * zoomEasing);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
    camera.begin();
    
    // setup the camera
    // zoom is the distance of camera to the world origin on z axis
    camera.setPosition(ofVec3f(0, 0, zoom * 100 + 300));
    camera.lookAt(ofVec3f(0, 0, 0));
    camera.setNearClip(0.0);
    camera.setFarClip(1000.0);
/*
    // setup lights
    spotlight.enable();
    spotlight.setPosition(-300, 300, -300);
    spotlight.setAmbientColor(ofFloatColor(100, 150, 255));
    spotlight.setDiffuseColor(ofFloatColor(255, 150, 100));
    spotlight.lookAt(ofVec3f(0, 0, 0));
  */
    // rotate the whole view based on interaction
    ofRotate(rotation.x, 0.0, 1.0, 0.0);
    ofRotate(rotation.y, 1.0, 0.0, 0.0);
    
    // draw globe
    g.draw();
    
    // draw all markers
    m.draw();
    m2.draw();
    m3.draw();
    m4.draw();
    
    c.draw();
    
    camera.end();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    if (touch.id == 0) {
        // store the initial position the first finger went down
        lastTouch = touch;
    }
    
    if (touch.id == 1) {
        // store the initial distance of finger one to finger two
        initialTouchDistance = touch.distance(lastTouch);
    }
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    if (touch.id == 0 && touch.numTouches == 1) {
        // rotate based on first finger position and only do so
        // when there is no more than only one finger down
        
        // use the actual 2 point difference vector, but make the
        // rotation value a lot smaller, and muffle y axis rotation even more
        rotationSpeed = ofVec2f(lastTouch - touch) / 20;
        rotationSpeed.y *= 0.5;
    }
    
    if (touch.id == 1) {
        // zooming the globe
        // detect the _percentual_ change in distance between the two
        // pinching fingers in relation to the initial distance when
        // the second finger first triggered touchDown
        
        float distance = touch.distance(lastTouch);
        float change = distance / initialTouchDistance;
        
        // don't allow zooming to unrealistic percentages
        newZoom = helpers::constrain(change, 0.5, 1.5);
    }
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    // on touch up reset a bunch of reference values
    if (touch.id == 0) {
        lastTouch = touch;
    }
    if (touch.id == 1) {
        initialTouchDistance = 0;
    }
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
