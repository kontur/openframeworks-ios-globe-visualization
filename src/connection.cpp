//
//  connection.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#include "connection.h"

connection::connection() {
    
}


void connection::init(ofVec2f _from, ofVec2f _to) {
    from = _from;
    to = _to;
}


void connection::draw() {
    
    ofVec3f fromCoords = helpers::geolocationToCoordinates(from, 100);
    ofVec3f toCoords = helpers::geolocationToCoordinates(to, 100);
    
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    
    ofSetColor(0, 255, 255);
    ofLine(fromCoords.x, fromCoords.y, toCoords.x, toCoords.y);
    
    
    ofPopMatrix();
}