#include "sprite_system.h"
#include "SDL.h"
#include "vec2.h"
using namespace math::vector;

SpriteSystem::SpriteSystem(TextureRenderer& _textureRenderer, TransformSystem& _transformSystem) : 
	textureRenderer {_textureRenderer}, 
	transformSystem {_transformSystem} {
}

// bool SpriteSystem::remove(int id) {
// 	return false;
// }

void SpriteSystem::submit()
{
	for (Component component : components) {		
		Sprite sprite = component.data;
		Transform *transform = transformSystem.get(component.id);
		
		// int spriteSize = sprite.spriteSheet->getSpriteSize();
		// SDL_Rect dst = { 
		// 	transform->position.x,
		// 	transform->position.y,
		// 	spriteSize * transform->scale,
		// 	sprite.size * transform->scale,
		// };		
		textureRenderer.submit({
			sprite.layer,
			sprite.sheet,
			sprite.position,
			transform->position,
			transform->scale,
			transform->rotation
			// sprite.spriteSheet->get(sprite.position.x, sprite.position.y),
			// dst,
			// transform->rotation,
			// sprite.flip
		});
	}
}