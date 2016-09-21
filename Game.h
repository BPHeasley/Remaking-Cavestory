#pragma once
#include "Animated_Sprite.h"
class Graphics;

class Game
{
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Animated_Sprite mPlayer;
};

