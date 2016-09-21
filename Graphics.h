#pragma once
#include <map>
#include <string>
#include <SDL.h>

struct SDL_Window;
struct SDL_Renderer;
// forward declaring SDL windows to avoid including them multiple times

class Graphics
{
public:
	Graphics();
	~Graphics();

	/* SDL_Surface* loadImage
		Loads an image into the mSpriteSheets map if it doesn't already exist
		As a result, each image will only be loaded once
		Returns the image from the map, regardless of whether or not it was just loaded
	*/
	SDL_Surface* loadImage(const std::string & filePath);

	// Draws a texture to a certain part of the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourcedRectangle, SDL_Rect* destinationRectangle);

	// Renders everything to the screen
	void flip();

	// Clears the screen
	void clear();

	// Return renderer 
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	std::map<std::string, SDL_Surface*> mSpriteSheets;
};

