#include "Application.h"
#include <iostream>
//#include "SDL3/SDL.h"

Application::Application()
{
	
}

Application::~Application()
{
	SDL_DestroyWindow(m_window);
}

bool Application::createConsoleWindow()
{
	std::cout << "Created" << std::endl;
	m_window = SDL_CreateWindow(m_Stitle, m_Swidth, m_Sheight, m_Sflags);
	std::cout << "Created" << std::endl;
	if (!m_window)
	{
		std::cout << "Failed to create window!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
		return 0;
	}

	return 1;
}

void Application::run()
{
	createRenderer(m_window, m_Rname, m_Rflags);
	while (!windowClosed())
	{
		create();
		update();

		SDL_Delay(10);
	}
}

void Application::create()
{

}

void Application::update()
{

}

bool Application::windowClosed()
{
	while (SDL_PollEvent(&m_event) > 0)
	{
		switch (m_event.type)
			{
			case SDL_EVENT_QUIT:
				return true;
			}
	}
	

	return false;
}