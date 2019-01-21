#pragma once
#include "component_system.h"
#include "collidable.h"
#include "transform_system.h"

class CollisionSystem : public ComponentSystem<Collidable>
{
public:
	CollisionSystem(TransformSystem&);
	~CollisionSystem();
private:
	TransformSystem& transformSystem;
};