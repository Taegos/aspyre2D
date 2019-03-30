#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "path_graph.h"
using namespace std;
using namespace math::geometry;
using namespace math::vector;

//https://www.wolframalpha.com/input/?i=plot++++++%7B0,0%7D,+++++++++%7B1.5,1%7D,+++++++++%7B1,-2%7D,+++++++++%7B0.5,1.5%7D,
TEST_CASE( "Test collision simple." ) {
    srand(time(NULL));
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {1.5,1},
    });
    PathGraph pathGraphB = PathGraph({
        {1,-2},
        {0.5,1.5},             
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B10,5%7D,+++++++++%7B5,-10%7D,
TEST_CASE( "Test not collision simple." ) {
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {2,2},
    });
    PathGraph pathGraphB = PathGraph({
        {10,5},
        {5,-10},             
    });
    IntersectionData data;
    REQUIRE(!pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 0);
}

TEST_CASE( "Test collision at points." ) {
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {2,2},
    });
    PathGraph pathGraphB = PathGraph({
        {3,0},
        {2,2},             
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
    REQUIRE(data.pointsOfIntersection[0] == Vec2{2,2});
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++%7B0,0%7D,+++++++++%7B3,0%7D,+++++++++%7B1,-2%7D,+++++++++%7B2,+1%7D,
TEST_CASE( "Test one horizontal." ) {
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {3,0},
    });
    PathGraph pathGraphB = PathGraph({
        {1,-2},
        {2, 1},             
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
}

//https://www.wolframalpha.com/input/?i=plot++++++++++++++++++++++++%7B1.5,-1.5%7D,+++++++++%7B1.5,+1.5%7D,++++++++++++%7B0,0%7D,+++++++++%7B2,+0.5%7D
TEST_CASE( "Test one vertical." ) {
    PathGraph pathGraphA = PathGraph({
        {1.5,-1.5},
        {1.5, 1.5},             
    });
    PathGraph pathGraphB = PathGraph({
        {0,0},
        {2, 0.5},             
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++%7B0,0%7D,+++++++++%7B3,0%7D,++++++++%7B1.5,-1.5%7D,+++++++++%7B1.5,+1.5%7D,
TEST_CASE( "Test horizontal and vertical." ) {
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {3,0},
    });
    PathGraph pathGraphB = PathGraph({
        {1.5,-1.5},
        {1.5, 1.5},             
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
    REQUIRE(data.pointsOfIntersection[0] == Vec2{1.5, 0});        
}

//https://www.wolframalpha.com/input/?i=plot+%7B0,0%7D,+++++++++%7B2,1%7D,+++++++++%7B1,1%7D,+++++++++%7B3,2%7D
TEST_CASE( "Test parallel, not overlapping." ) {
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {2,1},
    });
    PathGraph pathGraphB = PathGraph({
        {1,1},
        {3,2},
    });
    IntersectionData data;
    REQUIRE(!pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 0);    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++%7B0,+0%7D,+++++++++%7B0,+3%7D,+++++++++%7B5,+-5%7D,+++++++++%7B5,+5%7D,
TEST_CASE( "Test parallel, vertical and not overlapping." ) {
    PathGraph pathGraphA = PathGraph({
        {0, 0},
        {0, 3},
    });
    PathGraph pathGraphB = PathGraph({
        {5, -5},
        {5, 5},
    });
    IntersectionData data;
    REQUIRE(!pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 0);    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++%7B0,+0%7D,+++++++++%7B0,+3%7D,+++++++++%7B5,+-5%7D,+++++++++%7B5,+5%7D,
TEST_CASE( "Test parallel, same line and not overlapping." ) {
    PathGraph pathGraphA = PathGraph({
        {0, 0},
        {1, 2},
    });
    PathGraph pathGraphB = PathGraph({
        {2, 4},
        {3, 6},
    });
    IntersectionData data;
    REQUIRE(!pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 0);    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B30,+17%7D,+++++++++%7B-5,-1%7D,+++++++++%7B30,+17%7D,+++++++++%7B-5,-1%7D,
TEST_CASE( "Test overlap exact." ) {
    srand(-5123);
    Vec2 a = {30, 17};
    Vec2 b = {-5, -1};
    PathGraph pathGraphA = PathGraph({
        a,
        b
    });
    PathGraph pathGraphB = PathGraph({
        a,
        b
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
    float dAB = a.distance(b);
    float dAI = a.distance(data.pointsOfIntersection[0]);
    REQUIRE((0 <= dAI && dAI <= dAB));
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B0,0%7D,+++++++++%7B2,1%7D,+++++++++%7B1,0.5%7D,+++++++++%7B3,1.5%7D
TEST_CASE( "Test overlap A-C-B-D." ) {
    srand(105123);
    Vec2 a = {0, 0};
    Vec2 b = {1, 0.5};
    Vec2 c = {2, 1};
    Vec2 d = {3, 1.5};  
    PathGraph pathGraphA = PathGraph({
        a,
        c,
    });
    PathGraph pathGraphB = PathGraph({
        b,
        d,
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
    float dCB = c.distance(d);
    float dCI = c.distance(data.pointsOfIntersection[0]);
    REQUIRE((0 <= dCI && dCI <= dCB));
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B0,0%7D,+++++++%7B3,1.5%7D,++++%7B1,0.5%7D,++++++++++%7B2,1%7D
TEST_CASE( "Test overlap A-C-D-B." ) {
    srand(12312);
    Vec2 a = {0, 0};
    Vec2 c = {1, 0.5};  
    Vec2 d = {2, 1}; 
    Vec2 b = {3, 1.5};
    PathGraph pathGraphA = PathGraph({
        a,
        b,
    });
    PathGraph pathGraphB = PathGraph({
        c,
        d,
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);
    float dCD = c.distance(d);
    float dCI = c.distance(data.pointsOfIntersection[0]);
    REQUIRE((0 <= dCI && dCI <= dCD));
}

//https://www.wolframalpha.com/input/?i=plot%5B(2,4),(3.5,3),(5,0),(4,-2),(2,-1)(3,-2),(3,0)(4.5,3)(4.5,-2)%5D
TEST_CASE( "Test collision complex." ) {
    PathGraph pathGraphA = PathGraph({
        {2,4},
        {3.5,3},
        {5,0},        
        {4,-2},
        {2,-1},               
    });
    PathGraph pathGraphB = PathGraph({
        {3,-2},
        {3, 0},
        {4.5,3},
        {4.5,-2},        
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 4);
}

TEST_CASE( "Test not collision complex." ) {
    //https://www.wolframalpha.com/input/?i=plot%5B(1,1),(2,1),(2,4),(3.5,3),(5,0),(4,-2),(2,-1),(0,0)%5D
    PathGraph pathGraphA = PathGraph({
        {1,1},
        {2,1},
        {2,4},
        {3.5,3},
        {5,0},
        {4,-2},
        {2,-1},
        {0,0}        
    });
    //https://www.wolframalpha.com/input/?i=plot%5B(6,0),(5,3),(7,3),(9,2),(8,0)%5D
    PathGraph pathGraphB = PathGraph({
        {6,0},
        {5,3},
        {7,3},
        {9,2},
        {8,0}
    });
    IntersectionData data;
    REQUIRE(!pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 0);    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B4,-1%7D,+%7B0,0%7D,+++++++++%7B1,-3%7D,+++++++++%7B1.5,1%7D,
TEST_CASE( "Test collision occur because pathGraph closed." ) {
    vector<Vec2> points {};
    PathGraph pathGraphA = PathGraph({
        {0,0},
        {2,2},
        {4,-1},
        {0,0}
    });
    PathGraph pathGraphB = PathGraph({
        {1,-3},
        {1.5,1},             
    });
    IntersectionData data;
    REQUIRE(pathGraphA.isIntersecting(pathGraphB, data));    
    REQUIRE(data.pointsOfIntersection.size() == 1);    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B3,-1%7D,+++++++++%7B0,+1%7D
TEST_CASE( "Test throw on pathGraph edges self intersects." ) {
    REQUIRE_THROWS_AS(
        PathGraph({
            {0,0},
            {2,2},
            {3,-1},
            {0,1}
        }), 
        std::invalid_argument
    );
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B3,-1%7D,+++++++++%7B0,+1%7D
TEST_CASE( "Test throw on pathGraph only one point." ) {
    REQUIRE_THROWS_AS(
        PathGraph({
            {0,0}
        }), 
        std::invalid_argument
    );
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B3,-1%7D,+++++++++%7B0,+1%7D
TEST_CASE( "Test throw on pathGraph points self intersects." ) {
    REQUIRE_THROWS_AS(
        PathGraph({
            {0,0},
            {0,0},
        }), 
        std::invalid_argument
    );
}

//https://www.wolframalpha.com/input/?i=plot++++++++++++++++++++%7B0,0%7D,+++++++++++++%7B2,2%7D,+++++++++++++%7B2,-2%7D,+++++++++++++%7B3,+-1%7D,+%7B0,0%7D
TEST_CASE( "Test throw on pathGraph self intersection caused by closed." ) {
    REQUIRE_THROWS_AS(
        PathGraph({
            {0,0},
            {2,2},
            {2,-2},
            {3,-1},
            {0,0}
        }), 
        std::invalid_argument
    );
}