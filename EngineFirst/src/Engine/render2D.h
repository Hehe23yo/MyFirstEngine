#pragma once

#include "SDL3/SDL.h"

class __declspec(dllexport) render2D
{
public:
	render2D();
	~render2D();

	void createRenderer(SDL_Window* window, const char* name, int flags);

	void drawLine();

protected:
	SDL_Renderer* m_renderer;

};

