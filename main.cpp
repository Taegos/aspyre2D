
#include "engine.h"
#include <iostream>
using namespace std;

int main(int argc, char *args[])
{	
	Engine engine = Engine::setup("Aspyre2D", 60);	
	SpriteSheet sheet = engine.loadSpriteSheet("sheet.png", 32);
	
	TransformSystem& tSystem = engine.getTransformSystem();
	AnimationSystem& aSystem = engine.getAnimationSystem();
	InputEmitter& emitter = engine.getInputEmitter();

	tSystem.add(0, {4, 30, {100,100}});
	aSystem.add(0, {
		&sheet,
		1,
		32,
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

	emitter.onKeyHeld(SDLK_RIGHT, [&]{
		tSystem.get(0)->rotation += 0.3f;
		// tSystem.get(0)->position.x += 0.3f;
		// aSystem.get(0)->flip = SDL_FLIP_NONE;
	});
	emitter.onKeyHeld(SDLK_DOWN, [&]{
	//	tSystem.get(0)->position.y += 0.3f;
	});
	emitter.onKeyHeld(SDLK_LEFT, [&]{
		tSystem.get(0)->rotation -= 0.3f;
		// aSystem.get(0)->flip = SDL_FLIP_HORIZONTAL;
	});
	emitter.onKeyHeld(SDLK_UP, [&]{
		//tSystem.get(0)->position.y -= 0.3f;
	});
	engine.run();
	return 0;
}