#include "camera.h"
#include "consts.h"

void world_to_win(const Camera* cam, Pos* new_pos, const Pos* old_pos) {
	new_pos->x = old_pos->x + cam->x_offset;
	new_pos->y = (cam->win_size.y+MIN_GROUND)/2 + 1 - old_pos->y; //rounding error
}
void win_to_world(const Camera* cam, Pos* new_pos, const Pos* old_pos) {
	*new_pos = *old_pos;
	//new_pos->x += cam->x_offset;
	//new_pos->y -= (cam->win_size.y-MIN_GROUND)/2 + 1; //rounding error


}
