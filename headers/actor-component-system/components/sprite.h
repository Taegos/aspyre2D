#include "SDL.h"
#include "vec2.h"

struct Sprite {
    SDL_Texture* spriteSheet;
    int size;
    int layer;
    math::vector::Vec2<int> position;
};