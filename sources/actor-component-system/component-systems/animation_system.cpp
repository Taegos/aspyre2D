#include "animation_system.h"
#include "SDL.h"
#include <iostream>
#include "vec2.h"

using namespace math::vector;

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


		Transform *transform = transformSystem.get(component.id);
		SDL_Rect dst = { 
			transform->position.x,
			transform->position.y,
			anim.size * transform->scale,
			anim.size * transform->scale,
		};
	
		Vec2<int> pos = anim.frames[anim.currentFrame];
		textureRenderer.submit({
			anim.spriteSheet.getTexture(),
			anim.layer,
			anim.spriteSheet.get(pos.x, pos.y),
			dst
		});
	}
}