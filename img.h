#pragma once
#include "pos.h"

typedef struct {
	const char* data;
	Pos pos;
	Pos size;
} Img;

void img_align_pos(Pos* pos, const Pos* size, double align[2]);

void draw_img(const Img* im);
