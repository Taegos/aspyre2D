#include "engine.h"

int main(int argc, char *args[])
{	
	Engine engine = Engine::setup("Aspyre2D", 60);	
	SDL_Texture* texture = engine.loadTexture("sheet.png");
	
	//SpriteSheet sheet = {"test", 2};
	//Atlas, spritesheet av 2^n
	//Sprite, en rectangel i atlas
	//Animation, flera rektanglar i en atlas
	//engine.getAnimationSystem().submit(0.017f);
	//engine.getAnimationSystem().submit(0.017f);
	engine.getTransformSystem().add(0, {4, 0, {0,0}});
	//engine.getSpriteSystem().add(0, {1, texture});
	engine.getAnimationSystem().add(0, {
		texture,
		32,
		1,
		1,
		{
			{0,0},
			{1,0},
			{2,0},
			{3,0},
			{4,0},
			{5,0},
			{6,0},
			{7,0}
		}
	});

	engine.getInputEmitter().onKeyHeld(SDLK_RIGHT, [&]{engine.getTransformSystem().get(0)->position.x += 0.1f;});
	engine.getInputEmitter().onKeyHeld(SDLK_DOWN, [&]{engine.getTransformSystem().get(0)->position.y += 0.1f;});
	engine.getInputEmitter().onKeyHeld(SDLK_LEFT, [&]{engine.getTransformSystem().get(0)->position.x -= 0.1f;});
	engine.getInputEmitter().onKeyHeld(SDLK_UP, [&]{engine.getTransformSystem().get(0)->position.y -= 0.1f;});
	//Animation= 
	//Storlek
	engine.run();
	return 0;
}