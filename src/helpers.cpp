//
//  helpers.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#include "helpers.h"

/**
 * Simple number constrain
 */
float helpers::constrain(float value, float min, float max) {
    
    // rectify the order of min and max if needed
    if (min > max) {
        float m = max;
        max = min;
        min = m;
    }
    
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
};


/**
 * Simple conversion from two dimensional vector to coordinates
 */
ofVec3f helpers::geolocationToCoordinates(ofVec2f geolocation, float radius) {
    
    float latDeg = ofDegToRad(geolocation.x);
    float lngDeg = ofDegToRad(geolocation.y);
    
    float x = (radius * cos(latDeg) * cos(lngDeg));
    float y = (radius * cos(latDeg) * sin(lngDeg));
    float z = radius * sin(latDeg);
    
    return ofVec3f(x, y, z);
}

