#pragma once
#include<iostream>
#include"sfml\graphics.hpp"
#include"sfml\window.hpp"
#include"sfml\system.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>

using namespace sf;

#include "Player.h"
#include "Animation.h";


class Game
{
public:
	Game();
	~Game();

	void RunGame();

private:
	bool isRunning;
	void Update();
	void Render();
	void Clean();
	void ProcessEvents();
	void HandlePlayerInput(Keyboard::Key key, bool isPressed);
	bool running();

public:
	RenderWindow MyWindow;
	Player MyPlayer;
};

