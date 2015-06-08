//
//  marker.cpp
//  GlobeVisualization
//
//  Created by Johannes Neumeier on 03/06/15.
//
//

#include "marker.h"


marker::marker() {
    radius = 1;
    projectionRadius = 100;
    geolocation = ofVec2f(0);
    coordinates = ofVec3f(0);
    name = "";
}

void marker::draw() {
    ofPushMatrix();
    
    ofRotateY(-90);
    ofRotateX(-90);
    
    ofSetColor(255, 120, 0, 100);
    ofFill();
    ofDrawSphere(coordinates.x, coordinates.y, coordinates.z, radius);
    
    ofPopMatrix();
}

void marker::update(float r) {
    updateCoordinates(r);
}

void marker::setLatLng(ofVec2f latlng) {
    ofLog() << latlng;
    
    geolocation.x = latlng.x;
    geolocation.y = latlng.y;
    
    // upon chaning the geolocation also calculate new coordinates
    updateCoordinates(projectionRadius);
}

void marker::updateCoordinates(float r) {
    coordinates = helpers::geolocationToCoordinates(geolocation, projectionRadius);
}

ofVec3f marker::getCoordinates() {
    return coordinates;
}

void marker::setSize(float s) {
    radius = s;
}

float marker::getSize() {
    return radius;
}

void marker::setName(string n) {
    name = n;
}

string marker::getName() {
    return name;
}