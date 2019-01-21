#include "sprite_system.h"
#include "SDL.h"

SpriteSystem::SpriteSystem(TextureRenderer& _textureRenderer, TransformSystem& _transformSystem) : 
	textureRenderer {_textureRenderer}, 
	transformSystem {_transformSystem} {
}

void SpriteSystem::submit()
{
	for (Component component : components) {		
		Sprite Sprite = component.data;
		Transform *transform = transformSystem.get(component.id);

		int w, h;
		SDL_QueryTexture(Sprite.texture, NULL, NULL, &w, &h);

		SDL_Rect dst = { 
			transform->position.x,
			transform->position.y,
			w * transform->scale,
			h * transform->scale,
		};

		textureRenderer.submit({
			Sprite.texture,
			Sprite.layer,
			NULL,
			dst
		});
	}
}