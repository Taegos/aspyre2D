#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include "engine.h"

TEST_CASE( "Test create" ) {
	Engine engine = Engine::setup("Aspyre2D", 60);
}

//