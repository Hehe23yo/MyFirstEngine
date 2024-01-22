#include "Engine.h"
#include <math.h>

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
	std::vector<vec2DLine*> ball;

	float puckWidth = 50.0f;
	float puckHeight = 150.0f;

	int noTriangles = 70;
	float radius = 120.0f;
	float theta = 0.0f;
	vec2D ballCentre = { 400.0f, 300.0f };

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

	
	//vec2D ball = { 400.0f, 300.0f };
	float ballVelocityX = 3.0f;
	float ballVelocityY = 3.0f;
};

void Client::create()
{
	rectangles.push_back(&leftPuck);
	rectangles.push_back(&rightPuck);

	ball.reserve(noTriangles + 1);
	/*lines.push_back(&l1);
	lines.push_back(&l2);
	lines.push_back(&l3);*/

	for (int i = 0; i < noTriangles + 1; i++)
	{
		vec2DLine* line = new vec2DLine;
		line->x1 = ballCentre.x;
		line->y1 = ballCentre.y;
		line->x2 = line->x1 + radius * sin(theta);
		line->y2 = line->y1 + radius * cos(theta);

		theta += 2 * 3.141593 / noTriangles;

		ball.emplace_back(line);
	}
}

void Client::update()
{	
	//drawLines(lines);
	//drawPoint(p4, Colour);
	//drawLine(p5, p6, Colour);
	//drawLines(lines, Colour);
	//drawTriangle(p4, p5, p6, Colour,1);
	//drawRectangles(rectangles, 1, puckColour);
	//drawLines(lines, Colour);

	vec2D a;
	vec2D b;
	vec2D c;

	theta = 0.0;

	for (int i = 0; i < noTriangles + 1; i++)
	{

		ball[i]->x1 = ballCentre.x;
		ball[i]->y1 = ballCentre.y;
		ball[i]->x2 = ball[i]->x1 + radius * sin(theta);
		ball[i]->y2 = ball[i]->y1 + radius * cos(theta);

		theta += 2 * 3.141593 / noTriangles;

		//lines.erase(std::next(lines.begin(), i));
		//lines.emplace_back(lines[i]->x1,lines[i]->y1,(line->x1 + radius * sin(theta)), (line->x1 + radius * cos(theta)));
		//lines.emplace_back(line);
		
	}
	for (int i = 0; i < noTriangles; i++)
	{
		a = { ball[i]->x1, ball[i]->y1 };
		b = { ball[i]->x2, ball[i]->y2 };
	    c = { ball[i + 1]->x2, ball[i + 1]->y2 };
		//drawLine(b, c, Colour);
		drawTriangle(a, b, c, Colour, 1);
	}

	if(m_keys[KEY_W].down)
	{
		ballCentre.y -= 3;
	}
	else if(m_keys[KEY_S].down)
	{
		ballCentre.y += 3;
	}

	if (m_keys[KEY_A].down)
	{
		ballCentre.x -= 3;
	}
	else if (m_keys[KEY_D].down)
	{
		ballCentre.x += 3;
	}
	
	
	/*if (m_keys[KEY_W].down)
		leftPuck.y -= 10;
	else if (m_keys[KEY_S].down)
		leftPuck.y += 10;

	if (m_keys[KEY_UP].down)
		rightPuck.y -= 10;
	else if (m_keys[KEY_DOWN].down)
		rightPuck.y += 10;*/
	
}

int main()
{
	Client* game = new Client();
	if(game->createConsoleWindow());
		game->run();
	
	delete game;
	return 0;
}
