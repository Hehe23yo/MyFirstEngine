#pragma once

#include "render2D.h"
#include "Keys.h"

class __declspec(dllexport) Application : protected render2D
{
public:
	Application();
	~Application();

	bool createConsoleWindow();

	void run();
protected:
	//Uint8 const* key;

	struct keyState
	{
		bool down ;
		bool up = !down;
	};

	keyState m_keys[512];

	bool windowClosed();
	virtual void create();
	virtual void update();

	bool pollEvent(SDL_Event event);
	
private:
	
	SDL_Window* m_window;

protected:
SDL_Event m_event;
	const char* m_Stitle;
	float m_Swidth;
	float m_Sheight;
	float m_Sflags;

	const char* m_Rname;
	int m_Rflags;
};
