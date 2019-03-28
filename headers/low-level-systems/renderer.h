#pragma once
#include "SDL.h"
#include <vector>
#include <unordered_map>
#include <string.h>
#include "vec2.h"
#include "render_job.h"
#include "sprite_sheet.h"

class Renderer
{
public:
	Renderer(SDL_Renderer*);
	~Renderer();    
	void drawFrame(std::vector<RenderJob> frame);
    int loadTexture(const std::string&);
private:
	SDL_Renderer* renderer;	
    int currentTextureHandle;
    std::unordered_map<int, SDL_Texture*> handle2Texture;
};