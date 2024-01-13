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


/*
	THERE IS NO SDL_RenderPresent() FUNCTION CALL IN EVERY DRAW METHOD TO MAKE IT SO 
	THAT THE DIFFERENT ENTITIES WHEN DRAWN, ARE DRAWN ON THE SAME FRAME
*/

/*
	THERE IS NO SDL_RenderClear() FUNCTION CALL IN EVERY DRAW METHOD TO MAKE SURE THAT 
	ALREADY DRAWN ITEMS ON THE CURRENT FRAME BY OTHER DRAW CALLS ARE NOT ERASED AND 
	ALL DRAW CALLS IN A SINGLE ITERATION RESULT ON A COMMON / SAME FRAME 
*/


/**
* Draws a simple, single line of specified co-ordinates and of a specified colour
* - Takes beginning point and end point data 
* - Takes colour data of rgba type
*/
void render2D::drawLine(vec2D p1, vec2D p2, rgba colour)
{
	SDL_SetRenderDrawColor(m_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderLine(m_renderer, p1.x, p1.y, p2.x, p2.y);
}

/**
* Draws multiple lines of specified co-ordinates and a specified colour
* All lines drawn are of the same colour | Yet to implement unique colour for each separate line
* - Takes a vector of line data (start point x and y. end point x and y)
* - Takes colour data of rgba type
*/
void render2D::drawLines(std::vector<vec2DLine*> lines, rgba colour)
{
	for (auto& l : lines)
	{
		SDL_SetRenderDrawColor(m_renderer, colour.r, colour.g, colour.b, colour.a);
		SDL_RenderLine(m_renderer, l->x1, l->y1, l->x2, l->y2);
	}
}

/**
* Draws one or more rectangles at specified co-ordinates, option of filled or not filled, of a specified colour
* All rectangles are drawn of the same colour | Yet to implement unique colour for each separate line
* - Takes a vector of SDL_FRect type
* - Takes a boolean value for filled or not filled
* - Takes colour data of rgba type
*/
void render2D::drawRectangles(std::vector<SDL_FRect*> entity, bool fill, rgba colour)
{
	for (auto& e : entity)
	{
		SDL_SetRenderDrawColor(m_renderer, colour.r, colour.g, colour.b, colour.a);
		SDL_RenderFillRect(m_renderer, e);
	}
}

/**
* Draws one or more triangles of specified co-ordinates and specified colour
* - Takes co-ordinates data of three points
* - Takes colour data of rgba type
*/
void render2D::drawTriangle(vec2D p1, vec2D p2, vec2D p3, rgba colour)
{
	drawLine(p1, p2, colour);
	drawLine(p2, p3, colour);
	drawLine(p3, p1, colour);
}

/**
* Draws a single point of specified co-ordinates and of specified colour
* - Takes a single point co-ordinates data
* - Takes colour data of rgba type
*/
void render2D::drawPoint(vec2D p1, rgba colour)
{
	SDL_SetRenderDrawColor(m_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderPoint(m_renderer, p1.x, p1.y);
}

/**
* Swap Current frame drawn with the previous frame.
* After doing so, also clear the drawn frame to ready it for the next instance to be drawn.
*/
void render2D::swapFrames()
{
	// Render the current frame after drawn
	SDL_RenderPresent(m_renderer);
	
	// Clear the current frame to prepare for the next drawing call
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);
}