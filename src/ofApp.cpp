#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
    cout << "In ofApp::setup()\n";
    
    //The numerical parameter is the length of the history
    plot1 = new ofxHistoryPlot( NULL, "Chan0", 400, false); //NULL cos we don't want it to auto-update. confirmed by "true"
    plot1->setRange(0, ofGetHeight());
    plot1->setColor( ofColor(200,10,200) );
    plot1->setShowNumericalInfo(true);
    plot1->setRespectBorders(true);
    plot1->setLineWidth(3);
    plot1->setAutoRangeShrinksBack(true);
    
    plot2 = new ofxHistoryPlot( NULL, "Chan1", 400, false); //NULL cos we don't want it to auto-update. confirmed by "true"
    plot2->setRange(0, ofGetHeight());
    plot2->setColor( ofColor(200,10,200) );
    plot2->setShowNumericalInfo(true);
    plot2->setRespectBorders(true);
    plot2->setLineWidth(3);
    plot2->setAutoRangeShrinksBack(true);
    
    
    plot1->setDrawGrid(false);
    plot2->setDrawGrid(false);
    
    ofxbci.startStreaming();
    
    time_t seconds = time(NULL);
    ostringstream filename;
    
    //Note this sample file stream only works for Macs
    filename << "~/Desktop/l" << seconds << ".csv";
    cout << "Filename: " << filename.str().c_str() << "\n";
    logFile.open(filename.str().c_str());
    logFile << "timestamp,prompt,chan0,chan1,chan2,chan3,chan4,chan5,chan6,chan7,\n";

}

//--------------------------------------------------------------
void ofApp::update(){

    //Get any and all bytes off the serial port
    ofxbci.update(false); //Param is to echo to the command line
    if(ofxbci.isNewDataPacketAvailable())
    {
        vector<openBCIPacket> newData = ofxbci.getData();
        
        printf("Sees %lu new packets\n", newData.size());
        
        for (int i=0; i<newData.size(); ++i) {
            plot1->update(newData[i].values[0]);
            logFile << newData[i].values[0] << ",";
            
            plot2->update(newData[i].values[1]);
            logFile << newData[i].values[1] << ",";
            
            logFile << "\n";
        }
    }

}


//--------------------------------------------------------------
void ofApp::draw(){

    plot1->draw(10, 10, 1024, 240);
    plot2->draw(10, 300, 1024, 240);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==OF_KEY_RETURN)
    {
        if(!boardIsStreaming){
            ofHttpResponse res = ofLoadURL("http://localhost:5000/board/stream/start");
            boardIsStreaming = true;
        }
        else{
            ofHttpResponse res = ofLoadURL("http://localhost:5000/board/stream/stop");
            boardIsStreaming = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
