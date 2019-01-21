#pragma once
#include <unordered_map>
#include <vector>
#include "vec2.h"
#include "SDL.h"

struct InputState {
	std::unordered_map<SDL_Keycode, bool> isKeyDown;
	std::unordered_map<SDL_Keycode, bool> isKeyHeld;
	std::unordered_map<SDL_Keycode, bool> isKeyUp;

	std::unordered_map<Uint8, bool> isMouseDown;
	std::unordered_map<Uint8, bool> isMouseUp;
	bool isMouseMoving;
	math::vector::Vec2<int> mousePos;
	bool quitEventSet = false;
};