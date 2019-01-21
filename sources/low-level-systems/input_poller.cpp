#include "input_poller.h"
#include "vec2.h"
#include <iostream>

using namespace std;
using namespace math::vector;
InputState InputPoller::poll()
{
	InputState state = {};

	while (SDL_PollEvent(&handler) != 0)
	{
		if (handler.type == SDL_QUIT)
		{
			state.quitEventSet = true;
		}
		if (handler.key.repeat != 0) {
			return state;
		}
		switch (handler.type)
		{
		case SDL_KEYDOWN:
			state.isKeyDown[handler.key.keysym.sym] = true;
			isKeyHeld[handler.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			isKeyHeld[handler.key.keysym.sym] = false;
			state.isKeyUp[handler.key.keysym.sym] = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			state.isMouseDown[handler.button.button] = true;
			state.mousePos = { handler.button.x, handler.button.y };
			break;
		case SDL_MOUSEBUTTONUP:
			state.isMouseUp[handler.button.button] = true;
			state.mousePos = { handler.button.x, handler.button.y };
			break;
		case SDL_MOUSEMOTION:
			state.isMouseMoving = true;
			state.mousePos = { handler.button.x, handler.button.y };
		default:
			break;
		}
	}
	state.isKeyHeld = isKeyHeld;
	return state;
}