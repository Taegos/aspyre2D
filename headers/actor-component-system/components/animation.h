#include <vector>
#include <vec2.h>
#include "sprite_sheet.h"

struct Animation {
    SpriteSheet* sheet;
    int layer;
    float frameTime;
    std::vector<math::vector::Vec2<int>> frames;
    int currentFrame = 0;
    float timeLeft = frameTime;
};

//https://gamedev.stackexchange.com/questions/70876/sdl2-sprite-batching-and-texture-atlases