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