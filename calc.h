#pragma once

#include <math.h>
#include <stdio.h>

#define WIDTH   800
#define HEIGHT  600
#define FPS     60
#define PI      3.14159f

float per_second(float val);

float to_radians(float degrees);

float true_x(float heading, float speed);

float true_y(float heading, float speed);