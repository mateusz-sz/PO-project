#include "Game.h"

using namespace sf;

Game::Game()
	:MyWindow(VideoMode(640, 480), "Shooter", Style::Default | Style::Titlebar | Style::Close | Style::Resize)
	, MyPlayer(&PlayerTexture, Vector2u(3,9), 0.3f)
{

	
}

Game::~Game()
{
}

bool Game::running()
{
	return isRunning;
}

void Game::RunGame()
{
	while (MyWindow.isOpen())
	{
		ProcessEvents();
		Update();
		Render();
	}
}

void Game::ProcessEvents()
{
	Event MyEvent;
	while (MyWindow.pollEvent(MyEvent))
	{
		switch (MyEvent.type)
		{
		case Event::KeyPressed:
			HandlePlayerInput(MyEvent.key.code, true);
			break;
			
		case Event::KeyReleased:
			HandlePlayerInput(MyEvent.key.code, false);
			break;

		case Event::Closed:
			MyWindow.close();
			break;

		default:
			break;
		}
	}
}

void Game::HandlePlayerInput(Keyboard::Key key, bool isPressed)
{
	if (key == Keyboard::W) MyPlayer.isMovingUp = isPressed;

	else if (key == Keyboard::S) MyPlayer.isMovingDown = isPressed;

	else if (key == Keyboard::A) MyPlayer.isMovingLeft = isPressed;

	else if (key == Keyboard::D) MyPlayer.isMovingRight = isPressed;
}

void Game::Update()
{
	MyPlayer.Update();
}

void Game::Render()
{
	MyWindow.clear(Color::Blue);
	MyPlayer.DrawPlayer(MyWindow);

	MyWindow.display();
}

void Game::Clean()
{

}