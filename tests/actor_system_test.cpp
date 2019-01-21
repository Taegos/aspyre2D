#define CATCH_CONFIG_MAIN
#include "Catch2\catch.hpp"
#include <functional>
#include "actor.h"
#include "actor_system.h"
#include <iostream>
using namespace std;


class DummyActor : public Actor {
public:
    void update(float dt) override {}
};

class UpdatedActor : public Actor {
public:
    bool updated;
    void update(float dt) override {
        updated = true;
    }
};

class DestroyedActor : public Actor {
public:
    DestroyedActor(function<void()> onDestructorCalled) :
        onDestructorCalled { onDestructorCalled }
    {}
    ~DestroyedActor() {
        onDestructorCalled();
    }
    void update(float dt) override {}

private:
    function<void()> onDestructorCalled;
};

TEST_CASE( "Test update." ) {
    ActorSystem system {};
    UpdatedActor* updatedActor = new UpdatedActor();
    system.add(updatedActor);
    system.update(0.5f);
    REQUIRE ( updatedActor->updated );
}

TEST_CASE( "Test remove." ) {
    ActorSystem system {};
    
    bool destructorCalled;

    DummyActor* dummy0 = new DummyActor();
    DestroyedActor* destroyedActor = new DestroyedActor([&destructorCalled] { destructorCalled = true; });
    DummyActor* dummy1 = new DummyActor();

    system.add(dummy0);
    system.add(destroyedActor);
    system.add(dummy1);
    bool success = system.remove(destroyedActor->getId());
    REQUIRE(success);
    REQUIRE(destructorCalled);
}

TEST_CASE( "Test remove fail." ) {
    ActorSystem system {};
    DummyActor* dummy0 = new DummyActor();
    DummyActor* dummy1 = new DummyActor();
    DummyActor* dummy2 = new DummyActor();
    DummyActor* dummy3 = new DummyActor();
    DummyActor* dummy4 = new DummyActor();

    system.add(dummy0);
    system.add(dummy1);

    system.add(dummy3);
    system.add(dummy4);

    int i0 = dummy0->getId();
    system.remove(i0);
    bool success0 = system.remove(i0);
    
    bool success1 = system.remove(dummy2->getId());

    int i4 = dummy4->getId();
    system.remove(i4);
    bool success2 = system.remove(i4);

    bool success3 = system.remove(123);
    bool success4 = system.remove(-123);

    REQUIRE(!success0);
    REQUIRE(!success1);
    REQUIRE(!success2);
    REQUIRE(!success3);
    REQUIRE(!success4);
}