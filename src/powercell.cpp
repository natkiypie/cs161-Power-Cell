#include "ofMain.h"
#include "ofApp.h"
#include "powercell.h"

float ship_get_x(struct ship* ship);
float ship_get_y(struct ship* ship);
void ship_light_power_up(struct ship* ship);

struct powercell {
  int x;
  int y;
  int r;
  ofColor color;
};

struct powercell* powercell_construct(int x, int y) {
  struct powercell* thisPowercell = (struct powercell*)malloc(sizeof(struct powercell));
  thisPowercell->x = x;
  thisPowercell->y = y;
  thisPowercell->r = 3;
  thisPowercell->color = ofColor(0, 0, 0);
  return thisPowercell;
}

void powercells_construct(struct powercell* powercells[]) {
  for (int i = 0; i < NUMBER_OF_POWER_CELLS; ++i) {
    powercells[i] = powercell_construct(ofRandom(20, 1580), ofRandom(20, 880));
  }
}

void powercells_draw(struct powercell* powercells[]) {
  for (int i = 0; i < NUMBER_OF_POWER_CELLS; ++i) {
    ofFill();
    ofSetColor(powercells[i]->color);
    ofDrawCircle(powercells[i]->x, powercells[i]->y, powercells[i]->r);
  }
}

bool powercell_calculate_distance_ship(struct ship* ship, struct powercell* powercell) {
  float distance = ofDist(ship_get_x(ship), ship_get_y(ship), powercell->x, powercell->y);
  return distance <= 50;
}

void powercell_collect(struct ship* ship, struct powercell* powercell) {
  if (powercell_calculate_distance_ship(ship, powercell) == true) {
    powercell_relocate(powercell);
    ship_light_power_up(ship);
  }
}

void powercell_relocate(struct powercell* powercell) {
    powercell->x = ofRandom(20, 1580);
    powercell->y = ofRandom(20, 880);
}

void powercells_calculate_distance_ship(struct ship* ship, struct powercell* powercells[]) {
  for (int i = 0; i < NUMBER_OF_POWER_CELLS; ++i) {
    powercell_calculate_distance_ship(ship, powercells[i]);
  }
}

void powercells_collect(struct ship* ship, struct powercell* powercells[]) {
  for (int i = 0; i < NUMBER_OF_POWER_CELLS; ++i) {
    powercell_collect(ship, powercells[i]);
  }
}

void powercells_relocate(struct powercell* powercells[]) {
  for (int i = 0; i < NUMBER_OF_POWER_CELLS; ++i) {
    powercell_relocate(powercells[i]);
  }
}
