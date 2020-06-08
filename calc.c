#include "calc.h"

float per_second(float val) {
    return val / FPS;
}

float to_radians(float degrees) {
    return degrees * PI / 180;
}

float true_x(float heading, float speed) {
    printf("X : heading = %f, speed = %f, returned %f\n", heading, speed, sin(heading) * speed);
    return (float)sin(heading) * speed;
}

float true_y(float heading, float speed) {
    printf("Y : heading = %f, speed = %f, returned %f\n", heading, speed, cos(heading) * speed);
    return -1.0f * (float)cos(heading) * speed;
}