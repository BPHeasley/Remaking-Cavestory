#pragma once
#include "Sprite.h"
#include "Global.h"
#include <map>
#include <string>
#include <vector>

class Graphics;

/* Animated Sprite class holds logic for animating sprites
*/
class Animated_Sprite :
	public Sprite
{
public:
	Animated_Sprite();
	Animated_Sprite(Graphics & graphics, const std::string & filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
	~Animated_Sprite();

	// if once is false, the animation will only play once,
	// else it will loop
	void playAnimation(std::string animation, bool once = false);

	// updates the animated sprite with a timer
	void update(int elapsedTime);

	// Draws the sprite to the screen
	void draw(Graphics & graphics, int x, int y);

	// A required virtual function that allows each animated sprite to be animated
	virtual void setupAnimations();

protected:
	double mTimeToUpdate;
	bool mCurrentAnimationOnce;
	std::string mCurrentAnimation;

	// adds an animation to the map of animations for the sprite
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	// clears all animations associated with the sprite
	void resetAnimations();

	void stopAnimation();

	// sets the visibility of the animated sprite
	void setVisible(bool visible);

	// logic that occurs when an animation ends
	virtual void animationDone(std::string currentAnimation);
private:
	// map full of animations
	// accessed by name of animation
	// each animation will have a vector containing its frames
	std::map<std::string, std::vector<SDL_Rect> > mAnimations;

	// 
	std::map<std::string, Vector2> mOffsets;

	// which frame in the animation currently at
	int mFrameIndex;

	double mTimeElapsed;

	bool mVisible;
};

