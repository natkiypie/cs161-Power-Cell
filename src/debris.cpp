#include "debris.h"
#include "ofMain.h"
#include "ofApp.h"

static const float VELOCITY = ofRandom(0.005, 0.5);
static const float ACCELERATION = 0.0005;

struct debris {
  float x;
  float y;
  float v;
  float hv;
  float vv;
  float a;
  float lineWidth;
  float lineLength;
  int counter;
  float countLow;
  float countHigh;
  ofColor color;
};

struct debris* debris_create() {
  struct debris* thisDebris = (struct debris*)malloc(sizeof(struct debris));
  thisDebris->x = ofRandom(0, ofGetWidth());
  thisDebris->y = ofRandom(0, ofGetHeight());
  thisDebris->v = VELOCITY;
  thisDebris->hv = 0;
  thisDebris->vv = 0;
  thisDebris->a = ACCELERATION;
  thisDebris->lineWidth = 10;
  thisDebris->lineLength = 8;
  thisDebris->counter = 0;
  thisDebris->countLow = ofRandom(50, 200);
  thisDebris->countHigh = ofRandom(250, 350);
  thisDebris->color = ofColor(34, 45, 6);
  return thisDebris;
}

void debris_plural_construct(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i] = debris_create();
  }
}

void debris_plural_draw(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    ofSetColor(debris_plural[i]->color);
    ofSetLineWidth(debris_plural[i]->lineWidth);
    ofDrawLine(debris_plural[i]->x, debris_plural[i]->y, debris_plural[i]->x, debris_plural[i]->y + debris_plural[i]->lineLength);
  }
}

void debris_plural_rise(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {

    debris_plural[i]->counter++;
    if (debris_plural[i]->counter >= debris_plural[i]->countLow) {
      debris_plural[i]->color = ofColor(77, 102, 15);
    } else {
      debris_plural[i]->color = ofColor(34, 45, 6);
    }

    int direction = ofRandom(0, 100);
    if (direction < 50) {
      debris_plural[i]->x += debris_plural[i]->v;
      debris_plural[i]->v += debris_plural[i]->a;
    } else if (direction > 50) {
      debris_plural[i]->x -= debris_plural[i]->v;
      debris_plural[i]->v += debris_plural[i]->a;
    } else if (direction < 50) {
      debris_plural[i]->y += debris_plural[i]->v;
      debris_plural[i]->v += debris_plural[i]->a;
    } else if (direction > 50) {
      debris_plural[i]->y -= debris_plural[i]->v;
      debris_plural[i]->v += debris_plural[i]->a;
    }

    if (debris_plural[i]->v >= 0.8) {
      debris_plural[i]->v = 0.8;
    }

  }
}

void debris_plural_rise_return(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    if (debris_plural[i]->counter >= debris_plural[i]->countHigh) {
      debris_plural[i]->counter = 0;
    }
  }
}

void debris_plural_horizontal_motion(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i]->x += debris_plural[i]->hv;
    debris_plural[i]->hv *= 0.99;
  }
}

void debris_plural_vertical_motion(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i]->y += debris_plural[i]->vv;
    debris_plural[i]->vv *= 0.99;
  }
}

void debris_plural_move_left(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i]->hv += 0.2;
  }
}

void debris_plural_move_right(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i]->hv -= 0.02;
    if (debris_plural[i]->hv < 2) {
      debris_plural[i]->hv = 2;
    }
  }
}

void debris_plural_move_up(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i]->vv -= 0.2;
  }
}

void debris_plural_move_down(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    debris_plural[i]->vv += 0.2;
  }
}

void debris_plural_return(struct debris* debris_plural[]) {
  for (int i = 0; i < NUMBER_OF_DEBRIS; ++i) {
    if (debris_plural[i]->x < 0) {
      debris_plural[i]->x = ofGetWidth();
    } else if (debris_plural[i]->x > ofGetWidth()) {
      debris_plural[i]->x = 0;
    } else if (debris_plural[i]->y < 0) {
      debris_plural[i]->y = ofGetHeight();
    } else if (debris_plural[i]->y > ofGetHeight()) {
      debris_plural[i]->y = 0;
    }
  }
}

