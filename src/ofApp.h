#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxCsv.h"

#include "globe.h"
#include "marker.h"
#include "helpers.h"
#include "connection.h"
#include "overlay.h"

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
    	overlay *gui;
    
    private:
        // private functions
        void initConnections();
        void addMarker(string, ofVec2f, float);
    
    
        // private variables
    
        // 3d scene setup
        ofCamera camera;
        ofLight spotlight;
        
        float zoom;
        float newZoom;
        float zoomEasing;
        
        ofVec2f rotation;
        ofVec2f rotationSpeed;
        float rotationSpeedEasing;
    
        globe g;
    
        // mapped markers and connections vectors
        vector<marker> markers;
        vector<connection> connections;
    
    
        // interaction helpers
        ofVec2f lastTouch;
        float initialTouchDistance;
    
    
        // IO helpers
        wng::ofxCsv csv;
    
};


