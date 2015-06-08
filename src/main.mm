#include "ofMain.h"
#include "ofApp.h"

int main(){
	//ofSetupOpenGL(1024,768,OF_FULLSCREEN);			// <-------- setup the GL context

    ofAppiOSWindow * iOSWindow = new ofAppiOSWindow();
    ofSetupOpenGL(iOSWindow, 1024, 768, OF_FULLSCREEN);
    iOSWindow->enableRetina();
    iOSWindow->enableDepthBuffer();
    
	ofRunApp(new ofApp());
}
