#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "polygon.h"
using namespace std;
using namespace math::geometry;
using namespace math::vector;
typedef math::geometry::Polygon GPolygon;

//https://www.wolframalpha.com/input/?i=plot++++++%7B0,0%7D,+++++++++%7B1.5,1%7D,+++++++++%7B1,-2%7D,+++++++++%7B0.5,1.5%7D,
TEST_CASE( "Test collision simple." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {1.5,1},
    });
    GPolygon polygonB = GPolygon({
        {1,-2},
        {0.5,1.5},             
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B10,5%7D,+++++++++%7B5,-10%7D,
TEST_CASE( "Test not collision simple." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {2,2},
    });
    GPolygon polygonB = GPolygon({
        {10,5},
        {5,-10},             
    });
    IntersectionData data;
    REQUIRE(!polygonA.getIntersection(polygonB, data));    
}

TEST_CASE( "Test collision at points." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {2,2},
    });
    GPolygon polygonB = GPolygon({
        {3,0},
        {2,2},             
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++%7B0,0%7D,+++++++++%7B3,0%7D,+++++++++%7B1,-2%7D,+++++++++%7B2,+1%7D,
TEST_CASE( "Test horizontal." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {3,0},
    });
    GPolygon polygonB = GPolygon({
        {1,-2},
        {2, 1},             
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot++++++++++++++++++++++++%7B1.5,-1.5%7D,+++++++++%7B1.5,+1.5%7D,++++++++++++%7B0,0%7D,+++++++++%7B2,+0.5%7D
TEST_CASE( "Test vertical." ) {
    GPolygon polygonA = GPolygon({
        {1.5,-1.5},
        {1.5, 1.5},             
    });
    GPolygon polygonB = GPolygon({
        {0,0},
        {2, 0.5},             
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++%7B0,0%7D,+++++++++%7B3,0%7D,++++++++%7B1.5,-1.5%7D,+++++++++%7B1.5,+1.5%7D,
TEST_CASE( "Test horizontal / vertical." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {3,0},
    });
    GPolygon polygonB = GPolygon({
        {1.5,-1.5},
        {1.5, 1.5},             
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B30,+17%7D,+++++++++%7B-5,-1%7D,+++++++++%7B30,+17%7D,+++++++++%7B-5,-1%7D,
TEST_CASE( "Test overlap exact." ) {
    GPolygon polygonA = GPolygon({
        {30, 17},
        {-5,-1},
    });
    GPolygon polygonB = GPolygon({
        {30, 17},
        {-5,-1},
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B0,0%7D,+++++++++%7B2,1%7D,+++++++++%7B1,0.5%7D,+++++++++%7B3,1.5%7D
TEST_CASE( "Test overlap offset." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {2,1},
    });
    GPolygon polygonB = GPolygon({
        {1,0.5},
        {3,1.5},
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+%7B0,0%7D,+++++++++%7B2,1%7D,+++++++++%7B1,1%7D,+++++++++%7B3,2%7D
TEST_CASE( "Test parallel." ) {
    GPolygon polygonA = GPolygon({
        {0,0},
        {2,1},
    });
    GPolygon polygonB = GPolygon({
        {1,1},
        {3,2},
    });
    IntersectionData data;
    REQUIRE(!polygonA.getIntersection(polygonB, data));    
}

TEST_CASE( "Test collision complex." ) {
    //https://www.wolframalpha.com/input/?i=plot+(0,0),+(1,1),+(2,1),+(1,-1),+(1,0),+(1.5,2)
    GPolygon polygonA = GPolygon({
        {1,1},
        {2,1},
        {2,4},
        {3.5,3},
        {5,0},
        {4,-2},
        {2,-1},
        {0,0}        
    });
    GPolygon polygonB = GPolygon({
        {2.5,-3},
        {3.5 ,-1},
        {4,-1},
        {5,-5},        
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

TEST_CASE( "Test not collision complex." ) {
    //https://www.wolframalpha.com/input/?i=plot+(0,0),+(1,1),+(2,1),+(1,-1),+(1,0),+(1.5,2)
    GPolygon polygonA = GPolygon({
        {1,1},
        {2,1},
        {2,4},
        {3.5,3},
        {5,0},
        {4,-2},
        {2,-1},
        {0,0}        
    });
    GPolygon polygonB = GPolygon({
        {6,0},
        {5,3},
        {7,3},
        {9,2},
        {8,0}
    });
    IntersectionData data;
    REQUIRE(!polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B4,-1%7D,+%7B0,0%7D,+++++++++%7B1,-3%7D,+++++++++%7B1.5,1%7D,
TEST_CASE( "Test collision occur because polygon closed." ) {
    vector<Vec2> points {};
    GPolygon polygonA = GPolygon({
        {0,0},
        {2,2},
        {4,-1}
    }, 
    true
    );
    GPolygon polygonB = GPolygon({
        {1,-3},
        {1.5,1},             
    });
    IntersectionData data;
    REQUIRE(polygonA.getIntersection(polygonB, data));    
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B3,-1%7D,+++++++++%7B0,+1%7D
TEST_CASE( "Test throw on polygon self intersection." ) {
    REQUIRE_THROWS_AS(
        GPolygon({
            {0,0},
            {2,2},
            {3,-1},
            {0, 1}
        }), 
        std::invalid_argument
    );
}

//https://www.wolframalpha.com/input/?i=plot++++++++++++++++++++%7B0,0%7D,+++++++++++++%7B2,2%7D,+++++++++++++%7B2,-2%7D,+++++++++++++%7B3,+-1%7D,+%7B0,0%7D
TEST_CASE( "Test throw on polygon self intersection caused by closed." ) {
    REQUIRE_THROWS_AS(
        GPolygon({
            {0,0},
            {2,2},
            {2,-2},
            {3, -1}
        }, 
        true
        ), 
        std::invalid_argument
    );
}