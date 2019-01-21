#include "debugger.h"
#include <iostream>
using namespace std;

// void Debugger::drawPolygon(std::vector<b2Vec2> polygon)
// {
// 	for (int i = 0; i < polygon.size() - 1; i++) {
// 		SDL_RenderDrawLine(renderer, polygon[i].x, polygon[i].y, polygon[i + 1].x, polygon[i + 1].y);
// 	}
// }

// Debugger::Debugger(SDL_Renderer *renderer)
// {
// 	this->renderer = renderer;
// }

// Debugger::~Debugger()
// {
// }

// void Debugger::drawAll()
// {
// 	while (debugJobs.size() > 0) {
// 		DebugJob next = debugJobs.back();	
// 		SDL_SetRenderDrawColor(renderer, next.color.r, next.color.g, next.color.b, next.color.a);
// 		drawPolygon(next.polygon);
// 		debugJobs.pop_back();
// 	}
// }

// void Debugger::submitJob(DebugJob debugJob)
// {
// 	debugJobs.push_back(debugJob);
// }