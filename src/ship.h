#pragma once

struct ship* ship_construct();
void ship_draw(struct ship* ship);
void ship_collision(struct ship* ship);
void ship_motion(struct ship* ship);
void ship_left_motion(struct ship* ship);
void ship_right_motion(struct ship* ship);
void ship_rotate_left(struct ship* ship);
void ship_rotate_right(struct ship* ship);
void ship_thrust_forward(struct ship* ship);
void ship_thrust_back(struct ship* ship);
void ship_return(struct ship* ship);
float ship_get_x(struct ship* ship);
float ship_get_y(struct ship* ship);
void ship_light_draw(struct ship* ship);
void ship_light_motion(struct ship* ship);
void ship_light_return(struct ship* ship);
bool ship_get_light_status(struct ship* ship);
void ship_light_toggle(struct ship* ship, bool lightOn);
void ship_light_power_down(struct ship* ship);
void ship_light_power_up(struct ship* ship);
void ship_draw_power_bar();
void ship_draw_power_bar_status(struct ship* ship);
struct life* life_construct(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y);
void lives_construct(struct life* lives[]);
void lives_draw(struct life* lives[]);
void life_deduct(struct life* life, int x);
