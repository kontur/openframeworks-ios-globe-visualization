//
//  marker.h
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#ifndef __GlobeVisualization__marker__
#define __GlobeVisualization__marker__

#include "ofMain.h"
#include "helpers.h"
#include "ofxiOS.h"

class marker {
    
    public:
        marker();
        void draw();
        void update(float);
        void setLatLng(ofVec2f);

    private:
        float radius;
        ofVec2f geolocation;
        ofVec3f coordinates;
    
        void updateCoordinates(float);
    
};

#endif /* defined(__GlobeVisualization__marker__) */
