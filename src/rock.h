#pragma once

struct rock* rock_construct();

void rocks_construct(struct rock* rocks[]);
void rock_draw(struct rock* rock);
void rock_motion(struct rock* rock);
void rock_left_motion(struct rock* rock);
void rock_right_motion(struct rock* rock);
void rock_rotate_left(struct rock* rock);
void rock_rotate_right(struct rock* rock);
void rock_float_left(struct rock* rock);
void rock_float_right(struct rock* rock);
void rock_float_up(struct rock* rock);
void rock_float_down(struct rock* rock);
void rock_rotate_random(struct rock* rock);
void rock_float_random(struct rock* rock);
void rocks_motion(struct rock* rocks[]);
void rocks_left_motion(struct rock* rocks[]);
void rocks_right_motion(struct rock* rocks[]);
void rock_rotate_left(struct rock* rock);
void rocks_draw(struct rock* rocks[]);
void rocks_rotate_left(struct rock* rocks[]);
void rocks_rotate_right(struct rock* rocks[]);
void rocks_float_right(struct rock* rocks[]);
void rocks_float_left(struct rock* rocks[]);
void rocks_float_up(struct rock* rocks[]);
void rocks_float_down(struct rock* rocks[]);
void rock_rotate_random(struct rock* rock);
void rock_float_random(struct rock* rock);
void rocks_rotate_random(struct rock* rocks[]);
void rocks_float_random(struct rock* rocks[]);
bool rock_calculate_distance_ship(struct ship* ship, struct rock* rock);
void rocks_calculate_distance_ship(struct ship* ship, struct rock* rocks[]);
void rock_collision(struct ship* ship, struct rock* rock);
void rocks_collision(struct ship* ship, struct rock* rocks[]);

