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
	const int x = (int)cha->pos.x;

	//check every column
	for(int i = 0; i < cha->col_size.x; ++i) {
		if(i + x >= ground_len) { return 0; }
		if(cha->pos.y - 1 <= ground[i + x]) {
			return 1;
		}
	}
	return 0;
}

void scale_num(double* num, int sign, double scale, double max) {
	*num += sign * scale;
	if(sign * *num >= max) {
		*num = sign * max;
	}
	
}

void change_pos(Cha* cha, const Camera* cam, const int* ground, int ground_len, const Pos* dir) {
	Posd* pos = &cha->pos;

	if(on_ground(cha, ground, ground_len)) {
		scale_num(&cha->vel.x, dir->x, .0005, MAX_SPEED);
	} else {
		pos->y -= .5;
	}

	pos->y += cha->vel.y;
	pos->x += cha->vel.x;

}

void init() {
	initscr();
	noecho();
	curs_set(FALSE);
	cbreak();
	nodelay(stdscr, 1);
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
	while(1) {
		Pos dir = { 0, 0 };
		getmaxyx(stdscr, cam.win_size.y, cam.win_size.x);
		erase();

		draw_ground(level1, sizeof_arr(level1), &cam);
		update_img_pos(&ch, &cam);
		draw_img(&ch.img);
		//draw_axes(&cam);

		char c = getch();
		switch(c) {
			case 'd':
				++dir.x;
				break;
			case 'a':
				--dir.x;
				break;
			case 'r':
				ch.pos.y = 10;
				ch.pos.x = 0;
		}
		
		if(i%1000==0 || true) {
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
