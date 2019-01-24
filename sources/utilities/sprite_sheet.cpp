#include "sprite_sheet.h"
using namespace std;

SpriteSheet::SpriteSheet(SDL_Texture* _texture, int _spriteSize) : spriteSize { _spriteSize }, texture { _texture } {
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    if (!isPowerOf2(w*h) || !isPowerOf2(spriteSize)) {
        throw runtime_error("Texture and spriteSize has to be a power of 2.");
    }    
}

SpriteSheet::~SpriteSheet() {
    SDL_DestroyTexture(texture);
}

//https://stackoverflow.com/questions/600293/how-to-check-if-a-number-is-a-power-of-2
bool SpriteSheet::isPowerOf2(int value) {
    return (value != 0) && ((value & (value - 1)) == 0);
}

SDL_Rect SpriteSheet::get(int x, int y) {
    x *= spriteSize;
    y *= spriteSize;
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    if (x < 0 || x > w || y < 0 || y > h) {
        throw runtime_error("Position is outside the texture bounds.");
    }
    return { x, y, spriteSize, spriteSize};
}

SDL_Texture* SpriteSheet::getTexture() const {
    return texture;
}