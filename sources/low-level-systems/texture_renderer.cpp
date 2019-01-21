#include "texture_renderer.h"
#include "SDL_image.h"
#include <algorithm>

using namespace std;

TextureRenderer::TextureRenderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

TextureRenderer::~TextureRenderer()
{
	
}

void TextureRenderer::drawAll()
{	
	SDL_SetRenderDrawColor(renderer, 18, 21, 30, 0);
	SDL_RenderClear(renderer);
	sort(jobs.begin(), jobs.end(), [](const RenderJob& job0, const RenderJob& job1) -> bool
	{
		return job1.layer < job0.layer;
	});
	while (jobs.size() > 0) {
		RenderJob next = jobs.back();
		SDL_RenderCopy(renderer, next.texture, &next.src, &next.dst);
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

void TextureRenderer::submit(const RenderJob&& job) {
	jobs.push_back(job);
}