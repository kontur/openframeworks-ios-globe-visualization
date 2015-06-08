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
    
    float curviness = -5 * ofMap(distance, 0, 200, 0.25, 2);
    ofNoFill();
    ofSetLineWidth(1);
    ofSetColor(0, 255, 255, ofMap(intensity, 0.0, 1.0, 0, 255));
    ofCurve(fromCoords.x * curviness, fromCoords.y * curviness, fromCoords.z * curviness,
            fromCoords.x, fromCoords.y, fromCoords.z,
            toCoords.x, toCoords.y, toCoords.z,
            toCoords.x * curviness, toCoords.y * curviness, toCoords.z * curviness);
    
    
    ofPopMatrix();
}