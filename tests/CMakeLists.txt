cmake_minimum_required(VERSION 3.6.2)
#ctest --output-on-failure

enable_testing()

#VEC2 TEST
add_executable(
    Vec2Test 
    vec2_test.cpp 
    ${MATH_DIR_CXX}/vec2.cpp
)
target_include_directories(
    Vec2Test
    PUBLIC 
    ${MATH_DIR_H}
)
add_test(Vec2Test Vec2Test)

#COMPONENT SYSTEM TEST
add_executable(
    ComponentSystemTest 
    component_system_test.cpp
)
target_include_directories(
    ComponentSystemTest 
    PUBLIC 
    ${COMPONENT_SYSTEMS_BASE_DIR_H}
)
add_test(ComponentSystemTest ComponentSystemTest)

#ACTOR SYSTEM TEST
add_executable(
    ActorSystemTest 
    actor_system_test.cpp 
    ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/actor_system.cpp 
    ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/actor.cpp
)
target_include_directories(
    ActorSystemTest 
    PUBLIC 
    ${ACTOR_COMPONENT_SYSTEM_DIR_H}
)
add_test(ActorSystemTest ActorSystemTest)

#COLLISION SYSTEM TEST
add_executable(
    CollisionSystemTest 
    collision_system_test.cpp 
    ${COMPONENT_SYSTEMS_DIR_CXX}/collision_system.cpp 
    ${COMPONENT_SYSTEMS_DIR_CXX}/transform_system.cpp 
)
target_include_directories(
    CollisionSystemTest 
    PUBLIC 
    ${COMPONENT_SYSTEMS_DIR_H}
)
add_test(CollisionSystemTest CollisionSystemTest)

#PATH GRAPH TEST
add_executable(
    PathGraphTest
    path_graph_test.cpp 
    ${GEOMETRY_DIR_CXX}/path_graph.cpp 
)
target_include_directories(
    PathGraphTest 
    PUBLIC 
    ${GEOMETRY_DIR_H}
    ${MATH_DIR_H}
)
add_test(PathGraphTest PathGraphTest)

#SPRITE SHEET TEST
add_executable(
    SpriteSheetTest 
    sprite_sheet_test.cpp 
    ${UTILITIES_DIR_CXX}/sprite_sheet.cpp
)
#target_link_directories(SpriteSheetTest PUBLIC ${LIBS})
# target_link_libraries(SpriteSheetTest SDL2 SDL2main SDL2_image)
target_include_directories(
    SpriteSheetTest 
    PUBLIC 
    ${UTILITIES_DIR_H} 
    ${MATH_DIR_H}
)
add_test(SpriteSheetTest SpriteSheetTest)