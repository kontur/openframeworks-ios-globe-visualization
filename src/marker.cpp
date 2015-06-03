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
    
    float latDeg = ofDegToRad(lat);
    float lngDeg = ofDegToRad(lng);
    
    float R = 100;
    float x = (R * cos(latDeg) * cos(lngDeg));
    float y = (R * cos(latDeg) * sin(lngDeg));
    float z = R * sin(latDeg);
    
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    ofDrawSphere(x, y, z, 1);
    
    
    ofPopMatrix();
}

void marker::update() {
    
}

void marker::setLatLng(float _lat, float _lng) {
    lat = _lat;
    lng = _lng;
}