#pragma once
#include "pos.h"

typedef struct {
	Pos win_size;
	int x_offset;
} Camera;

void world_to_win(const Camera* cam, Pos* new_pos, const Pos* old_pos);
void win_to_world(const Camera* cam, Pos* new_pos, const Pos* old_pos);
