#include "sprite_system.h"
#include "SDL.h"
#include "vec2.h"
using namespace math::vector;

SpriteSystem::SpriteSystem(TextureRenderer& _textureRenderer, TransformSystem& _transformSystem) : 
	textureRenderer {_textureRenderer}, 
	transformSystem {_transformSystem} {
}

void SpriteSystem::submit()
{
	for (Component component : components) {		
		Sprite sprite = component.data;

		Transform *transform = transformSystem.get(component.id);

		SDL_Rect dst = { 
			transform->position.x,
			transform->position.y,
			sprite.size * transform->scale,
			sprite.size * transform->scale,
		};
		
		textureRenderer.submit({
			sprite.spriteSheet.getTexture(),
			sprite.layer,
			sprite.spriteSheet.get(sprite.position.x, sprite.position.y),
			dst
		});
	}
}