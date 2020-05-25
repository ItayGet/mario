#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "assets.h"
#include "img.h"

void draw_ground_upper(int* ground, int len, int base) {
	for(int i = 0; i < len; i++) {
		for(int j = 1; j <= ground[i]; j++) {
			mvaddch(base-j, i, '#');
		}
	}
}

void draw_ground_base(int* ground, int len, int base, int height) {
	for(int i = 0; i < len; i++) {
		if(ground[i] == 0) { continue; }
		for(int j = 1; j <= height+1; j++) {
			mvaddch(base-j, i, '#');
		}
	}
}

void draw_ground(int* ground, int len, int win_size[2]) {
	draw_ground_base(
			ground,
			len,
			win_size[0],
			(win_size[0]-MIN_GROUND)/2 + 1 //rounding error
			);
	draw_ground_upper(
			ground,
			len,
			(win_size[0]+MIN_GROUND)/2
			);
}

void change_pos(int pos[2], int* ground, int ground_len, int size[2]) {
}

void init() {
	initscr();
	noecho();
	curs_set(FALSE);
}

void draw() {
	int pos[2] = { 6, 1 }, size[2] = { 5, 5 };
	double alignment[2] = { 1, 0 };

	struct img c = { char_anim[0], { 1, 1 }, { 5, 5 } };

	int i = 0;
	int win_size[2];
	while(1) {
		getmaxyx(stdscr, win_size[0], win_size[1]);
		erase();

		draw_ground(level1, sizeof(level1)/sizeof(level1[0]), win_size);
		draw_img(&c);
		if(i%10000==0) { c.pos[1] += 1; }
		++i;

		refresh();

		//usleep(1000);
	}
}

int main(int argc, char* argv[]) {
	init();

	draw();

	sleep(1);

	endwin();
}
