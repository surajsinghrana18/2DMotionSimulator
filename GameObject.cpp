#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, float x, float y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xfinalvelocity = x;
	yfinalvelocity = y;

	std::cout << "Enter value of initial velocity: ";
	std::cin >> initialvelocity;
	std::cout << "\nEnter value of acceleration: ";
	std::cin >> acceleration;
	std::cout << "\nWant faster character? (y/n) "; //10x increase to acceleration and velocity
	std::cin >> super;
	if (super == 'y')
	{
		initialvelocity *= 10;
		acceleration *= 10;
	}
}

void GameObject::Update()
{
	xfinalvelocity = initialvelocity + acceleration*time; //final speed v = u + at.
	yfinalvelocity = initialvelocity + acceleration*time;
	time++;

	sprite.h = 48; //determines height and width of the sprite
	sprite.w = 30;
	sprite.x = 0 + 30*(time%4); //chooses the sprite from the sheet
	if (super == 'y')
		sprite.y = 48;
	else
		sprite.y = 0;

	frame.x = initialvelocity*time + (acceleration*time*time)/2; //displacement s = ut + (a*t^2)/2
	frame.y = initialvelocity*time + (acceleration*time*time)/2;

	frame.w = sprite.w*2; //determines size of the sprite
	frame.h = sprite.h*2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &sprite, &frame);
}