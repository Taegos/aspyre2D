#pragma once
#include "component_system.h"
#include "transform.h"

class TransformSystem : public ComponentSystem<Transform> {
public: 
    TransformSystem();
};