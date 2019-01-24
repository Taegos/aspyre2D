#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "sprite_sheet.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <iostream>
using namespace std;

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer)
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
    return texture;
}

void REQUIRE_RECTS(SDL_Rect a, SDL_Rect b) {
    // cout << a.x << " " << a.y << " " << a.w << " " << a.h << endl;
    // cout << b.x << " " << b.y << " " << b.w << " " << b.h << endl << endl;
    CHECK((a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h)); 
}

TEST_CASE( "Test get." ) {
    SDL_Renderer* renderer;
    SDL_Window* window;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ||
		SDL_CreateWindowAndRenderer(500,500, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0) 
	{
		throw runtime_error(string(SDL_GetError()));
	}

    SDL_Texture* texture = loadTexture("valid_texture_size.png", renderer);
    SpriteSheet sheet {texture, 32};
    SDL_Rect rect0 = sheet.get(0, 0);
    SDL_Rect rect1 = sheet.get(4, 4);
    SDL_Rect rect2 = sheet.get(8, 8);
    
    REQUIRE_RECTS(rect0, {0,0,32,32});
    REQUIRE_RECTS(rect1, {128,128,32,32});
    REQUIRE_RECTS(rect2, {256,256,32,32});

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

TEST_CASE( "Test get out of bounds." ) {
    SDL_Renderer* renderer;
    SDL_Window* window;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ||
		SDL_CreateWindowAndRenderer(500,500, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0) 
	{
		throw runtime_error(string(SDL_GetError()));
	}

    SDL_Texture* texture = loadTexture("valid_texture_size.png", renderer);
    SpriteSheet sheet {texture, 32};
    REQUIRE_THROWS_AS(sheet.get(-1, 0), std::runtime_error);
    REQUIRE_THROWS_AS(sheet.get(9,9), std::runtime_error);
  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

TEST_CASE( "Test create invalid texture size." ) {
    SDL_Renderer* renderer;
    SDL_Window* window;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ||
		SDL_CreateWindowAndRenderer(500,500, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0) 
	{
		throw runtime_error(string(SDL_GetError()));
	}

    SDL_Texture* texture = loadTexture("invalid_texture_size.png", renderer);
    REQUIRE_THROWS_AS(SpriteSheet(texture, 32), std::runtime_error);
  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

TEST_CASE( "Test create invalid sprite size." ) {
    SDL_Renderer* renderer;
    SDL_Window* window;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ||
		SDL_CreateWindowAndRenderer(500,500, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0) 
	{
		throw runtime_error(string(SDL_GetError()));
	}


    SDL_Texture* texture = loadTexture("valid_texture_size.png", renderer);
    REQUIRE_THROWS_AS(SpriteSheet(texture, 31), std::runtime_error);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}