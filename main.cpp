#include "engine.h"
#include <iostream>
using namespace std;

int main(int argc, char *args[])
{	
	Engine engine = Engine::setup("Aspyre2D", 60);	
	engine.getInputEmitter().onKeyDown(SDLK_LEFT, [] { cout << "left" << endl;});
	engine.getInputEmitter().onKeyHeld(SDLK_RIGHT, [] { cout << "right held" << endl;});
	engine.run();
	return 0;
}