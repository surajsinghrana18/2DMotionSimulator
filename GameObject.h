#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texturesheet, float x, float y);

	int time = 0; //time t=0 but increases every cycle
	float acceleration = 0; //constant acceleration a=1. You may change this value as required. 
	float initialvelocity = 0; //initial velocity u=4. You may change this value as required.
	char super = 'n';
	float xfinalvelocity = 0;
	float yfinalvelocity = 0;

	void Update();
	void Render();

private:

	SDL_Texture* objTexture;
	SDL_Rect sprite, frame;

};