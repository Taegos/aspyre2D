#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include "actor.h"

class ActorSystem {
public:
	ActorSystem();
	~ActorSystem();
	void update(float dt);
	void add(Actor* actor);
	bool remove(int);
	
private:
	std::vector<Actor*> actors;
	std::vector<Actor*>::iterator find_it(int id);
};