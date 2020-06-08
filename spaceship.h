#pragma once
#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

//typedef struct SpaceshipStruct Spaceship;
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;

typedef enum  {
    STOP, LEFT, RIGHT
} Rotated;

Spaceship* spaceship_create(float sx, float sy);

void spaceship_draw(const Spaceship* ship);

void spaceship_rotated(Spaceship* ship, Rotated rotated);

void spaceship_check();

void spaceship_speedup(Spaceship* ship, float speed);

void spaceship_update(Spaceship* ship);

#endif // !_SPACESHIP_H
