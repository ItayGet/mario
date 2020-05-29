#include <math.h>
#include "cha.h"

void update_img_pos(Cha* cha, const Camera* cam) {
	Pos pos = { ceil(cha->pos.y), ceil(cha->pos.x) };
	world_to_win(cam, &cha->img.pos, &pos);
	double align[2] = { 1, 0 };
	img_align_pos(&cha->img.pos, &cha->img.size, align);
	++cha->img.pos.y;
}
