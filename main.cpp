
#include "engine.h"

int main(int argc, char *args[])
{	
	Engine engine = Engine::setup("Aspyre2D", 60);	
	SpriteSheet sheet = engine.loadSpriteSheet("sheet.png", 32);
	
	engine.getTransformSystem().add(0, {4, 0, {0,0}});
	engine.getAnimationSystem().add(0, {
		sheet,
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
	engine.run();
	return 0;
}