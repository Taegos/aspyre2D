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
		Animation& animation = component.data;
		animation.timeLeft -= dt;
		if (animation.timeLeft <= 0) {
			animation.currentFrame = (animation.currentFrame + 1) % animation.frames.size();
			animation.timeLeft = animation.frameTime;
		}
		Transform *transform = transformSystem.get(component.id);
		Vec2<int> position = animation.frames[animation.currentFrame];
		textureRenderer.submit({
			animation.layer,
			animation.sheet,
			position,
			transform->position,
			transform->scale,
			transform->rotation			
		});
	}
}