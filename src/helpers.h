//
//  helpers.h
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#ifndef __GlobeVisualization__helpers__
#define __GlobeVisualization__helpers__

#include <stdio.h>
#include "ofxiOS.h"

class helpers {
    public:
        static float constrain(float, float, float);
        static ofVec3f geolocationToCoordinates(ofVec2f, float);
};

#endif /* defined(__GlobeVisualization__helpers__) */
