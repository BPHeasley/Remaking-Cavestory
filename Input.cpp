#include "stdafx.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

//This function is called at the beginning of each new frame
// to reset the keys that are no longer relevant
void Input::beginNewFrame()
{
	mPressedKeys.clear();
	mReleasedKeys.clear();
}

// This function is called when a key is released
void Input::keyUpEvent(const SDL_Event & event)
{
	mReleasedKeys[event.key.keysym.scancode] = true;
	mHeldKeys[event.key.keysym.scancode] = false;
}

// This gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event & event)
{
	mPressedKeys[event.key.keysym.scancode] = true;
	mHeldKeys[event.key.keysym.scancode] = true;
}

// Checks if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
	// return a bool from that key on whether or not it was pressed this frame
	return mPressedKeys[key];
}

// Checks if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key)
{
	return mReleasedKeys[key];
}

// Checks if a certain key is currently being held
bool Input::isKeyHeld(SDL_Scancode key)
{
	return mHeldKeys[key];
}