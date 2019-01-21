#include "animation_system.h"
#include "SDL.h"
#include <iostream>

AnimationSystem::AnimationSystem(TextureRenderer& _textureRenderer, TransformSystem& _transformSystem) : 
	textureRenderer {_textureRenderer}, 
	transformSystem {_transformSystem} {
}
void AnimationSystem::submit(float dt)
{
	for (Component& component : components) {
		Animation& anim = component.data;
		anim.timeLeft -= dt;
		if (anim.timeLeft <= 0) {
			anim.currentFrame = (anim.currentFrame + 1) % anim.frames.size();
			anim.timeLeft = anim.frameTime;
		}
	 			
		SDL_Rect src = { 
			anim.size * anim.frames[anim.currentFrame].x,
			anim.size * anim.frames[anim.currentFrame].y,
			anim.size,
			anim.size,
		};
	
		Transform *transform = transformSystem.get(component.id);
		SDL_Rect dst = { 
			transform->position.x,
			transform->position.y,
			anim.size * transform->scale,
			anim.size * transform->scale,
		};
	
		textureRenderer.submit({
			anim.spriteSheet,
			anim.layer,
			src,
			dst
		});
	}
}