#pragma once
#include "transform_system.h"
#include "texture_renderer.h"
#include "component_system.h"
#include "sprite.h"

class SpriteSystem : public ComponentSystem<Sprite>
{
public:
	SpriteSystem(TextureRenderer&, TransformSystem&);
	//bool remove(int id);
	void submit();
private:
	TextureRenderer& textureRenderer;
	TransformSystem& transformSystem;
};