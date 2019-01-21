#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "vec2.h"
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
using namespace math::vector;

TEST_CASE( "Addition" ) {
    Vec2<float> a{-2, 2};
    Vec2<float> b{4, 2};
    Vec2<float> c = {2, 4};
    REQUIRE( a + b == c);
}

TEST_CASE( "Subtraction" ) {
    Vec2<float> a = {-2, 2};
    Vec2<float> b = {-2, 2};
    Vec2<float> c = {0, 0};
    REQUIRE( a - b == c);
}

TEST_CASE( "Multiplication" ) {
    Vec2<float> a = {-2, 2};
    Vec2<float> b = {-2, 2};
    Vec2<float> c = {4, 4};
    REQUIRE( a * b == c);
}

TEST_CASE( "Division" ) {
    Vec2<float> a = {-2, 2};
    Vec2<float> b = {-2, 2};
    Vec2<float> c = {1, 1};
    REQUIRE( a / b == c);
}

TEST_CASE( "Scale up" ) {
    Vec2<float> a = {-2, 2};
    Vec2<float> b = {-8, 8};
    a *= 4;
    REQUIRE( a == b);
}

TEST_CASE( "Scale down" ) {
    Vec2<float> a = {-2, 2};
    Vec2<float> b = {-.5f, .5f};
    a /= 4;
    REQUIRE( a == b);
}

TEST_CASE( "Output" ) {
    Vec2<float> a = {-2, 2};
    stringstream buffer;
    buffer << a;
    REQUIRE( buffer.str() == "(-2, 2)");
}

TEST_CASE( "Normalized" ) {
    Vec2<double> vec{3, 3};
    Vec2<double> res = vec.normalized();
    Vec2<double> expected{1 / sqrt(2), 1 / sqrt(2)}; 
    REQUIRE(res == expected);
}