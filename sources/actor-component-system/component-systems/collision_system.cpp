#include "collision_system.h"

CollisionSystem::CollisionSystem(TransformSystem& transformSystem) : transformSystem { transformSystem } {
}

CollisionSystem::~CollisionSystem()
{
}