#pragma once
#include "input_state.h"
#include <unordered_map>
#include <vector>
#include "SDL.h"

class InputPoller 
{
public:
	InputState poll();
private:
	SDL_Event handler;
	std::unordered_map<SDL_Keycode, bool> isKeyHeld;
};