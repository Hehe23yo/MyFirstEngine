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

void render2D::drawLine(vec2D p1, vec2D p2)
{
	/*if(y % 10 == 0)
		SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
	else
		SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);*/
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
	SDL_RenderLine(m_renderer, p1.x, p1.y, p2.x, p2.y);
	SDL_RenderPresent(m_renderer);

	//y++;
}

