#pragma once
#include <SDL.h>
#define sizeOffset 2.f


struct Resolution {
	int x = 640;
	int y = 480;
};

class Vector2D {
	public:
		int x;
		int y;
		Vector2D(int X, int Y) { x = X; y = Y; };
};

