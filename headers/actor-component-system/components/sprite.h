#include "SDL.h"
#include "vec2.h"
#include "sprite_sheet.h"

struct Sprite {
    SpriteSheet* sheet;
    int layer;
    math::vector::Vec2<int> position;
};