#pragma once

struct img {
	const char* data;
	int pos[2];
	int size[2];
};

void img_align_pos(int pos[2], int size[2], double align[2]);

void draw_img(const struct img* im);
