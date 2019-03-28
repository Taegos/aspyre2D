
#include "engine.h"
#include <iostream>
using namespace std;

int main(int argc, char *args[])
{	
	Engine engine = Engine::setup("Aspyre2D", 60);	
	SpriteSheet sheet = engine.loadSpriteSheet("sheet.png", 32);
	SpriteSheet debug = engine.loadSpriteSheet("debug.png", 32);

	TransformSystem& tSystem = engine.getTransformSystem();
	SpriteSystem& sSystem = engine.getSpriteSystem();
	InputEmitter& emitter = engine.getInputEmitter();
	AnimationSystem& aSystem = engine.getAnimationSystem();


	tSystem.add(0, {1, 0, {5, 5}});
	sSystem.add(0, {
		&debug,		
		1,
		{0,0}
	});

	// tSystem.add(1, {4, 0, {50, 50}});
	// aSystem.add(1, {
	// 	&sheet,
	// 	2,
	// 	2,	
	// 	{
	// 		{0,0},
	// 		{1,0},
	// 		{2,0},
	// 		{3,0}
	// 	} 
	// });

	emitter.onKeyHeld(SDLK_RIGHT, [&]{
		tSystem.get(0)->position.x += 0.3f;
	});
	emitter.onKeyHeld(SDLK_DOWN, [&]{
		tSystem.get(0)->position.y += 0.3f;
	});
	emitter.onKeyHeld(SDLK_LEFT, [&]{
		tSystem.get(0)->position.x -= 0.3f;
	});
	emitter.onKeyHeld(SDLK_UP, [&]{
		tSystem.get(0)->position.y -= 0.3f;
	});
	emitter.onKeyHeld(SDLK_a, [&]{
		tSystem.get(0)->rotation -= 0.3f;
	});
	emitter.onKeyHeld(SDLK_d, [&]{
		tSystem.get(0)->rotation += 0.3f;
	});
	engine.run();
	return 0;
}