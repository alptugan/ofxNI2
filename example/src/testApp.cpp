#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup()
{
    w = 640;
    h = 480;
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	
    ofSetWindowShape(w*2, h);
    
	//device = new ofxNI2::Device;
	//device->setup();
    device.setup();
    
    depthFbo.allocate(w, h, GL_RGBA, 4);
    depthFbo.begin();
    ofClear(0, 0, 0, 0);
    depthFbo.end();
    
	if (depth.setup(device))
	{
		depth.setSize(w, h);
		depth.setFps(30);
		depth.start();
    
	}

	if (ir.setup(device)) // only for xtion device (OpenNI2-FreenectDriver issue)
	{
		ir.setSize(w, h);
		ir.setFps(30);
		ir.start();
	}
	
	/*if (color.setup(device)) // only for kinect device
	{
        color.setSize(w, h);
		color.setFps(60);
		color.start();
	}*/
}

void testApp::exit()
{
	device.exit();
	//delete device;
}

//--------------------------------------------------------------
void testApp::update()
{
    //ir.updateTextureIfNeeded();
}

//--------------------------------------------------------------
void testApp::draw()
{
	
	//color.draw(0, h);
    
    ir.draw();
    
        
    ofPixels px = depth.getPixelsRef(ofGetMouseY(), ofGetMouseX());
        depthFbo.readToPixels(px);
        depth.draw(w, 0);
    depthFbo.draw(w, 0);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}
