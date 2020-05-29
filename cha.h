#pragma once
#include "pos.h"
#include "posd.h"
#include "img.h"
#include "camera.h"

typedef struct {
	Img img;
	Posd pos;
	Pos col_size; //size for physics
	Posd vel;
} Cha;

void update_img_pos(Cha* cha, const Camera* cam);
