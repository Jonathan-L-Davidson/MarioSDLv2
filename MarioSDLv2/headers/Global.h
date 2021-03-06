#pragma once
#include <SDL.h>
#define levelDir "./resources/levels/"
#define sizeOffset 2.f

const bool DEBUG = true;

struct Resolution {
	int x = 640;
	int y = 480;
};

class Vector2D {
	public:
		int x;
		int y;
		Vector2D(int X, int Y) { x = X; y = Y; };
		Vector2D() { x = 0; y = 0; };
};

class VectorF2D {
	public:
		float x;
		float y;
		VectorF2D(float X, float Y) { x = X; y = Y; };
		VectorF2D() { x = 0; y = 0; };
};

