#pragma once

#include "ofMain.h"
#include "card.hpp"
#include "player.hpp"
#include "button.hpp"

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
        vector<Card> deck;
        ofImage faces[52];
        Player p[2];
        int turn = 0;
        string command;
        bool finished;
        bool started;
    
        void compare();
        void reset();
        void restart();
    
        Button b[4];
    
        int money;
        int wager;
        string bet;
        string name[2];
    
        locale loc;
        bool IsNumber();
};
