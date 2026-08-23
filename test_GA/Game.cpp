#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "iostream"

float Game::zoom{ 80.f };

Game::Game(const Window& window)
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{

}

void Game::Cleanup()
{
}

void Game::Update(float elapsedSec)
{
	v = Vector{ 0, cosf(time), sinf(time), 0 };
	time += elapsedSec;

	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_LALT] )
	{
		//std::cout << "Right arrow key is down\n";
	}
	if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	{
		//std::cout << "Left and up arrow keys are down\n";
	}
}

void Game::Draw()
{
	ClearBackground();
	glPushMatrix();
	{
		glTranslatef(Game::GetViewPort().width / 3, Game::GetViewPort().height / 3, 1.f);
		// variable de translation pour bouger avec molette	
		glScalef(zoom, zoom, 0.f);

		DrawBackground();


		TriVector pointGA{ Point::ToPGAPoint(point) };
		TriVector pointGAReflected{ (v * u * pointGA * GA::Inverse(v * u)).Grade3() };
		Point pointRefected{ Point::ToEnginePoint(pointGAReflected) };

		utils::SetColor(Color4f{ 0, 1, 1, 1 });
		renderer.DrawPoint(point, 5.f);

		utils::SetColor(Color4f{ 1, 1, 1, 1 });
		renderer.DrawPoint(pointRefected, 5.f);
		utils::SetColor(Color4f{ .75f, .75f, .75f, 1 });
		renderer.DrawPoint((GA::Inner(pointGAReflected, e2) * GA::Inverse(e2)).Grade3(), 7.f);
		//renderer.DrawLine(Line{ u. }, 1.f);
		//renderer.DrawLine(v, 1.f);
	}
	glPopMatrix();
}

void Game::DrawBackground() const
{
	BiVector xAxis{ 12, 0, 0, -2, 0, 0 },
		yAxis{ 0, 12, 0, 0, -2, 0 },
		zAxis{ 0, 0, 12, 0, 0, -2 };

	utils::SetColor(Color4f{ 1, 0, 0, 1 });
	renderer.DrawLine(xAxis, 3.f);

	utils::SetColor(Color4f{ 0, 1, 0, 1 });
	renderer.DrawLine(yAxis, 3.f);

	utils::SetColor(Color4f{ 0, 0, 1, 1 });
	renderer.DrawLine(zAxis, 3.f);

	xAxis = BiVector{ 10, 0, 0, 0, 0, 0 };
	yAxis = BiVector{ 0, 10, 0, 0, 0, 0 };
	zAxis = BiVector{ 0, 0, 10, 0, 0, 0 };

	for (size_t i = 0; i < 10; i++)
	{
		xAxis.e12()++;
		yAxis.e12()++;
		zAxis.e31()++;
		utils::SetColor(Color4f{ 0, 1, 0, 0.3f }); // green
		renderer.DrawLine(xAxis, 2.f);
		utils::SetColor(Color4f{ 1, 0, 0, 0.3f }); // red
		renderer.DrawLine(yAxis, 2.f);
		renderer.DrawLine(zAxis, 2.f);
	}

	xAxis.e12() = 0;
	yAxis.e12() = 0;
	zAxis.e31() = 0;

	for (size_t i = 0; i < 11; i++)
	{

		utils::SetColor(Color4f{ 0, 0, 1, 0.3f }); // blue
		renderer.DrawLine(xAxis, 2.f);
		renderer.DrawLine(yAxis, 2.f);
		utils::SetColor(Color4f{ 0, 1, 0, 0.3f }); // green
		renderer.DrawLine(zAxis, 2.f);

		xAxis.e31()++;
		yAxis.e23()++;
		zAxis.e23()++;
	}
}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_LALT:
		isAlt = true;
		break;
	}
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_UP:
		if (isAlt) point.position.z++;
		else point.position.y++;
		break;
	case SDLK_DOWN:
		if (isAlt) point.position.z--;
		else point.position.y--;
		break;
	case SDLK_LEFT:
		point.position.x--;
		break;
	case SDLK_RIGHT:
		point.position.x++;
		break;
	case SDLK_LALT:
		isAlt = false;
		break;
	}
}

void Game::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}

}

void Game::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseWheelEvent(const SDL_MouseWheelEvent& e)
{
	if (e.y > 0)
	{
		zoom += 5.f;
	}
	else if (e.y < 0)
	{
		zoom -= 5.f;
	}
}

void Game::ClearBackground() const
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
