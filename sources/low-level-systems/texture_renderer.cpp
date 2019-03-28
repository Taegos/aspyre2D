#include "renderer.h"
#include "SDL_image.h"
#include <algorithm>

using namespace std;

Renderer::Renderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void Renderer::drawFrame(vector<RenderJob> frame)
{	
	SDL_SetRenderDrawColor(renderer, 18, 21, 30, 0);
	SDL_RenderClear(renderer);
	sort(frame.begin(), frame.end(), [](const RenderJob& job0, const RenderJob& job1) -> bool
	{
		return job1.layer < job0.layer;
	});
	while (frame.size() > 0) {
		RenderJob job = jobs.back();
		SpriteSheet& sheet = spriteSheets[job.]
		SpriteSheet* sheet = next.sheet;
		SDL_Rect src = sheet->get(next.sheetPos.x, next.sheetPos.y);	
		float dstWidth = src.w * next.scale;
		float dstHeight = src.h * next.scale;
		SDL_Rect dst = { 
			next.destPos.x - dstWidth / 2 ,
			next.destPos.y - dstHeight / 2,
			dstWidth,
			dstHeight,
		};	
		SDL_RenderCopyEx(renderer, sheet->getTexture(), &src, &dst, next.rotation, NULL, SDL_FLIP_NONE);
		jobs.pop_back();
	}

	//int SDL_RenderCopyEx(SDL_Renderer*          renderer,
	//	SDL_Texture*           texture,
	//	const SDL_Rect*        srcrect,
	//	const SDL_Rect*        dstrect,
	//	const double           angle,
	//	const SDL_Point*       center,
	//	const SDL_RendererFlip flip)
}