#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "globe.h"
#include "marker.h"
#include "helpers.h"
#include "connection.h"

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
    ofCamera camera;
    ofLight spotlight;
    
    float zoom;
    float newZoom;
    float zoomEasing;
    
    globe g;
    marker m, m2, m3, m4;
    connection c;
    
    ofVec2f rotation;
    ofVec2f rotationSpeed;
    float rotationSpeedEasing;
    
    
    ofVec2f lastTouch;
    
    float initialTouchDistance;

};


