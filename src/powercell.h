#pragma once

struct powercell* powercell_construct(int x, int y);
void powercells_construct(struct powercell* powercells[]);
void powercells_draw(struct powercell* powercells[]);
bool powercell_calculate_distance_ship(struct ship* ship, struct powercell* powercell);
void powercell_collect(struct ship* ship, struct powercell* powercell);
void powercell_relocate(struct powercell* powercell);
void powercells_calculate_distance_ship(struct ship* ship, struct powercell* powercells[]);
void powercells_collect(struct ship* ship, struct powercell* powercells[]);
void powercells_relocate(struct powercell* powercells[]);
