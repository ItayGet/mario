#pragma once

typedef struct {
	union {
		struct {
			int y;
			int x;
		};
		int arr[2];
	};
} Pos;
