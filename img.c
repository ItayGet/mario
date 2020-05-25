#include <ncurses.h>
#include <math.h>
#include "img.h"

void draw_img(const struct img* im) {
	for(int i = 0; i < im->size[0]; i++) {
		for(int j = 0; j < im->size[1]; j++) {
			char c = im->data[i*im->size[1]+j];
			if(c == ' ') { continue; }
			mvaddch(i+im->pos[0], j+im->pos[1], c);
		}
	}
}

void img_align_pos(int* pos, int size[2], double align[2]) {
	pos[0] -= floor(align[0] * size[0]);
	pos[1] -= floor(align[1] * size[1]);
}
