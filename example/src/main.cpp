#include "testApp.h"


//--------------------------------------------------------------
int main()
{
    ofSetupOpenGL(1024, 768, ofWindowMode::OF_WINDOW);
	ofRunApp(new testApp()); // start the app
}
