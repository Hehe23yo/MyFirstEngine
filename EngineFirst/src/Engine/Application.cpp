#include "Application.h"

Application::Application()
{
	
}

Application::~Application()
{
	SDL_DestroyWindow(m_window);
}

bool Application::createConsoleWindow()
{
	m_window = SDL_CreateWindow(m_Stitle, m_Swidth, m_Sheight, m_Sflags);
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
	create();
	while (!windowClosed())
	{
		
		//onUserInput();
		update();
		swapFrames();
		SDL_Delay(10);
	}
}

void Application::create()
{

}

void Application::update()
{

}

bool Application::pollEvent(SDL_Event event)
{
	//key = SDL_GetKeyboardState(nullptr);
	return (SDL_PollEvent(&event) > 0);
}

bool Application::windowClosed()
{
	Uint8 const* key;
	while (SDL_PollEvent(&m_event) > 0)
	{
		switch (m_event.type)
			{
			case SDL_EVENT_QUIT:
				return true;
			case SDL_EVENT_KEY_DOWN:
				key = SDL_GetKeyboardState(nullptr);
				for (int i = 0; i < 512; i++)
				{
					if (key[i])
						m_keys[i].down = true;
				}
			case SDL_EVENT_KEY_UP:
				key = SDL_GetKeyboardState(nullptr);
				for (int i = 0; i < 512; i++)
				{
					if(!key[i])
						m_keys[i].down = false;
				}
			}
	}
	

	return false;
}