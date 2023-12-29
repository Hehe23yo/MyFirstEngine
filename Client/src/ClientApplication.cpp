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
	void update() override;

private:

	/*vec2D p1 = { 0.0, 25.0 };
	vec2D p2 = { 600.0, 600.0 };
	vec2D p3 = { 7.0, 0.0 };
	vec2D p4 = { 0.0, 350.0 };
	vec2D p5 = { 7.0, 0.0 };
	vec2D p6 = { 0.0, 350.0 };*/

	vec2D p1 = { 0.0, 25.0 };
	vec2D p2 = { 600.0, 600.0 };
	vec2D p3 = { 7.0, 0.0 };
	vec2D p4 = { 0.0, 350.0 };
	vec2D p5 = { 0.0, 0.0 };
	vec2D p6 = { 0.0, 0.0 };

};

void Client::create()
{
	drawLine(p1, p2);
	drawLine(p3, p4);
	drawLine(p5, p6);
}

void Client::update()
{
	if (p1.x <= 800.0 && p1.y <= 0.0)
		p1.x += 2;
	else if (p1.x >= 800.0 && p1.y <= 600.0)
		p1.y += 2;
	else if (p1.x >= 0.0 && p1.y >= 600.0)
		p1.x -= 2;
	else
		p1.y -= 2;

	if (p2.x <= 800.0 && p2.y <= 0.0)
		p2.x += 2;
	else if (p2.x >= 800.0 && p2.y <= 600.0)
		p2.y += 2;
	else if (p2.x >= 0.0 && p2.y >= 600.0)
		p2.x -= 2;
	else
		p2.y -= 2;

	if (p3.x <= 800.0 && p3.y <= 0.0)
		p3.x += 2;
	else if (p3.x >= 800.0 && p3.y <= 600.0)
		p3.y += 2;
	else if (p3.x >= 0.0 && p3.y >= 600.0)
		p3.x -= 2;
	else
		p3.y -= 2;

	if (p4.x <= 800.0 && p4.y <= 0.0)
		p4.x += 2;
	else if (p4.x >= 800.0 && p4.y <= 600.0)
		p4.y += 2;
	else if (p4.x >= 0.0 && p4.y >= 600.0)
		p4.x -= 2;
	else
		p4.y -= 2;

	//p2.x -= 2;

	//p3.y += 2;

	//p4.y -= 2;

	
}

int main()
{
	Client* game = new Client();
	if(game->createConsoleWindow());
		game->run();
	
	delete game;
	return 0;
}
