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

	std::vector<SDL_FRect*> rectangles;

	float puckWidth = 50.0f;
	float puckHeight = 150.0f;

	SDL_FRect leftPuck = { 25.0f, 100.0f, puckWidth, puckHeight };
	SDL_FRect rightPuck = { 800.0f - 75.0f, 100.0f, puckWidth, puckHeight };

	vec2D p5 = { 7.0, 0.0 };
	vec2D p6 = { 0.0, 350.0 };
};

void Client::create()
{
	rectangles.push_back(&leftPuck);
	rectangles.push_back(&rightPuck);
}

void Client::update()
{

	//drawLine(p5, p6);
	drawRectangles(rectangles, 1);

	if (m_keys[KEY_W].down)
		leftPuck.y -= 1;
	else if (m_keys[KEY_S].down)
		leftPuck.y += 1;

	if (m_keys[KEY_UP].down)
		rightPuck.y -= 1;
	else if (m_keys[KEY_DOWN].down)
		rightPuck.y += 1;

	
}

int main()
{
	Client* game = new Client();
	if(game->createConsoleWindow());
		game->run();
	
	delete game;
	return 0;
}
