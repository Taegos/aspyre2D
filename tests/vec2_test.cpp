#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "vec2.h"
#include <sstream>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;
using namespace math::vector;

TEST_CASE( "Addition" ) {
    Vec2 a {-2, 2};
    Vec2 b {4, 2};
    Vec2 c {2, 4};
    REQUIRE( a + b == c);
}

TEST_CASE( "Subtraction" ) {
    Vec2 a = {-2, 2};
    Vec2 b = {-2, 2};
    Vec2 c = {0, 0};
    REQUIRE( a - b == c);
}

TEST_CASE( "Multiplication" ) {
    Vec2 a = {-2, 2};
    Vec2 b = {-2, 2};
    Vec2 c = {4, 4};
    REQUIRE( a * b == c);
}

TEST_CASE( "Division" ) {
    Vec2 a = {-2, 2};
    Vec2 b = {-2, 2};
    Vec2 c = {1, 1};
    REQUIRE( a / b == c);
}

TEST_CASE( "Scale up" ) {
    Vec2 a = {-2, 2};
    Vec2 b = {-8, 8};
    a *= 4;
    REQUIRE( a == b);
}

TEST_CASE( "Scale down" ) {
    Vec2 a = {-2, 2};
    Vec2 b = {-.5f, .5f};
    a /= 4;
    REQUIRE( a == b);
}

TEST_CASE( "Output" ) {
    Vec2 a = {-2, 2};
    stringstream buffer;
    buffer << a;
    REQUIRE( buffer.str() == "(-2, 2)");
}

TEST_CASE( "Normalized" ) {
    Vec2 vec {3, 3};
    Vec2 res = vec.normalized();
    Vec2 expected{1 / sqrt(2), 1 / sqrt(2)}; 
    REQUIRE(res == expected);
}

TEST_CASE( "Equality" ) {
    Vec2 vec1 {0, 0};
    Vec2 vec2 {2,-2};
    // Vec2 res = vec.normalized();
    // Vec2 expected{1 / sqrt(2), 1 / sqrt(2)}; 
    REQUIRE(vec1 != vec2);
}

//https://www.wolframalpha.com/input/?i=distance+between+(30,+17),(+-5,-1)
TEST_CASE( "Distance" ) {
    Vec2 a = {30, 17};
    Vec2 b = {-5, -1};
    REQUIRE(abs(a.distance(b) - sqrt(1549)) <= 0.015f) ;
}