#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    spotlight.enable(); //spotlight is in the global frame and not the camera frame
    
    camera.begin();
    
    foo = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //  Draw a green sphere at the center of the canvas.
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawSphere(ofGetWidth() * .5, ofGetHeight()* .5, 0, 25);
    foo += 1;
    

    cout << spotlight.getPitch();
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
