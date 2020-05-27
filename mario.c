#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "assets.h"
#include "consts.h"
#include "img.h"
#include "cha.h"
#include "camera.h"

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

void change_pos(Cha* ch, const Camera* cam, const int* ground, int ground_len, const Pos* dir) {
	Pos* pos = &ch->pos;
	int on_ground = pos->y + 1 == ground[pos->x];

	++pos->x;
	if(on_ground) {
		
	} else {
		
	}

}

void init() {
	initscr();
	noecho();
	curs_set(FALSE);
}

#define sizeof_arr(arr) sizeof(arr)/sizeof(arr[0])
void draw() {
	double alignment[2] = { 1, 0 };
	Cha ch = 
	{
		{
			char_anim[0],
			{ 0, 0 }, 
			{ 5, 5 } 
		},
		{ 4, 0 }
	};

	Camera cam = { { 0, 0 }, 0 };

	int i = 0;
	Pos dir = { 0, 1 };
	while(1) {
		getmaxyx(stdscr, cam.win_size.y, cam.win_size.x);
		erase();

		draw_ground(level1, sizeof_arr(level1), cam.win_size.arr);
		update_img_pos(&ch, &cam);
		draw_img(&ch.img);
		if(i%10000==0) {
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
