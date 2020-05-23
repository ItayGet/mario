#include <ncurses.h>
#include <unistd.h>

const char* char_idle = 
"(_)  "
"(0-0)"
"\\___/"
"|||| "
"|||| "
;
const char* char_walk = 
"(_)  "
"(0-0)"
"\\___/"
" ||||"
" ||||"
;


void draw_pic(const char* pic, int pos[2], int size[2]) {
	for(int i = 0; i < size[0]; i++) {
		for(int j = 0; j < size[1]; j++) {
			mvaddch(i+pos[0], j+pos[1], pic[i*size[1]+j]);
		}
	}
}

void init() {
	initscr();
	noecho();
	curs_set(FALSE);
}

void draw() {
	const char** curr_anim = &char_idle;
	char is_walk = 0;

	int pos[2] = {0, 0}, size[2] = { 5, 5 }, i = 0;
	while(1) {
		erase();

		if(i%10000==0) {
			curr_anim = is_walk ? &char_idle : &char_walk;
			is_walk = !is_walk;
		}

		draw_pic(*curr_anim, pos, size);
		i++;

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
