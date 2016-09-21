#include "stdafx.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "Global.h"

/* Need to build a window to draw the game
Create a screen in order to do this (screen/window are synonymous)
Cavestory resolution is 640x480
Creating a class dedicated entirely to graphics

Split up headers/implementation files
Graphics class will use SDL functions
Graphics class holds all information dealing with graphics for the game
*/

Graphics::Graphics()
/* Need to create the window in the constructor */
{
	SDL_CreateWindowAndRenderer(global::SCREEN_WIDTH, global::SCREEN_HEIGHT, 0, &mWindow, &mRenderer);
	SDL_SetWindowTitle(mWindow, "Cavestory");
}


Graphics::~Graphics()
{
	SDL_DestroyWindow(mWindow);
}

SDL_Surface* Graphics::loadImage(const std::string & filePath)
{
	if (mSpriteSheets.count(filePath) == 0)
	{
		mSpriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return mSpriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* distinationRectangle)
{
	SDL_RenderCopy(mRenderer, texture, sourceRectangle, distinationRectangle);
	
}

void Graphics::flip()
{
	SDL_RenderPresent(mRenderer);
}

void Graphics::clear()
{
	SDL_RenderClear(mRenderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return mRenderer;
}