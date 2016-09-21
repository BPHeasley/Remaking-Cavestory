#include "stdafx.h"
#include "Animated_Sprite.h"
#include "Graphics.h"
#include "Sprite.h"



Animated_Sprite::Animated_Sprite()
{
}

Animated_Sprite::Animated_Sprite(Graphics & graphics, const std::string & filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate)
	: Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	mFrameIndex(0),
	mTimeToUpdate(timeToUpdate),
	mVisible(true),
	mCurrentAnimationOnce(false),
	mCurrentAnimation(""),
	mTimeElapsed(0)
{
}

Animated_Sprite::~Animated_Sprite()
{
}

// "slices" up the animation from the spritesheet
void Animated_Sprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect newRect = {(i + x) * width, y, width, height};
		rectangles.push_back(newRect);
	}
	mAnimations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));
	mOffsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void Animated_Sprite::resetAnimations()
{
	mAnimations.clear();
	mOffsets.clear();
}

void Animated_Sprite::playAnimation(std::string animation, bool once)
{
	mCurrentAnimationOnce = once;
	if (mCurrentAnimation != animation)
	{
		mCurrentAnimation = animation;
		mFrameIndex = 0;
	}
}

void Animated_Sprite::setVisible(bool visible)
{
	mVisible = visible;
}

void Animated_Sprite::stopAnimation()
{
	mFrameIndex = 0;
	animationDone(mCurrentAnimation);
}

void Animated_Sprite::update(int elapsedTime)
{
	Sprite::update();

	mTimeElapsed += elapsedTime;
	if (mTimeElapsed > mTimeToUpdate)
	{
		mTimeElapsed -= mTimeToUpdate;
		if (mFrameIndex < mAnimations[mCurrentAnimation].size() - 1)
		{
			mFrameIndex++;
		}
		else
		{
			if (mCurrentAnimationOnce == true)
			{
				setVisible(false);
			}
			mFrameIndex = 0;
			animationDone(mCurrentAnimation);
		}
	}
}

void Animated_Sprite::draw(Graphics &graphics, int x, int y)
{
	if (mVisible)
	{
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + mOffsets[mCurrentAnimation].mX;
		destinationRectangle.y = y + mOffsets[mCurrentAnimation].mY;
		destinationRectangle.w = mSourceRect.w * global::SPRITE_SCALE;
		destinationRectangle.h = mSourceRect.h * global::SPRITE_SCALE;

		SDL_Rect sourceRect = mAnimations[mCurrentAnimation][mFrameIndex];
		graphics.blitSurface(mSpriteSheet, &sourceRect, &destinationRectangle);
	}
}

void Animated_Sprite::animationDone(std::string currentAnimation)
{

}

void Animated_Sprite::setupAnimations()
{
	addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}

