#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofDisableDepthTest();
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    g.setTexture("earth2.bmp");
    
    m.setLatLng(0, 0);
    m2.setLatLng(60, 20);
    m3.setLatLng(0, 20);
    m4.setLatLng(30, 30);
    rotation = ofVec2f(0);
    rotationSpeed = ofVec2f(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    rotation = rotation - rotationSpeed;
    rotationSpeed *= 0.9;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
    camera.begin();
    
    camera.setPosition(ofVec3f(0, 0, 300));
    camera.lookAt(ofVec3f(0, 0, 0));
    camera.setNearClip(0.0);
    camera.setFarClip(1000.0);

    spotlight.enable();
    spotlight.setPosition(-300, 300, -300);
    spotlight.setAmbientColor(ofFloatColor(100, 100, 100));
    spotlight.setDiffuseColor(ofFloatColor(100, 100, 100));
    spotlight.lookAt(ofVec3f(0, 0, 0));
    //spotlight.setAttenuation(0, 1, 0);
    
    ofColor(255, 0, 0);
    ofDrawSphere(100, 100, 100, 5);
    
    //ofRotateX(180);
    
    ofRotate(rotation.x, 0.0, 1.0, 0.0);
    ofRotate(rotation.y, 1.0, 0.0, 0.0);
    g.draw();
    
    m.draw();
    m2.draw();
    m3.draw();
    m4.draw();
    
    camera.end();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    if (touch.id == 0) {
        lastTouch = touch;
    }
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    rotationSpeed = ofVec2f(lastTouch - touch) / 5;
    rotationSpeed.y *= 0.5;
    ofLog() << rotationSpeed;
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    lastTouch = touch;
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
