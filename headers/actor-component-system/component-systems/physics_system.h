#pragma once
#include "component_system.h"
#include "body.h"
#include "transform_system.h"

class PhysicsSystem : public ComponentSystem<Body>
{
public:
	//PhysicsSystem(&TransformSystem);
	void update(float);
private:
	//TransformSystem& transformSystem;
};