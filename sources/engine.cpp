#include "engine.h"
#include <iostream>
#include "SDL_image.h"

using namespace std;

Engine::Engine(SDL_Renderer* _renderer, SDL_Window* _window, int targetFps) :
	renderer { _renderer },
	window { _window },
	textureRenderer { renderer },
	spriteSystem { textureRenderer, transformSystem },
	animationSystem { textureRenderer, transformSystem },
	collisionSystem { transformSystem },
	//physicsSystem { transformSystem },
	targetFrameTime { 1000.0f / targetFps }
{

}

Engine::~Engine()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Engine Engine::setup(const std::string &title, int targetFps)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ||
		SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI, &window, &renderer) != 0) 
	//	SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI, &window, &renderer) != 0) 
	{
		throw runtime_error(string(SDL_GetError()));
	}
	SDL_SetWindowTitle(window, title.c_str());
	return Engine(renderer, window, targetFps);
}

void Engine::draw()
{
	spriteSystem.submit();
	animationSystem.submit(dt);
	textureRenderer.drawAll();
	// debugger.drawAll();
	SDL_RenderPresent(renderer);
}

void Engine::update()
{
	//physicsSystem.update(dt);
//	collisionSystem.update();
}

void Engine::run() {
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

void Engine::destroy(int id) {
	actorSystem.remove(id);
	physicsSystem.remove(id);
	collisionSystem.remove(id);
	spriteSystem.remove(id);
	animationSystem.remove(id);
	transformSystem.remove(id);
}

void Engine::addActors(Actor* actors...) {
	for (Actor* actor : {actors}) {
		actorSystem.add(actor);	
	}
}

InputEmitter & Engine::getInputEmitter()
{
	return inputEmitter;
}

TransformSystem & Engine::getTransformSystem()
{
	return transformSystem;
}

SpriteSystem & Engine::getSpriteSystem()
{
	return spriteSystem;
}

AnimationSystem & Engine::getAnimationSystem() 
{
	return animationSystem;
}

CollisionSystem & Engine::getCollisionSystem()
{
	return collisionSystem;
}

PhysicsSystem & Engine::getPhysicsSystem()
{
	return physicsSystem;
}

SpriteSheet Engine::loadSpriteSheet(string path, int spriteSize) {
	SDL_Texture* texture = loadTexture(path);
	return SpriteSheet { texture, spriteSize };
}

SDL_Texture* Engine::loadTexture( string path )
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(path.c_str());
    if( surface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if( texture == NULL )
	{
		printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	SDL_FreeSurface(surface);
    return texture;
}