#include "actor_system.h"
using namespace std;
#include <iostream>

ActorSystem::ActorSystem()
{
}

ActorSystem::~ActorSystem()
{
	for (Actor* actor : actors) {
		delete(actor);
	}
}

void ActorSystem::update(float dt)
{
	for (Actor* actor : actors) {
		actor->update(dt);
	}
}

void ActorSystem::add(Actor * actor)
{
	auto it = find_it(actor->getId());
	actors.insert(it, actor);
}

bool ActorSystem::remove(int id) {
	auto it = find_it(id);
	if (it == actors.end() || (*it)->getId() != id) {
		return false;
	}
	Actor *actor = *it;
	actors.erase(it);
	delete(actor);
	return true; 
}

vector<Actor*>::iterator ActorSystem::find_it(int id)  {
	return lower_bound(
		actors.begin(), 
		actors.end(), 
		id,
		[](const Actor *actor, int id) -> bool {
			return actor->getId() < id;
		}
	);
}