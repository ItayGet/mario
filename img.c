#include "img.h"
#include <ncurses.h>
#include <math.h>

void draw_img(const Img* img) {
	for(int i = 0; i < img->size.y; i++) {
		for(int j = 0; j < img->size.x; j++) {
			char c = img->data[i*img->size.x+j];
			if(c == ' ') { continue; }
			mvaddch(i+img->pos.y, j+img->pos.x, c);
		}
	}
}

void img_align_pos(Pos* pos, const Pos* size, double align[2]) {
	pos->y -= floor(align[0] * size->y);
	pos->x -= floor(align[1] * size->x);
}
