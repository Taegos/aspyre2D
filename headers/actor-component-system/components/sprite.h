#include "SDL.h"
#include "vec2.h"
#include "sprite_sheet.h"

struct Sprite {
    SpriteSheet* spriteSheet;
    int size;
    int layer;
    math::vector::Vec2<int> position;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};