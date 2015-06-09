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
        globe();
        void update();
        void draw();
        void setTexture(string);
    void setTextureRendering(bool);
    
    private:
        ofImage textureImage;
        ofSpherePrimitive sphere;
	    bool renderTexture;
    
};

#endif
