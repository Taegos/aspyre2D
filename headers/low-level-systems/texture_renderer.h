#pragma once

#include "SDL.h"
#include <vector>

struct RenderJob {
	SDL_Texture* texture;
	int layer;
	SDL_Rect src;
	SDL_Rect dst;
	double rotation;
	SDL_RendererFlip flip;
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