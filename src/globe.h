//
//  globe.h
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#ifndef GlobeVisualization_globe_h
#define GlobeVisualization_globe_h


#include "ofMain.h"

class globe {
    
    public:
        void update();
        void draw();
    
        globe();
    
    
        void setTexture(string);
    
    private:
        ofImage textureImage;
        ofTexture texture;
    
};

#endif
