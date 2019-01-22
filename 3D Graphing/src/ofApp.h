#pragma once

#include "ofMain.h"
#include "camera.hpp"
#include "line.hpp"
#include "plane.hpp"
#include "point.hpp"
#include "segment.hpp"
#include "global.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    private:
        CeasyCam cam;
    
        std::vector<GraphPoint> p;
        std::vector<GraphPoint> axes;
    
        std::vector<Line> l;
        std::vector<Line> gl;
    
        std::vector<Plane> pl;
    
        bool xPressed, yPressed, zPressed, upPressed, downPressed;
    
        bool scaleIncrease[4];
        bool scaleDecrease[4];
    
        bool m[4] = {false, false, false, false};

    
        void changeScale();
        void updateScale();
};
