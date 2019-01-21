#pragma once
#include <string>
#include <vector>
#include "SDL.h"
#include "transform_system.h"
#include "sprite_system.h"
#include "animation_system.h"
#include "collision_system.h"
#include "physics_system.h"
#include "actor_system.h"
#include "input_emitter.h"
#include "input_poller.h"
#include "sprite_sheet.h"
class Engine 
{
public:
	~Engine();
	static Engine setup(const std::string&, int);
	void run();		
	
	void destroy(int);
	void addActors(Actor*...);
	
	TransformSystem & getTransformSystem();
	SpriteSystem & getSpriteSystem();
	AnimationSystem & getAnimationSystem();
	CollisionSystem & getCollisionSystem();
	PhysicsSystem & getPhysicsSystem();
	
	InputEmitter & getInputEmitter();
	SDL_Texture* loadTexture(std::string path);
	
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	ActorSystem actorSystem;
    TransformSystem transformSystem;
    SpriteSystem spriteSystem;
    AnimationSystem animationSystem;
    CollisionSystem collisionSystem;
    PhysicsSystem physicsSystem;    

	InputPoller inputPoller;
	InputEmitter inputEmitter;
	TextureRenderer textureRenderer;

	const float targetFrameTime;
	float dt = 0;
	void draw();
	void update();
	Engine(SDL_Renderer*, SDL_Window*, int);

};