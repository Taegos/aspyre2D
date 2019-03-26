#include <vector>
#include <vec2.h>
#include "sprite_sheet.h"

struct Animation {
    SpriteSheet* spriteSheet;
    int layer;
    int size;
    float frameTime;
    std::vector<math::vector::Vec2<int>> frames;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    int currentFrame = 0;
    float timeLeft = frameTime;
};

//https://gamedev.stackexchange.com/questions/70876/sdl2-sprite-batching-and-texture-atlases