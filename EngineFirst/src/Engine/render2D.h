#pragma once

#include "SDL3/SDL.h"

class __declspec(dllexport) render2D
{
	int y = 0;
protected:

	SDL_Renderer* m_renderer;

	struct vec2D
	{
		float x;
		float y;
	};

public:
	render2D();
	~render2D();

	void createRenderer(SDL_Window* window, const char* name, int flags);

	void drawLine(vec2D p1, vec2D p2);
	

};

