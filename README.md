# OpenBCIHub_ofxExample
openFrameworks example application of the new OpenBCI Hub

## Requirements
* ofxHistoryPlot [available here](https://github.com/armadillu/ofxHistoryPlot), props to [armadillu] (https://github.com/armadillu) for a simple streaming plot library
* ofxOSC (I believe this is a standard add-on in OF8+, correct me if I'm wrong)
Note: This repo is an XCode-based OF project. Apologies to Windows or Linux users, let me know if you have any trouble getting this working.

## Getting Started
This application is a client of the new [OpenBCI Hub](https://github.com/dgoodwin208/OpenBCI_Hub). You must clone and run the Hub before this application can do anything.

```
your-obcihub-dir > python app --simulator
```

Then you can run the openframeworks app. When you press `ENTER` it will use the RESTful API of the Hub to start the OSC stream. You should see activity similar to the screenshot below

![](https://github.com/dgoodwin208/OpenBCIHub_ofxExample/blob/master/screenshot.png)
