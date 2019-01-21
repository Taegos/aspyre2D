#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "component_system.h"
#include <string>
using namespace std;

class DummySystem : public ComponentSystem<string> {};

TEST_CASE( "Test add / get." ) {
    DummySystem system;
    system.add(0, "a");
    system.add(1, "b");
    system.add(2, "c");
    REQUIRE( *system.get(0) == "a");
    REQUIRE( *system.get(1) == "b");
    REQUIRE( *system.get(2) == "c");
}

TEST_CASE( "Test remove." ) {
    DummySystem system;
    system.add(0, "a");
    system.add(1, "b");
    system.add(2, "c");
    REQUIRE( system.remove(1) == true);
    REQUIRE( system.get(1) == nullptr);
}
    
TEST_CASE( "Test get fail." ) {
    DummySystem system;
    system.add(0, "a");
    system.add(1, "b");
    system.add(2, "c");
    REQUIRE( system.get(3) == nullptr);
}

TEST_CASE( "Test remove fail." ) {
    DummySystem system;
    system.add(0, "a");
    system.add(1, "b");

    system.add(3, "d");
    system.add(4, "e");

    system.remove(0);
    bool success0 = system.remove(0);
    
    bool success1 = system.remove(2);

    system.remove(4);
    bool success2 = system.remove(4);

    bool success3 = system.remove(123);
    bool success4 = system.remove(-123);

    REQUIRE(!success0);
    REQUIRE(!success1);
    REQUIRE(!success2);
    REQUIRE(!success3);
    REQUIRE(!success4);
}

TEST_CASE( "Test modify." ) {
    DummySystem system;
    system.add(0, "a");
    system.add(1, "b");
    system.add(2, "c");
    *system.get(1) = "123";
    REQUIRE( *system.get(1) == "123");
}

TEST_CASE( "Test mixed." ) {
    DummySystem system;

    system.add(2, "a");
    system.add(1, "b");
    system.add(4, "c");
    system.add(10, "d");
    system.add(9, "e");
    
    bool rm0 = system.remove(9);
    system.add(3, "f");
    *system.get(4) = "abc";
    bool rm1 = system.remove(10);
    bool rm2 = system.remove(9);
    bool rm3 = system.remove(2);
    system.add(123, "abc");
    bool rm4 = system.remove(123);

    REQUIRE( rm0 );
    REQUIRE( rm1 );
    REQUIRE( !rm2 );
    REQUIRE( rm3 );
    REQUIRE( rm4 );

    REQUIRE( *system.get(1) == "b");  
    REQUIRE( *system.get(3) == "f");
    REQUIRE( *system.get(4) == "abc");

    REQUIRE( system.get(2) == nullptr);  
    REQUIRE( system.get(9) == nullptr);  
    REQUIRE( system.get(10) == nullptr);  
    REQUIRE( system.get(123) == nullptr);  
}