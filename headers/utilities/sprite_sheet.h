#pragma once
#include <string>
#include "SDL.h"

class SpriteSheet {
public:
    SpriteSheet(SDL_Texture*, int);
    ~SpriteSheet();
    SDL_Rect get(int, int);
    SDL_Texture* getTexture() const;
private:
    const int spriteSize;
    SDL_Texture* texture;
    bool isPowerOf2(int);
};