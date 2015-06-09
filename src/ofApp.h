#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxCsv.h"

#include "globe.h"
#include "marker.h"
#include "helpers.h"
#include "connection.h"
#include "overlayController.h"
#include "overlayView.h"

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
    	// touch event handlers
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
    	// user interface
    	overlayController *gui;
	    void toggleTexture(bool);
	    void setMaxConnections(int);
    
    private:
        // private functions
        void initConnections(int);
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
	    unsigned int maxConnections;
    
    
        // interaction helpers
        ofVec2f lastTouch;
        float initialTouchDistance;
    
    
        // IO helpers
        wng::ofxCsv csv;
    
};


