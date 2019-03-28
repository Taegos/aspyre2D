#include "collision_system.h"
using namespace math::vector;
using namespace math::geometry;

CollisionSystem::CollisionSystem(TransformSystem& transformSystem) : transformSystem { transformSystem } {
}

void CollisionSystem::update() {
    for (Component componentA : components) {
        for (Component componentB : components) {
            if (componentA.id != componentB.id) {
                if (!collisionMatrix[componentA.id][componentB.id]) {
                    continue;
                }
                Transform* transformA = transformSystem.get(componentA.id);
                Transform* transformB = transformSystem.get(componentB.id);
                Shape* adjustedA = componentA.data.shape.adjusted(transformA->position, transformA->rotation, transformA->scale);
                Shape* adjustedB = componentA.data.shape.adjusted(transformA->position, transformA->rotation, transformA->scale);
                IntersectionData* intersectionData = adjustedA->getIntersection(adjustedB);
                if (intersectionData != nullptr) {
                    Vec2 positionLastFrameA = positionsLastFrame[componentA.id];
                    Vec2 positionLastFrameB = positionsLastFrame[componentB.id];
                    transformSystem.get(componentA.id)->position = positionLastFrameA;
                    transformSystem.get(componentB.id)->position = positionLastFrameB;
                    componentA.data.onCollision(componentB.id, intersectionData);
                    componentB.data.onCollision(componentA.id, intersectionData);
                }
            }
        }
    }
    for (Component component : components) {
        Vec2 position = transformSystem.get(component.id)->position;
        positionsLastFrame[component.id] = position;
    }
}