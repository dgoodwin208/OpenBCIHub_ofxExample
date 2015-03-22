#pragma once

#include "ofMain.h"
#include "ofxOpenBCIOSC.h"
#include "ofxHistoryPlot.h"

// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp {
	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont font;

		int current_msg_string;
		string msg_strings[NUM_MSG_STRINGS];
		float timers[NUM_MSG_STRINGS];

    
        ofxOpenBCIOSC ofxbci;
        ofxHistoryPlot * plot1; //manual
        ofxHistoryPlot * plot2;
    
        ofstream logFile;
    
        //cheap way of start/stop management for now
        bool boardIsStreaming;
};
