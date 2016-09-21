#pragma once

namespace global
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	const int SPRITE_SCALE = 2;
}

struct Vector2
{
public:
	int mX, mY;
	Vector2() :
		mX(0), mY(0)
	{}
	Vector2(int x, int y) :
		mX(x), mY(x)
	{}

	Vector2 Vector2_zero() {
		return Vector2(0, 0);
	}
};