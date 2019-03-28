#pragma once

#include "SDL.h"
#include <vector>
#include "sprite_sheet.h"
#include "vec2.h"


struct RenderJob {
	int layer;
	SpriteSheet* sheet;
	math::vector::Vec2<int> sheetPos;
	math::vector::Vec2<float> destPos;
	float scale;
	double rotation;

	// SDL_Texture* texture;
	// int layer;
	// SDL_Rect src;
	// SDL_Rect dst;
	// double rotation;
	// SDL_RendererFlip flip;
};

class TextureRenderer
{
private:
	SDL_Renderer* renderer;	
	std::vector<RenderJob> jobs;
public:
	TextureRenderer(SDL_Renderer*);
	~TextureRenderer();
	void drawAll();
	void submit(const RenderJob&& job);
};