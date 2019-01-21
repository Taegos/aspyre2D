#include "actor.h"

int Actor::currentId = 0;

Actor::Actor() : id { ++Actor::currentId } 
{
    
}

int Actor::getId() const 
{ 
    return id;
}