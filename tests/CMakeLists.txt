cmake_minimum_required(VERSION 3.6.2)
#ctest --output-on-failure

enable_testing()

add_executable(Vec2Test vec2_test.cpp ${MATH_DIR_CXX}/vec2.cpp)
target_include_directories(Vec2Test PUBLIC ${MATH_DIR_H})
add_test(Vec2Test Vec2Test)

add_executable(ComponentSystemTest component_system_test.cpp)
target_include_directories(ComponentSystemTest PUBLIC ${COMPONENT_SYSTEMS_BASE_DIR_H})
add_test(ComponentSystemTest ComponentSystemTest)

add_executable(ActorSystemTest actor_system_test.cpp ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/actor_system.cpp ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/actor.cpp)
target_include_directories(ActorSystemTest PUBLIC ${ACTOR_COMPONENT_SYSTEM_DIR_H})
add_test(ActorSystemTest ActorSystemTest)

add_executable(CollisionSystemTest collision_system_test.cpp ${COMPONENT_SYSTEMS_DIR_CXX}/collision_system.cpp)
target_include_directories(CollisionSystemTest PUBLIC ${COMPONENT_SYSTEMS_DIR_H})
add_test(CollisionSystemTest CollisionSystemTest)