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
		RenderJob job = frame.back();
        SDL_Texture *texture = handle2Texture[job.textureHandle];
        SDL_Rect sourceRect = {
            job.sourceRect.topLeft.x,
            job.sourceRect.topLeft.y,
            job.sourceRect.width,
            job.sourceRect.height
        };
        SDL_Rect destRect = {
            job.destRect.topLeft.x,
            job.destRect.topLeft.y,
            job.destRect.width,
            job.destRect.height
        };
		// SpriteSheet& sheet = spriteSheets[job.sheet];
		// SDL_Rect src = sheet.get(job.sheetPos.x, job.sheetPos.y);	
		// float dstWidth = src.w * next.scale;
		// float dstHeight = src.h * next.scale;
		// SDL_Rect dst = { 
		// 	next.destPos.x - dstWidth / 2 ,
		// 	next.destPos.y - dstHeight / 2,
		// 	dstWidth,
		// 	dstHeight,
		// };	
        SDL_RenderCopy(renderer, texture, &sourceRect, &destRect);
		//SDL_RenderCopyEx(renderer, sheet->getTexture(), &src, &dst, next.rotation, NULL, SDL_FLIP_NONE);
		frame.pop_back();
	}
}

int Renderer::loadTexture(const string& path) {
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(path.c_str());
    if( surface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if( texture == NULL )
	{
		printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	SDL_FreeSurface(surface);
    currentTextureHandle++;
    handle2Texture[currentTextureHandle] = texture;
    return currentTextureHandle;    
}