#include "ofMain.h"
#include "ofApp.h"
#include "ship.h"

struct ship {
  float x;
  float y;
  float p1x;
  float p1y;
  float p2x;
  float p2y;
  float p3x;
  float p3y;
  float d;
  float v;
  float mv;
  float a;
  float a2;
  float lightX;
  float lightY;
  float lightR;
  float lightAlpha;
  bool lightStatus;
  float lightPower;
  float powerBarStatus;
  ofColor color;
};

struct ship* ship_construct() {
  struct ship* thisShip = (struct ship*)malloc(sizeof(struct ship));
  thisShip->x = (ofGetWidth()/2);
  thisShip->y = (ofGetHeight()/2);
  thisShip->p1x = -20;
  thisShip->p1y = -32;
  thisShip->p2x = -20;
  thisShip->p2y = 32;
  thisShip->p3x = 54;
  thisShip->p3y = 0;
  thisShip->d = 0;
  thisShip->v = 0;
  thisShip->mv = 0;
  thisShip->a = 0.5;
  thisShip->a2 = 400;
  thisShip->lightX = thisShip->x + 154;
  thisShip->lightY = thisShip->y;
  thisShip->lightR = 100;
  thisShip->lightAlpha = 100;
  thisShip->lightStatus = false;
  thisShip->lightPower = 80;
  thisShip->powerBarStatus = 144;
  thisShip->color = ofColor(255, 255, 255);
  return thisShip;
}

void ship_draw(struct ship* ship) {
  ofNoFill();
  ofSetLineWidth(2);
  ofSetColor(ship->color);
  ofPushMatrix();
  ofTranslate(ship->x, ship->y);
  ofRotateDeg(ship->d);
  ofDrawTriangle(ship->p1x, ship->p1y, ship->p2x, ship->p2y, ship->p3x, ship->p3y);
  ofPopMatrix();
}

void ship_motion(struct ship* ship) {
  ship->x += ship->v * cos((ship->d * PI) / 180);
  ship->y += ship->v * sin((ship->d * PI) / 180);
  ship->v *= 0.99;
}

void ship_left_motion(struct ship* ship) {
  ship->d -= ship->mv;
  ship->mv *= 0.99;
}

void ship_right_motion(struct ship* ship) {
  ship->d += ship->mv;
  ship->mv *= 0.99;
}

void ship_rotate_left(struct ship* ship) {
  ship->mv += ship->a2;
}

void ship_rotate_right(struct ship* ship) {
  ship->mv -= ship->a2;
}

void ship_thrust_forward(struct ship* ship) {
  ship->v += ship->a;
}

void ship_thrust_back(struct ship* ship) {
  ship->v -= ship->a;
}

void ship_return(struct ship* ship) {
  if (ship->x < 0) {
    ship->x = ofGetWidth();
  } else if (ship->x > ofGetWidth()) {
    ship->x = 0;
  } else if (ship->y < 0) {
    ship->y = ofGetHeight();
  } else if (ship->y > ofGetHeight()) {
    ship->y = 0;
  }
}

float ship_get_x(struct ship* ship) {
  return ship->x;
}

float ship_get_y(struct ship* ship) {
  return ship->y;
}

void ship_light_draw(struct ship* ship) {
  if (ship->lightStatus == true) {
    ofFill();
    ofSetCircleResolution(80);
    ofSetColor(255, (ofRandom(230, 255)), (ofRandom(40, 180)), ship->lightAlpha);
    ofPushMatrix();
    ofTranslate(ship->lightX, ship->lightY);
    ofRotateDeg(ship->d);
    ofDrawCircle(0, 0, ship->lightR);
    ofPopMatrix();
  }
}

void ship_light_motion(struct ship* ship) {
  ship->lightX += ship->v * cos((ship->d * PI) / 180);
  ship->lightY += ship->v * sin((ship->d * PI) / 180);
  ship->v *= 0.99;
}

void ship_light_return(struct ship* ship) {
  if (ship->lightX < 0) {
    ship->lightX = ofGetWidth();
  } else if (ship->lightX > ofGetWidth()) {
    ship->lightX = 0;
  } else if (ship->lightY < 0) {
    ship->lightY = ofGetHeight();
  } else if (ship->lightY > ofGetHeight()) {
    ship->lightY = 0;
  }
}

bool ship_get_light_status(struct ship* ship) {
  return ship->lightStatus;
}

void ship_light_toggle(struct ship* ship, bool status) {
  ship->lightStatus = status;
}

void ship_light_power_down(struct ship* ship) {
  if (ship->lightStatus == true) {
    ship->lightPower -= 0.05;
    if (ship->lightPower <= 0) {
      ship->lightPower = 0;
      ship->lightStatus = false;
    }
    ship->lightAlpha -= 0.05;
    ship->lightR -= 0.05;
    ship->powerBarStatus -= 0.09;
    if (ship->lightPower <= 4) {
      ship->lightAlpha = ofRandom(0, 255);
    }
  }
}

void ship_light_power_up(struct ship* ship) {
  ship->lightPower = 80;
  ship->lightAlpha = 100;
  ship->lightR = 100;
  ship->powerBarStatus = 144;
}

void ship_draw_power_bar() {
  ofNoFill();
  ofSetLineWidth(2);
  ofSetColor(255, 255, 255);
  ofDrawRectangle(20, 20, 150, 20);
}

void ship_draw_power_bar_status(struct ship* ship) {
  ofFill();
  ofSetLineWidth(2);
  ofSetColor(255, 255, 255);
  ofDrawRectangle(23, 23, ship->powerBarStatus, 14);
}

struct life {
  int p1x;
  int p1y;
  int p2x;
  int p2y;
  int p3x;
  int p3y;
  ofColor color;
};

struct life* life_construct(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
  struct life* thisLife = (struct life*)malloc(sizeof(struct life));
  thisLife->p1x = p1x;
  thisLife->p1y = p1y;
  thisLife->p2x = p2x;
  thisLife->p2y = p2y;
  thisLife->p3x = p3x;
  thisLife->p3y = p3y;
  thisLife->color = ofColor(255, 255, 255);
  return thisLife;
}

void lives_construct(struct life* lives[]) {
  for (int i = 0; i < NUMBER_OF_LIVES; ++i) {
    static int p1x[] = {200, 230, 260, 290, 320};
    static int p2x[] = {210, 240, 270, 300, 330};
    static int p3x[] = {220, 250, 280, 310, 340};
    lives[i] = life_construct(p1x[i], 40, p2x[i], 20, p3x[i], 40);
  }
}

void lives_draw(struct life* lives[]) {
  for (int i = 0; i < NUMBER_OF_LIVES; ++i) {
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(lives[i]->color);
    ofDrawTriangle(lives[i]->p1x, lives[i]->p1y, lives[i]->p2x, lives[i]->p2y, lives[i]->p3x, lives[i]->p3y);
  }
}

void life_deduct(struct life* life, int x) {
//  lives[x]->color = ofColor(0, 0, 0, 0);
}
