#include <vector>
#include "sprite_sheet.h"
#include "vec2.h"
#include "geometry.h"

using namespace math::geometry;

struct RenderJob {
	int layer;
	int textureHandle;
    Rect<int> sourceRect;
    Rect<int> destRect;
    // sheet;
	// math::vector::Vec2<int> sheetPos;
	// math::vector::Vec2<float> destPos;
	// float scale;
	// double rotation;
};