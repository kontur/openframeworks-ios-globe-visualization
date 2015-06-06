//
//  marker.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#include "marker.h"


marker::marker() {
    radius = 100;
    geolocation = ofVec2f(0);
    coordinates = ofVec3f(0);
}

void marker::draw() {
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    
    ofSetColor(255, 120, 0, 100);
    ofFill();
    ofDrawSphere(coordinates.x, coordinates.y, coordinates.z, 5);
    
    ofPopMatrix();
}

void marker::update(float r) {
    updateCoordinates(r);
}

void marker::setLatLng(ofVec2f latlng) {
    geolocation.x = latlng.x;
    geolocation.y = latlng.y;
    
    // upon chaning the geolocation also calculate new coordinates
    updateCoordinates(radius);
}

void marker::updateCoordinates(float r) {
    coordinates = helpers::geolocationToCoordinates(geolocation, radius);
}