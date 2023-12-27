#pragma once

#include "SDL3/SDL.h"
#include "render2D.h"
#include <iostream>

class __declspec(dllexport) Application : protected render2D
{
public:
	Application();
	~Application();

	bool createConsoleWindow();

	void run();
protected:
	
	bool windowClosed();
	virtual void create();
	
private:
	
	SDL_Window* m_window;
	SDL_Event m_event;

protected:

	const char* m_Stitle;
	float m_Swidth;
	float m_Sheight;
	float m_Sflags;

	const char* m_Rname;
	int m_Rflags;
};
