#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    g.setTexture("earth.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    g.update();
    foo++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    
    camera.setPosition(ofVec3f(0, 0, -300));
    camera.lookAt(ofVec3f(0, 0, 0));
    camera.setNearClip(0.0);
    camera.setFarClip(1000.0);

    spotlight.enable();
    spotlight.setPosition(0, 0, -300);
    spotlight.setAmbientColor(ofFloatColor(255, 0, 0));
    
    ofRotate(foo, 0.0, 1.0, 0.0);
    g.draw();
    
    camera.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

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
