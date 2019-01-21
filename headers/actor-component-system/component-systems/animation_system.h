#pragma once
#include "texture_renderer.h"
#include "transform_system.h"
#include "component_system.h"
#include "animation.h"

class AnimationSystem : public ComponentSystem<Animation>
{
public:
	AnimationSystem(TextureRenderer&, TransformSystem&);
	void submit(float dt);
private:
	TextureRenderer& textureRenderer;
	TransformSystem& transformSystem;
};