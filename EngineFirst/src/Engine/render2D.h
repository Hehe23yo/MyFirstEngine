#pragma once

#include "SDL3/SDL.h"
#include <iostream>
#include <vector>
#include <algorithm>
class __declspec(dllexport) render2D
{
protected:

	SDL_Renderer* m_renderer;

	struct rgba
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 a;
	};

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

	struct circle
	{
		std::vector<vec2DLine*> lines;
		int noTriangles;
		vec2D centre;
		float radius;
	};
	
	SDL_FRect entities[2];
	int i = 0;

public:
	render2D();
	~render2D();

	void createRenderer(SDL_Window* window, const char* name, int flags);
	
	void drawLine(vec2D p1, vec2D p2, rgba colour);
	void drawLines(std::vector<vec2DLine*> lines, rgba colour);
	void drawRectangles(std::vector<SDL_FRect*> entity, bool fill, rgba colour);
	void drawTriangle(vec2D p1, vec2D p2, vec2D p3, rgba colour, bool fill);
	void drawPoint(vec2D p1, rgba colour);

	void swapFrames();
};

