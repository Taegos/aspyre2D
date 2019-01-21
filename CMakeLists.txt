cmake_minimum_required(VERSION 3.6.2)
project(Aspyre2D VERSION 1.0.0)

#HEADER PATHS 
set(HEADERS_DIR ${CMAKE_SOURCE_DIR}/headers)
set(ACTOR_COMPONENT_SYSTEM_DIR_H ${HEADERS_DIR}/actor-component-system)
set(COMPONENT_SYSTEMS_DIR_H ${ACTOR_COMPONENT_SYSTEM_DIR_H}/component-systems)
set(COMPONENT_SYSTEMS_BASE_DIR_H ${COMPONENT_SYSTEMS_DIR_H}/base)
set(COMPONENTS_DIR_H ${ACTOR_COMPONENT_SYSTEM_DIR_H}/components)
set(LOW_LEVEL_SYSTEMS_DIR_H ${HEADERS_DIR}/low-level-systems)
set(UI_DIR_H ${HEADERS_DIR}/ui)
set(UTILITIES_DIR_H ${HEADERS_DIR}/utilities)
set(MATH_DIR_H ${UTILITIES_DIR_H}/math)

set(HEADERS 
    ${HEADERS_DIR} 
    ${ACTOR_COMPONENT_SYSTEM_DIR_H}
    ${COMPONENT_SYSTEMS_DIR_H}
    ${COMPONENT_SYSTEMS_BASE_DIR_H}
    ${COMPONENTS_DIR_H}
    ${LOW_LEVEL_SYSTEMS_DIR_H}
    ${UI_DIR_H}
    ${UTILITIES_DIR_H}
    ${MATH_DIR_H})

#SOURCES PATHS 
set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/sources)
set(ACTOR_COMPONENT_SYSTEM_DIR_CXX ${SOURCES_DIR}/actor-component-system)
set(COMPONENT_SYSTEMS_DIR_CXX ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/component-systems)
set(LOW_LEVEL_SYSTEMS_DIR_CXX ${SOURCES_DIR}/low-level-systems)
set(UI_DIR_CXX ${SOURCES_DIR}/ui)
set(UTILITIES_DIR_CXX ${SOURCES_DIR}/utilities)
set(MATH_DIR_CXX ${UTILITIES_DIR_CXX}/math)

#External includes
set(EXTERNAL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/include)
set(SDL2_INCLUDE_DIR ${EXTERNAL_INCLUDE_DIR}/SDL2)
set(SDL2_IMAGE_INCLUDE_DIR ${EXTERNAL_INCLUDE_DIR}/SDL2_Image)
set(EXTERNAL_INCLUDES ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

#External libraries
set(EXTERNAL_LIB_DIR ${CMAKE_SOURCE_DIR}/external/lib)
set(SDL2_LIB_DIR ${EXTERNAL_LIB_DIR}/SDL2)
set(SDL2_IMAGE_LIB_DIR ${EXTERNAL_LIB_DIR}/SDL2_Image)
set(LIBS ${SDL2_LIB_DIR} ${SDL2_IMAGE_LIB_DIR})

#Adding the tests
add_subdirectory(tests)
add_subdirectory(game)

#Putting everything together
link_directories(${LIBS})
add_executable(Aspyre2D)
target_link_libraries(Aspyre2D SDL2 SDL2main SDL2_image)
target_include_directories(Aspyre2D PUBLIC ${HEADERS} ${EXTERNAL_INCLUDES})
target_sources(Aspyre2D PUBLIC
    game/main.cpp
    ${SOURCES_DIR}/engine.cpp
    ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/actor_system.cpp
    ${ACTOR_COMPONENT_SYSTEM_DIR_CXX}/actor.cpp
    ${COMPONENT_SYSTEMS_DIR_CXX}/animation_system.cpp
    ${COMPONENT_SYSTEMS_DIR_CXX}/collision_system.cpp
    ${COMPONENT_SYSTEMS_DIR_CXX}/physics_system.cpp
    ${COMPONENT_SYSTEMS_DIR_CXX}/sprite_system.cpp
    ${COMPONENT_SYSTEMS_DIR_CXX}/transform_system.cpp
    ${LOW_LEVEL_SYSTEMS_DIR_CXX}/input_emitter.cpp
    ${LOW_LEVEL_SYSTEMS_DIR_CXX}/input_poller.cpp
    ${LOW_LEVEL_SYSTEMS_DIR_CXX}/texture_renderer.cpp
    ${UI_DIR_CXX}/ui.cpp
    ${UTILITIES_DIR_CXX}/debugger.cpp
        
    ${MATH_DIR_CXX}/vec2.cpp
)