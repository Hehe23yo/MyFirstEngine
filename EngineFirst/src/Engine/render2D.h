#pragma once

#include "SDL3/SDL.h"
#include <iostream>
#include <vector>
#include <algorithm>
class __declspec(dllexport) render2D
{
protected:

	SDL_Renderer* m_renderer;

	struct vec2D
	{
		float x;
		float y;
	};

	struct vec2DLine
	{
		float x1;
		float y1; 
		float x2;
		float y2;
	};
	//std::vector<SDL_FRect> entities;
	SDL_FRect entities[2];
	int i = 0;

	//std::vector<SDL_FRect> rects;
public:
	render2D();
	~render2D();

	void createRenderer(SDL_Window* window, const char* name, int flags);

	void drawLine(vec2D p1, vec2D p2);
	void drawLines(std::vector<vec2DLine*> lines);
	void drawRectangles(std::vector<SDL_FRect*> entity, bool fill);
	void drawPoint(vec2D p1);
	
	void swapFrames();
};

