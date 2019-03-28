#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "sprite_sheet.h"
#include "geometry.h"
#include "vec2.h"
#include <iostream>

using namespace std;
using namespace math::geometry;
using namespace math::vector;

TEST_CASE( "Test get." ) {
    SpriteSheet sheet {0, {256, 256},  32};
    Rect<int> rect0 = sheet.getSpriteRect({0, 0});
    Rect<int> rect1 = sheet.getSpriteRect({4, 4});
    Rect<int> rect2 = sheet.getSpriteRect({8, 8});

    Rect<int> expected0 {{0,0}, {32,32}};
    Rect<int> expected1 {{128,128},{32,32}};
    Rect<int> expected2 {{256,256},{32,32}};

    REQUIRE(rect0 == expected0);
    REQUIRE(rect1 == expected1);
    REQUIRE(rect2 == expected2);
}

TEST_CASE( "Test get out of bounds." ) {
    SpriteSheet sheet {0, {256, 256}, 32};
    REQUIRE_THROWS_AS(sheet.getSpriteRect({-1, 0}), std::runtime_error);
    REQUIRE_THROWS_AS(sheet.getSpriteRect({9,9}), std::runtime_error);
}

TEST_CASE( "Test create invalid sprite sheet size." ) {
    REQUIRE_THROWS_AS(SpriteSheet(0, {256, 257}, 32), std::runtime_error);
}

TEST_CASE( "Test create invalid sprite size." ) {
    REQUIRE_THROWS_AS(SpriteSheet(0, {256, 256}, 31), std::runtime_error);
}