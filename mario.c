#include <ncurses.h>
#include <unistd.h>
#include <math.h>

//minimum amount of columns for the ground
#define MIN_GROUND 5

const char* char_anim[] = {
"(_)  "
"(0-0)"
"\\___/"
"|||| "
"|||| "
,
"(_)  "
"(0-0)"
"\\___/"
" ||||"
" ||||"
};


void draw_pic(const char* pic, int pos[2], int size[2]) {
	for(int i = 0; i < size[0]; i++) {
		for(int j = 0; j < size[1]; j++) {
			mvaddch(i+pos[0], j+pos[1], pic[i*size[1]+j]);
		}
	}
}

void draw_pic_align(const char* pic, int pos[2], int size[2], double align[2]) {
	int new_pos[2] = {
		pos[0] - floor(align[0] * size[0]),
		pos[1] - floor(align[1] * size[1]),
	};
	draw_pic(pic, new_pos, size);
}

void init() {
	initscr();
	noecho();
	curs_set(FALSE);
}

void draw() {
	int pos[2] = { 5, 0 }, size[2] = { 5, 5 };
	double alignment[2] = { 1, 0 };
	int i = 0;
	while(1) {
		erase();

		draw_pic_align(char_anim[i/10000%2==0], pos, size, alignment);
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
