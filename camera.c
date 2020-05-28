#include "camera.h"
#include "consts.h"

void world_to_win(const Camera* cam, Pos* new_pos, const Pos* old_pos) {
	new_pos->x = old_pos->x - cam->x_offset;
	new_pos->y = get_playreg_length(cam) - old_pos->y;
}
void win_to_world(const Camera* cam, Pos* new_pos, const Pos* old_pos) {
	new_pos->x = old_pos->x + cam->x_offset;
	new_pos->y = get_playreg_length(cam) - old_pos->y;
}

int get_playreg_length(const Camera* cam) {
	return (cam->win_size.y+MIN_GROUND)/2;
}

int get_bar_length(const Camera* cam) {
	return (cam->win_size.y-MIN_GROUND)/2;
}
