#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "assets.h"
#include "consts.h"
#include "img.h"
#include "cha.h"
#include "camera.h"
#include "ground.h"

int on_ground(const Cha* cha, const int* ground, int ground_len) {
	const int* x = &cha->pos.x;

	//check every column
	for(int i = 0; i < cha->col_size.x; ++i) {
		if(i + *x >= ground_len) { return 0; }
		if(cha->pos.y - 1 <= ground[i + *x]) {
			return 1;
		}
	}
	return 0;
}

void change_pos(Cha* cha, const Camera* cam, const int* ground, int ground_len, const Pos* dir) {
	Pos* pos = &cha->pos;

	if(on_ground(cha, ground, ground_len)) {
		++pos->x;
	} else {
		--pos->y;
	}

}

void init() {
	initscr();
	noecho();
	curs_set(FALSE);
}

void draw_axes(const Camera* cam) {
	for(char i = 0; i<cam->win_size.y; ++i) {
		mvaddch(i, 0, i + 49);
	}
}

#define sizeof_arr(arr) sizeof(arr)/sizeof(arr[0])
void draw() {
	Cha ch = 
	{
		{
			char_anim[0],
			{ 0, 0 }, 
			{ 5, 5 } 
		},
		{ 10, 0 },
		{ 5, 5}
	};

	Camera cam = { { 0, 0 }, 0 };

	int i = 0;
	Pos dir = { 0, 1 };
	while(1) {
		getmaxyx(stdscr, cam.win_size.y, cam.win_size.x);
		erase();

		draw_ground(level1, sizeof_arr(level1), &cam);
		update_img_pos(&ch, &cam);
		draw_img(&ch.img);
		//draw_axes(&cam);
		if(i%1000==0) {
			change_pos(&ch, &cam, level1, sizeof_arr(level1), &dir);
		}
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
