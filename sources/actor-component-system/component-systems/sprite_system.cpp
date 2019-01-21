#include "sprite_system.h"
#include "SDL.h"

SpriteSystem::SpriteSystem(TextureRenderer& _textureRenderer, TransformSystem& _transformSystem) : 
	textureRenderer {_textureRenderer}, 
	transformSystem {_transformSystem} {
}

void SpriteSystem::submit()
{
	for (Component component : components) {		
		Sprite sprite = component.data;

		SDL_Rect src = { 
			sprite.position.x,
			sprite.position.y,
			sprite.size,
			sprite.size,
		};

		Transform *transform = transformSystem.get(component.id);

		SDL_Rect dst = { 
			transform->position.x,
			transform->position.y,
			sprite.size * transform->scale,
			sprite.size * transform->scale,
		};

		textureRenderer.submit({
			sprite.spriteSheet,
			sprite.layer,
			src,
			dst
		});
	}
}