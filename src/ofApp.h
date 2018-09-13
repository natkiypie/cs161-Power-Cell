#pragma once
#include "ofMain.h"

static const int NUMBER_OF_LIVES = 5;
static const int NUMBER_OF_POWER_CELLS = 5;
static const int NUMBER_OF_DEBRIS = 60;
static const int NUMBER_OF_ROCKS = 4;

class ofApp : public ofBaseApp {

	public:
    struct ship* ship;
    struct life** lives;
    struct powercell** powercells;
    struct debris** debris_plural;
    struct rock** rocks;
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);

    ofTrueTypeFont deface; 

    ofSoundPlayer aka47;

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
