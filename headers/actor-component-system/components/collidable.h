#include <functional>
#include "geometry.h"

enum CollisionID {
	PLAYER,
	WALL,
	COUNT
};

struct Collidable {
    math::geometry::Shape shape;
	std::function<void(int, math::geometry::IntersectionData)> onCollision;
    CollisionID id;
};