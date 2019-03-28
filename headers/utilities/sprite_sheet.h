#pragma once
#include <string>
#include <vec2.h>
#include <geometry.h>

class SpriteSheet {
public:
    SpriteSheet(int, math::vector::Vec2<int>, int);
    math::geometry::Rect<int> getSpriteRect(math::vector::Vec2<int>);
    int getTextureHandle() const;
private:
    const int spriteSize;
    const math::vector::Vec2<int> sheetSize;
    const int textureHandle;
    bool isPowerOf2(int);
};