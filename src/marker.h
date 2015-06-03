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

class marker {
    
    
    public:
        marker();
        void draw();
        void update();
        void setLatLng(float, float);

    private:
        float lat;
        float lng;
    
    
};

#endif /* defined(__GlobeVisualization__marker__) */
