//
//  connection.h
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#ifndef __GlobeVisualization__link__
#define __GlobeVisualization__link__

#include <stdio.h>
#include "ofxiOS.h"
#include "helpers.h"

class connection {
    public:
        connection();
        void init(ofVec2f, ofVec2f);
        void draw();
    
        void setIntensity(float);
    
    private:
        // geocoordinates of the endpoints stored in
        // two-dimensional vectors
        ofVec2f from;
        ofVec2f to;
    
        ofVec3f fromCoords;
        ofVec3f toCoords;
    
        // the radius of the globe the connetionon is being projected onto
        float projectionRadius;
    
        // distance of the two connection points on the projection globe
        float distance;
    
        // 0-1 visual indicator
        float intensity;
    
        int alpha;
        int red;
        int yellow;
        float curviness;
    
        void updateLook();
};

#endif /* defined(__GlobeVisualization__link__) */
