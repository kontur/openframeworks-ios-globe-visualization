//
//  marker.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#include "marker.h"


marker::marker() {
    lat = 0;
    lng = 0;
}

void marker::draw() {
    ofSetColor(255, 120, 0);
    ofFill();
    
    float R = 100;
    float x = R * cos(lat) * cos(lng);
    float y = R * cos(lat) * sin(lng);
    float z = R *sin(lat);
    
    ofDrawSphere(x, y, z, 5);
}

void marker::update() {
    
}

void marker::setLatLng(float _lat, float _lng) {
    lat = _lat;
    lng = _lng;
}