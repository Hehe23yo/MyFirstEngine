#include "render2D.h"

render2D::render2D()
{
	m_renderer = NULL;
}

render2D::~render2D()
{
	SDL_DestroyRenderer(m_renderer);
}

void render2D::createRenderer(SDL_Window* window, const char* name, int flags)
{
	m_renderer = SDL_CreateRenderer(window, NULL, flags);
}

void render2D::drawLine()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderLine(m_renderer, 0.0f, 0.0f, 800.0f, 600.0f);
	SDL_RenderLine(m_renderer, 800.0f, 0.0f, 0.0f, 600.0f);
	SDL_RenderPresent(m_renderer);
}

