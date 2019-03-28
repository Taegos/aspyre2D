#include "scene.h"
#include <iostream>
#include "SDL_image.h"
#include "engine.h"

using namespace std;

// Scene::Scene(SDL_Renderer* _renderer, SDL_Window* _window, int targetFps) :
// 	renderer { _renderer },
// 	window { _window },
// 	textureRenderer { renderer },
// 	spriteSystem { textureRenderer, transformSystem },
// 	animationSystem { textureRenderer, transformSystem },
// 	collisionSystem { transformSystem },
// 	//physicsSystem { transformSystem },
// 	targetFrameTime { 1000.0f / targetFps }
// {

// }

void Scene::load(Engine* engine) {
    this->engine = engine;
    //SDL_Renderer* _renderer, SDL_Window* _window, int targetFps
    //
}

void Scene::draw()
{
	spriteSystem.submit();
	animationSystem.submit(dt);
	textureRenderer.drawAll();
	// debugger.drawAll();
	SDL_RenderPresent(renderer);
}

void Scene::update()
{
	//physicsSystem.update(dt);
//	collisionSystem.update();
}

void Scene::run() {
	InputState state = inputPoller.poll();
	while (!state.quitEventSet) {

		int frameStart = SDL_GetTicks();
		inputEmitter.emit(state);

		update();
		draw();

		int frameEnd = SDL_GetTicks();
		int frameTime = frameEnd - frameStart;

		while ( frameTime < targetFrameTime) {
			frameTime += SDL_GetTicks() - frameEnd;
		}

		dt = frameTime / 1000.0f;
		state = inputPoller.poll();
	}
}

void Scene::destroy(int id) {
	actorSystem.remove(id);
	physicsSystem.remove(id);
	collisionSystem.remove(id);
	spriteSystem.remove(id);
	animationSystem.remove(id);
	transformSystem.remove(id);
}

void Scene::addActors(Actor* actors...) {
	for (Actor* actor : {actors}) {
		actorSystem.add(actor);	
	}
}

InputEmitter & Scene::getInputEmitter()
{
	return inputEmitter;
}

TransformSystem & Scene::getTransformSystem()
{
	return transformSystem;
}

SpriteSystem & Scene::getSpriteSystem()
{
	return spriteSystem;
}

AnimationSystem & Scene::getAnimationSystem() 
{
	return animationSystem;
}

CollisionSystem & Scene::getCollisionSystem()
{
	return collisionSystem;
}

PhysicsSystem & Scene::getPhysicsSystem()
{
	return physicsSystem;
}

// SpriteSheet Scene::loadSpriteSheet(string path, int spriteSize) {
// 	SDL_Texture* texture = loadTexture(path);
// 	return SpriteSheet { texture, spriteSize };
// }