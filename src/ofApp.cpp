#include "ofApp.h"
#include "ship.h"
#include "powercell.h"
#include "debris.h"
#include "rock.h"

void ofApp::setup() {
  aka47.load("aka47.mp3");
  aka47.play();

  deface.load("deface.ttf", 120, true, true, true);

  ofSetBackgroundColor(0, 0, 0);
  debris_plural = (struct debris**)malloc(NUMBER_OF_DEBRIS * sizeof(struct debris*));
  debris_plural_construct(debris_plural);
  ship = ship_construct();
  lives = (struct life**)malloc(NUMBER_OF_LIVES * sizeof(struct life*));
  lives_construct(lives);
  powercells = (struct powercell**)malloc(NUMBER_OF_POWER_CELLS * sizeof(struct powercell*));
  powercells_construct(powercells);
  rocks = (struct rock**)malloc(NUMBER_OF_ROCKS * sizeof(struct rock*));
  rocks_construct(rocks);
}

void ofApp::update() {

  debris_plural_rise(debris_plural);
  debris_plural_rise_return(debris_plural);
  debris_plural_horizontal_motion(debris_plural);
  debris_plural_vertical_motion(debris_plural);
  debris_plural_return(debris_plural);
  debris_plural_move_right(debris_plural);
  ship_motion(ship);
  ship_left_motion(ship);
  ship_right_motion(ship);
  ship_return(ship);
  ship_light_motion(ship);
  ship_light_return(ship);
  ship_light_power_down(ship);
  powercells_collect(ship, powercells);
  rocks_motion(rocks);
  rocks_left_motion(rocks);
  rocks_right_motion(rocks);
  rocks_float_random(rocks);
  rocks_rotate_random(rocks);
//  rocks_collision(ship, rocks);
}

void ofApp::draw() {
  ship_light_draw(ship);

  ofSetColor(0, 0, 0);
  deface.drawString("natkiypie", 410, (ofGetHeight()/2));

  rocks_draw(rocks);
  debris_plural_draw(debris_plural);
  ship_draw(ship);
  powercells_draw(powercells);
  lives_draw(lives);
  ship_draw_power_bar();
  ship_draw_power_bar_status(ship);
}

void ofApp::keyPressed(int key) {
  if (key == OF_KEY_LEFT) {
    ship_rotate_left(ship);
  } else if (key == OF_KEY_RIGHT) {
    ship_rotate_right(ship);
  } else if (key == OF_KEY_UP) {
    ship_thrust_forward(ship);
  } else if (key == OF_KEY_DOWN) {
    ship_thrust_back(ship);
  }

  if (key == ' ') {
    if (ship_get_light_status(ship) == false) {
      ship_light_toggle(ship, true);
    } else if (ship_get_light_status(ship) == true) {
      ship_light_toggle(ship, false);
    }
  }

//  if (key == 'f') {
//    lives_deduct(lives, 4);
//  }
}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y ) {

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::mouseEntered(int x, int y) {

}

void ofApp::mouseExited(int x, int y) {

}

void ofApp::windowResized(int w, int h) {

}

void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) { 

}
