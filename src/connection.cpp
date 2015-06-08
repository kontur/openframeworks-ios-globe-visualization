//
//  connection.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#include "connection.h"

connection::connection() {
    radius = 100;
}


void connection::init(ofVec2f _from, ofVec2f _to) {
    from = _from;
    to = _to;
}


void connection::draw() {
    
    ofVec3f fromCoords = helpers::geolocationToCoordinates(from, radius);
    ofVec3f toCoords = helpers::geolocationToCoordinates(to, radius);
    
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    
    
    ofSetColor(0, 255, 255, 100);

    ofDrawSphere(fromCoords.x, fromCoords.y, fromCoords.z, 2);
    ofDrawSphere(toCoords.x, toCoords.y, toCoords.z, 2);

    
    float curviness = -5;
    ofNoFill();
    ofSetLineWidth(1);
    ofCurve(fromCoords.x * curviness, fromCoords.y * curviness, fromCoords.z * curviness,
            fromCoords.x, fromCoords.y, fromCoords.z,
            toCoords.x, toCoords.y, toCoords.z,
            toCoords.x * curviness, toCoords.y * curviness, toCoords.z * curviness);
    
    
    ofPopMatrix();
}