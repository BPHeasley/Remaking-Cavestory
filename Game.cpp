#include "stdafx.h"
#include "Game.h"
#include "SDL.h"
#include "Graphics.h"
#include "Input.h"
#include <algorithm>

//	Holds all information for the main game loop
namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
	// max time a frame is allowed to exist
}

Game::Game()
{
	// initialize SDL timer, audio, events, etc.
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}


Game::~Game()
{
}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	// SDL_Event holds the event that happens during each frame
	SDL_Event event;

	// gets the player sprite
	mPlayer = Animated_Sprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16, 100, 100, 100);
	mPlayer.setupAnimations();
	mPlayer.playAnimation("RunRight");

	// gets the number of milliseconds
	// since the SDL library initialization
	int LAST_UPDATE_TIME = SDL_GetTicks();

	// start the game loop
	while (true)
	{
		// resets pressed and released keys
		input.beginNewFrame();


		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				// verifies that the user is not holding down a key
				if (event.key.repeat == 0)
				{
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT)
			{
				// allows user to exit the game via x button
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			// if the user presses escape, exits the game
			return;
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		// How long the current frame took
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();

	// draws the character to the screen
	// PLACEHOLDER
	mPlayer.draw(graphics, 100, 100);

	graphics.flip();
}

void Game::update(float elapsedTime)
{
	mPlayer.update(elapsedTime);
}
