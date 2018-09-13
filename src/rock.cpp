#include "rock.h"
#include "ofMain.h"
#include "ofApp.h"

float ship_get_x(struct ship* ship);
float ship_get_y(struct ship* ship);
void ship_collision(struct ship* ship);
void life_deduct(struct life* life, int x);

static const float ACCELERATION = ofRandom(0.5, 2);

struct rock {
  float x;
  float y;
  float x1;
  float y1;
  float w;
  float h;
  float d;
  float v;
  float mv;
  int number;
  ofColor color;
};

struct rock* rock_construct() {
  struct rock* thisRock = (struct rock*)malloc(sizeof(struct rock));
  thisRock->x = ofRandom(0, 1600);
  thisRock->y = ofRandom(0, 900);
  thisRock->x1 = -50;
  thisRock->y1 = -50;
  thisRock->w = 100;
  thisRock->h = 100;
  thisRock->d = 0;
  thisRock->v = 0;
  thisRock->mv = 0;
  thisRock->number = ofRandom(0, 100);
  thisRock->color = ofColor(0, 0, 0);
  return thisRock;
}

void rocks_construct(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rocks[i] = rock_construct();
  }
}

void rock_draw(struct rock* rock) {
  ofSetColor(rock->color);
  ofPushMatrix();
  ofTranslate(rock->x, rock->y);
  ofRotateDeg(rock->d);
  ofDrawRectangle(rock->x1, rock->y1, rock->w, rock->h);
  ofPopMatrix();
}

void rock_motion(struct rock* rock) {
  rock->x += rock->v * cos((rock->d * PI) / 180);
  rock->y += rock->v * sin((rock->d * PI) / 180);
  rock->v *= 0.99;
}


void rock_left_motion(struct rock* rock) {
  rock->d -= rock->mv;
  rock->mv *= 0.99;
}

void rock_right_motion(struct rock* rock) {
  rock->d += rock->mv;
  rock->mv *= 0.99;
}

void rock_rotate_left(struct rock* rock) {
  rock->mv += 2;
}

void rock_rotate_right(struct rock* rock) {
  rock->mv--;
}

void rock_float_left(struct rock* rock) {
  rock->x -= ACCELERATION;
  if ((rock->x + (rock->w/2)) < 0) {
    rock->x = (ofGetWidth() + (rock->w/2));
  }
}

void rock_float_right(struct rock* rock) {
  rock->x += ACCELERATION;
  if ((rock->x - (rock->w/2)) > ofGetWidth()) {
    rock->x = -(rock->w/2);
  }
}

void rock_float_up(struct rock* rock) {
  rock->y -= ACCELERATION;
  if ((rock->y + (rock->h/2)) < 0) {
    rock->y = (ofGetHeight() + (rock->h/2));
  }
}

void rock_float_down(struct rock* rock) {
  rock->y += ACCELERATION;
  if ((rock->y - (rock->h/2)) > ofGetHeight()) {
    rock->y = -(rock->h/2);
  }
}

void rock_rotate_random(struct rock* rock) {
  if (rock->number < 50) {
    rock_rotate_left(rock);
  } else {
    rock_rotate_right(rock);
  }
}

void rock_float_random(struct rock* rock) {
  if (rock->number < 25) {
    rock_float_left(rock);
  } else if (rock->number < 50) {
    rock_float_right(rock);
  } else if (rock->number < 75) {
    rock_float_up(rock);
  } else {
    rock_float_down(rock);
  }
}

void rocks_draw(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_draw(rocks[i]);
  }
}

void rocks_motion(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_motion(rocks[i]);
  }
}

void rocks_left_motion(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_left_motion(rocks[i]);
  }
}

void rocks_right_motion(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_right_motion(rocks[i]);
  }
}

void rocks_rotate_left(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_rotate_left(rocks[i]);
  }
}

void rocks_rotate_right(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_rotate_right(rocks[i]);
  }
}

void rocks_float_right(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_float_right(rocks[i]);
  }
}

void rocks_float_left(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_float_left(rocks[i]);
  }
}

void rocks_float_up(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_float_up(rocks[i]);
  }
}

void rocks_float_down(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_float_down(rocks[i]);
  }
}

void rocks_rotate_random(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_rotate_random(rocks[i]);
  }
}

void rocks_float_random(struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_float_random(rocks[i]);
  }
}

bool rock_calculate_distance_ship(struct ship* ship, struct rock* rock) {
  float distance = ofDist(ship_get_x(ship), ship_get_y(ship), (rock->w/2), (rock->h/2));
  return distance <= 50;
}

void rocks_calculate_distance_ship(struct ship* ship, struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
    rock_calculate_distance_ship(ship, rocks[i]);
  }
}

void rock_collision(struct ship* ship, struct rock* rock) {
  if (rock_calculate_distance_ship(ship, rock) == true) {
  }
}

void rocks_collision(struct ship* ship, struct rock* rocks[]) {
  for (int i = 0; i < NUMBER_OF_ROCKS; ++i) {
  }
}
