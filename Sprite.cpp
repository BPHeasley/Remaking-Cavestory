#include "stdafx.h"
#include "Graphics.h"
#include "Sprite.h"
#include "Global.h"

Sprite::Sprite()
{
}

Sprite::Sprite(Graphics & graphics, const std::string & filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) : mX(posX), mY(posY)
{
	mSourceRect.x = sourceX;
	mSourceRect.y = sourceY;
	mSourceRect.w = width;
	mSourceRect.h = height;

	mSpriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (mSpriteSheet == NULL)
	{
		printf("Error: Unable to load image\n");
	}
}

Sprite::~Sprite()
{
}

void Sprite::draw(Graphics & graphics, int x, int y)
{
	SDL_Rect destinationRectangle = { x, y, mSourceRect.w * global::SPRITE_SCALE, mSourceRect.h * global::SPRITE_SCALE };
	graphics.blitSurface(mSpriteSheet, &mSourceRect, &destinationRectangle);

}

void Sprite::update() {}