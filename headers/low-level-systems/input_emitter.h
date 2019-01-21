#pragma once
#include "input_state.h"
#include <unordered_map>
#include <functional>
#include <vector>
#include "vec2.h"

class InputEmitter
{
public:
	void emit(InputState& state);

	void onKeyDown(SDL_Keycode, std::function<void()>);
	void onKeyHeld(SDL_Keycode, std::function<void()>);
	void onKeyUp(SDL_Keycode, std::function<void()>);

	void onMouseDown(Uint8, std::function<void(math::vector::Vec2<int>)>);
	void onMouseHeld(Uint8, std::function<void(math::vector::Vec2<int>)>);
	void onMouseUp(Uint8, std::function<void(math::vector::Vec2<int>)>);
	void onMouseMove(std::function<void(math::vector::Vec2<int>)>);
	
private:
	void invokeAll(std::vector<std::function<void()>>) const;
	void invokeAll(std::vector<std::function<void(math::vector::Vec2<int>)>>, math::vector::Vec2<int>) const;

	std::unordered_map<SDL_Keycode, std::vector<std::function<void()>>> keyDownDispatch;
	std::unordered_map<SDL_Keycode, std::vector<std::function<void()>>> keyHeldDispatch;
	std::unordered_map<SDL_Keycode, std::vector<std::function<void()>>> keyUpDispatch;

	std::unordered_map<Uint8, std::vector<std::function<void(math::vector::Vec2<int>)>>> mouseDownDispatch;
	std::unordered_map<Uint8, std::vector<std::function<void(math::vector::Vec2<int>)>>> mouseHeldDispatch;
	std::unordered_map<Uint8, std::vector<std::function<void(math::vector::Vec2<int>)>>> mouseUpDispatch;
	std::vector<std::function<void(math::vector::Vec2<int>)>> mouseMoveDispatch;
};