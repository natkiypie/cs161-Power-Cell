#pragma once

struct debris* debris_create();
void debris_plural_construct(struct debris* debris_plural[]);
void debris_plural_draw(struct debris* debris[]);
void debris_plural_rise(struct debris* debris[]);
void debris_plural_rise_return(struct debris* debris_plural[]);
void debris_plural_horizontal_motion(struct debris* debris_plural[]);
void debris_plural_vertical_motion(struct debris* debris_plural[]);
void debris_plural_move_left(struct debris* debris_plural[]);
void debris_plural_move_right(struct debris* debris_plural[]);
void debris_plural_move_up(struct debris* debris_plural[]);
void debris_plural_move_down(struct debris* debris_plural[]);
void debris_plural_return(struct debris* debris[]);
