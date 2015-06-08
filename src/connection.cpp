//
//  connection.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#include "connection.h"

connection::connection() {
    projectionRadius = 100;
    intensity = 0.1;
    distance = 0;
}

void connection::init(ofVec2f _from, ofVec2f _to) {
    from = _from;
    to = _to;
    
    ofVec3f fromCoords = helpers::geolocationToCoordinates(from, projectionRadius);
    ofVec3f toCoords = helpers::geolocationToCoordinates(to, projectionRadius);
    
    distance = fromCoords.distance(toCoords);
}

void connection::draw() {
    ofVec3f fromCoords = helpers::geolocationToCoordinates(from, projectionRadius);
    ofVec3f toCoords = helpers::geolocationToCoordinates(to, projectionRadius);
    
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    
    // set dynamic "steepness" of the curve based on the absolute distance
    // between the point; this essentially makes sure the connection curves enough
    // to not go through the globe
    float curviness = -5 * ofMap(distance, 0, 200, 0.5, 2);
    ofNoFill();
    ofSetLineWidth(1);
    
    // set the intensitiy of the connection curves dynamically
    // note even on full never go to 100% opaque (for stylistic reasons)
    int alpha = (int)ofMap(intensity, 0.0, 1.0, 10.0, 200.0);
    int red = (int)ofMap(intensity, 0.0, 1.0, 0.0, 255.0);
    
    ofLog() << red;
    
    ofSetColor(red, 255 - red, 0, alpha);
    ofCurve(fromCoords.x * curviness, fromCoords.y * curviness, fromCoords.z * curviness,
            fromCoords.x, fromCoords.y, fromCoords.z,
            toCoords.x, toCoords.y, toCoords.z,
            toCoords.x * curviness, toCoords.y * curviness, toCoords.z * curviness);
    ofSetColor(0);
    
    ofPopMatrix();
}

void connection::setIntensity(float i) {
    intensity = helpers::constrain(i, 0.0, 1.0);
}