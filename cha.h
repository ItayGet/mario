#pragma once
#include "pos.h"
#include "img.h"
#include "camera.h"

typedef struct {
	Img img;
	Pos pos;
	Pos col_size; //size for physics
} Cha;

void update_img_pos(Cha* cha, const Camera* cam);
