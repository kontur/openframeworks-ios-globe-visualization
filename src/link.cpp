//
//  link.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 06/06/15.
//
//

#include "link.h"

link::link() {
    
}


void link::init(ofVec2f _from, ofVec2f _to) {
    from = _from;
    to = _to;
}


void link::draw() {
    
    ofSetColor(255, 120, 0);
    ofFill();
    
    ofVec3f fromCoords = helpers::geolocationToCoordinates(from, 100);
    ofVec3f toCoords = helpers::geolocationToCoordinates(to, 100);
    
    
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    ofLine(fromCoords.x, fromCoords.y, toCoords.x, toCoords.y);
    
    
    ofPopMatrix();
}