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
	std::vector<vec2DLine*> lines;

	float puckWidth = 50.0f;
	float puckHeight = 150.0f;

	SDL_FRect leftPuck = {
		25.0f,
		100.0f,
		puckWidth,
		puckHeight
	};

	SDL_FRect rightPuck = {
		800.0f - 75.0f,
		100.0f,
		puckWidth,
		puckHeight
	};

	rgba puckColour = { 200,200,200,255 };

	SDL_FRect ball = {
		400.0f,
		300.0f,
		17.0f,
		17.0f
	};

	rgba Colour = { 255,255,0,255 };

	vec2D p4 = { 300.0, 50.0 };
	vec2D p5 = { 10.0, 100.0 };
	vec2D p6 = { 800.0, 600.0 };

	vec2DLine l1 = {
		100.0, 100.0,
		700.0, 500.0,
	};

	vec2DLine l2 = {
		700.0, 500.0,
		800.0, 0.0
	};

	vec2DLine l3 = {
		800.0, 0.0,
		100.0, 100.0
	};

	float ballVelocityX = 3.0f;
	float ballVelocityY = 3.0f;
};

void Client::create()
{
	rectangles.push_back(&leftPuck);
	rectangles.push_back(&rightPuck);
	rectangles.push_back(&ball);

	lines.push_back(&l1);
	lines.push_back(&l2);
	lines.push_back(&l3);
}

void Client::update()
{	
	//drawLines(lines);
	drawPoint(p4, Colour);
	//drawLine(p5, p6, Colour);
	//drawLines(lines, Colour);
	drawTriangle(p4, p5, p6, Colour);
	drawRectangles(rectangles, 1, puckColour);
	
	if (m_keys[KEY_W].down)
		leftPuck.y -= 10;
	else if (m_keys[KEY_S].down)
		leftPuck.y += 10;

	if (m_keys[KEY_UP].down)
		rightPuck.y -= 10;
	else if (m_keys[KEY_DOWN].down)
		rightPuck.y += 10;
	
	ball.x += ballVelocityX;
	ball.y -= ballVelocityY;

	if (ball.x >= rightPuck.x - 17.0 || ball.x <= leftPuck.x + puckWidth)
		if ((ball.y >= rightPuck.y && ball.y <= rightPuck.y + puckHeight) || (ball.y >= leftPuck.y && ball.y <= leftPuck.y + puckHeight))
			ballVelocityX *= -1.0f;
	if (ball.y <= 0.0f || ball.y >= 600.0f)
		ballVelocityY *= -1.0f;
	
}

int main()
{
	Client* game = new Client();
	if(game->createConsoleWindow());
		game->run();
	
	delete game;
	return 0;
}
