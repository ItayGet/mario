#include "ground.h"
#include "pos.h"
#include <ncurses.h>

void draw_ground_upper(const int* ground, int len, const Camera* cam) {
	Pos pos;
	Pos pos_on_win;
	for(pos.x = 0; pos.x < len; ++pos.x) {
		for(pos.y = 1; pos.y <= ground[pos.x]; ++pos.y) {
			world_to_win(cam, &pos_on_win, &pos);
			mvaddch(pos_on_win.y, pos_on_win.x, '#');
		}
	}
}

void draw_ground_base(int* ground, int len, const Camera* cam) {
	Pos pos;
	Pos pos_on_win;
	int bar_len = get_bar_length(cam);
	for(pos.x = 0; pos.x < len; ++pos.x) {
		if(ground[pos.x] == 0) { continue; }
		for(pos.y = 0; pos.y <= bar_len + 1; ++pos.y) { //added 1 because of rounding error
			pos_on_win.y = cam->win_size.y - pos.y;
			pos_on_win.x = pos.x;
			mvaddch(pos_on_win.y, pos_on_win.x, '#');
		}
	}
}

void draw_ground(int* ground, int len, const Camera* cam) {
	draw_ground_base(
			ground,
			len,
			cam
			);
	draw_ground_upper(
			ground,
			len,
			cam
			);
}
