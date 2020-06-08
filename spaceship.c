#include "spaceship.h"

Spaceship* spaceship_create(float sx, float sy) {
    Spaceship* ship = malloc(sizeof(Spaceship));
    ship->sx = 400;
    ship->sy = 400;
    ship->heading = 0;
    ship->speed = 0;
    ship->gone = 0;
    ship->color = al_map_rgb(0, 255, 0);

    return ship;
}

void spaceship_draw(const Spaceship* ship) {
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_rotate_transform(&t, ship->heading);
    al_translate_transform(&t, ship->sx, ship->sy);
    al_use_transform(&t);

    al_draw_line(-8, 9, 0, -11, ship->color, 3.0f);
    al_draw_line(0, -11, 8, 9, ship->color, 3.0f);
    al_draw_line(-6, 4, -1, 4, ship->color, 3.0f);
    al_draw_line(6, 4, 1, 4, ship->color, 3.0f);
}

void spaceship_rotated(Spaceship* ship, Rotated rotated) {
    switch (rotated)
    {
    case LEFT:
        ship->heading -= 0.05;
        break;
    case RIGHT:
        ship->heading += 0.05;
        break;
    default:
        break;
    }
}