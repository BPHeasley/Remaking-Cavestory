#pragma once
#include <SDL.h>
#include <string>
// Sprite class holds all information for individual sprites

class Graphics;

class Sprite
{
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string & filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics & graphics, int x, int y);
protected:
	SDL_Rect mSourceRect;
	SDL_Texture* mSpriteSheet;

private:
	float mX, mY;
};

