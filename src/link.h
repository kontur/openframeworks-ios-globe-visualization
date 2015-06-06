//
//  link.h
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

class link {
    public:
        link();
        void init(ofVec2f, ofVec2f);
        void draw();
    
    private:
        // geocoordinates of the endpoints stored in
        // two-dimensional vectors
        ofVec2f from;
        ofVec2f to;
};

#endif /* defined(__GlobeVisualization__link__) */
