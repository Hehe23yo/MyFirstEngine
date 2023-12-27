#include "Engine.h"

class Client : public Application
{
public:
	Client()
	{
		m_Stitle = "Pong";
		m_Swidth = 800.0f;
		m_Sheight = 600.0f;
		m_Sflags = 0;

		m_Rname = NULL;
		m_Rflags = SDL_RENDERER_ACCELERATED;
	}

	~Client()
	{
		
	}


	void create() override;

private:

};

void Client::create()
{
	drawLine();
}

int main()
{
	Client* game = new Client();
	if(game->createConsoleWindow());
		game->run();
	
	delete game;
	return 0;
}
