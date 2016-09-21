// Remaking Cavestory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Game.h"

#undef main
// undef main allows SDL2 to work, multiple main functions cannot exist, so one must be undefined
int main()
{
	Game game;

	return 0;
}