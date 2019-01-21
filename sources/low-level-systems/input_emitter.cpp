#include "input_emitter.h"
#include "input_state.h"

using namespace std;
using namespace math::vector;

void InputEmitter::emit(InputState& state)
{
	for (auto it = keyDownDispatch.begin(); it != keyDownDispatch.end(); it++) {
		if (state.isKeyDown[it->first]) {
			invokeAll(keyDownDispatch[it->first]);
		}
	}
	for (auto it = keyHeldDispatch.begin(); it != keyHeldDispatch.end(); it++) {
		if (state.isKeyHeld[it->first]) {
			invokeAll(keyHeldDispatch[it->first]);		
		}
	}
	for (auto it = keyUpDispatch.begin(); it != keyUpDispatch.end(); it++) {
		if (state.isKeyUp[it->first]) {
			invokeAll(keyUpDispatch[it->first]);
		}
	}
}

void InputEmitter::onKeyDown(SDL_Keycode code, function<void()> action)
{
	keyDownDispatch[code].push_back(action);
}

void InputEmitter::onKeyHeld(SDL_Keycode code, function<void()> action)
{
	keyHeldDispatch[code].push_back(action);
}

void InputEmitter::onKeyUp(SDL_Keycode code, function<void()> action)
{
	keyUpDispatch[code].push_back(action);
}

void InputEmitter::onMouseDown(Uint8 code, function<void(Vec2<int>)> action)
{
	mouseDownDispatch[code].push_back(action);
}

void InputEmitter::onMouseHeld(Uint8 code, function<void(Vec2<int>)> action)
{
	mouseHeldDispatch[code].push_back(action);
}

void InputEmitter::onMouseUp(Uint8 code, function<void(Vec2<int>)> action)
{
	mouseUpDispatch[code].push_back(action);
}

void InputEmitter::onMouseMove(function<void(Vec2<int>)> action)
{
	mouseMoveDispatch.push_back(action);
}


void InputEmitter::invokeAll(vector<function<void()>> actions) const
{
	for (function<void()> action : actions) {
		action();
	}
}

void InputEmitter::invokeAll(vector<function<void(Vec2<int>)>> actions, Vec2<int> point) const
{
	for (function<void(Vec2<int>)> action : actions) {
		action(point);
	}
}