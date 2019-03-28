#include "sprite_sheet.h"
using namespace std;
using namespace math::geometry;
using namespace math::vector;

SpriteSheet::SpriteSheet(int _textureHandle, Vec2<int> _sheetSize, int _spriteSize) : 
    textureHandle { _textureHandle },
    sheetSize { _sheetSize },
    spriteSize { _spriteSize } {    
    if (!isPowerOf2(sheetSize.x*sheetSize.y) || !isPowerOf2(spriteSize)) {
        throw runtime_error("Texture and spriteSize has to be a power of 2.");
    }    
}

//https://stackoverflow.com/questions/600293/how-to-check-if-a-number-is-a-power-of-2
bool SpriteSheet::isPowerOf2(int value) {
    return (value != 0) && ((value & (value - 1)) == 0);
}

Rect<int> SpriteSheet::getSpriteRect(Vec2<int> sheetPosition) {
    sheetPosition *= spriteSize;
    if (sheetPosition.x < 0 || sheetPosition.x > sheetSize.x || sheetPosition.y < 0 || sheetPosition.y > sheetSize.y) {
        throw runtime_error("Position is outside the texture bounds.");
    }
    return { sheetPosition, { spriteSize, spriteSize} };
}

int SpriteSheet::getTextureHandle() const {
    return textureHandle;
}