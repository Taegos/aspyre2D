#include <vector>
#include <vec2.h>

struct Animation {
    SDL_Texture* spriteSheet;
    int size;
    int layer;
    float frameTime;
    std::vector<math::vector::Vec2<int>> frames;
    int currentFrame = 0;
    float timeLeft = frameTime;
};