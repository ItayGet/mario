#pragma once

typedef struct {
	union {
		struct {
			double y;
			double x;
		};
		double arr[2];
	};
} Posd;
