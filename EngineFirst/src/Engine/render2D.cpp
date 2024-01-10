#include "render2D.h"
#include <algorithm>

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
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
	SDL_RenderLine(m_renderer, p1.x, p1.y, p2.x, p2.y);
	//SDL_RenderPresent(m_renderer);
}

void render2D::drawLines(std::vector<vec2DLine*> lines)
{
	/*SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);*/
	for (auto& l : lines)
	{
		SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
		SDL_RenderLine(m_renderer, l->x1, l->y1, l->x2, l->y2);
	}
	//SDL_RenderPresent(m_renderer);
}

void render2D::drawRectangles(std::vector<SDL_FRect*> entity, bool fill)
{
	
	//SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	//SDL_RenderClear(m_renderer);
	for (auto& e : entity)
	{
		SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
		SDL_RenderFillRect(m_renderer, e);
	}
	//SDL_RenderPresent(m_renderer);
}

void render2D::drawPoint(vec2D p1)
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
	SDL_RenderPoint(m_renderer, p1.x, p1.y);
	//SDL_RenderPresent(m_renderer);
}

void render2D::swapFrames()
{
	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);
}