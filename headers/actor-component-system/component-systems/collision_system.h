#pragma once
#include "component_system.h"
#include "collidable.h"
#include "transform_system.h"
#include "unordered_map"
#include "vec2.h"


class CollisionSystem : public ComponentSystem<Collidable>
{
public:
	CollisionSystem(TransformSystem&);
	~CollisionSystem();
	void update();


	//spelare ändrar ->
	//uppdaterar collision? ändra tillbaka
	//renderar
private:
	std::unordered_map<int, math::vector::Vec2> positionsLastFrame;
	CollisionID collisionMatrix[CollisionID::COUNT][CollisionID::COUNT];
	TransformSystem& transformSystem;
	bool isCollision(Component& a, Component& b);

};