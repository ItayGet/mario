#pragma once

#include <camera.h>

void draw_ground_upper(const int* ground, int len, const Camera* cam);
void draw_ground_base(int* ground, int len, const Camera* cam);
void draw_ground(int* ground, int len, const Camera* cam);

