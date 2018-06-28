#include<iostream>
#include"sfml\graphics.hpp"
#include"sfml\window.hpp"
#include"sfml\system.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "GenerateRandomNumber.h"

using namespace sf;

int ScreenX = 1920, ScreenY = 1080;
static const float VIEW_HEIGHT = (float)ScreenY;

void ResizeView(const RenderWindow& window, View& view);

int main()
{
	int counter = 0; std::cout << counter << "\n";
	float deltaTime = 0.0f;
	Clock clock;
	
	RenderWindow window(VideoMode(ScreenX, ScreenY), "Shooter", Style::Close | Style::Resize);
	View view(Vector2f(0, 0), Vector2f((float)ScreenX, (float)ScreenY));
	
	Texture playerTexture; //-----------------------------------------------------------CREATING PLAYER
	playerTexture.loadFromFile("Images/PlayerSprite.png");
	Player player(&playerTexture, Vector2u(4, 4), 0.3f, 150.f, 90.f);
	
	Texture a; a.loadFromFile("Images/a.jpg");
	Texture b; b.loadFromFile("Images/b.jpg");
	Platform p1(&a, Vector2f(200, 150), Vector2f(200, 100));
	Platform p2(&b, Vector2f(200, 150), Vector2f(500, 0));

	Texture enemyTexture;
	enemyTexture.loadFromFile("Images/EnemySprite.png");
	Enemy enemy(&enemyTexture, Vector2u(4, 4), 0.3f, ScreenX, ScreenY);
	std::vector<Enemy>Enemies;
	

	while (window.isOpen())
	{
		counter++;
		deltaTime = clock.restart().asSeconds();

		Event Myevent;
		while(window.pollEvent(Myevent))
		{
			switch (Myevent.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::Resized:
				ResizeView(window, view);
				break;

			default:
				break;
			}
		}
		//GENERATING
		if (counter % 5000 == 0) Enemies.push_back(enemy);
	
		//UPDATE
		player.Update(deltaTime);
		srand(time(NULL));
		for (auto &e : Enemies)e.Update(deltaTime, player);
		
	
		//COLLISION
		p1.GetCollider().CheckCollision(player.GetCollider(), 0.3f);
		p2.GetCollider().CheckCollision(player.GetCollider(), 0.8f);
		for(auto &e:Enemies)e.GetCollider().CheckCollision(player.GetCollider(), 0.5f);   //-------COLLISION FOR ALL ENEMIES
		for(auto &e: Enemies) for(auto &ee : Enemies)e.GetCollider().CheckCollision(ee.GetCollider(), 0.5f);

		//WINDOW SETTINGS
		view.setCenter(player.GetPlayerPosition());     //player is in the center 
		window.clear(Color::Green);
		window.setView(view);

		//DEJWO TO ZIOMAL

		//DRAWING
		player.DrawPlayer(window);
		p1.Draw(window);
		p2.Draw(window);
		for (auto &e : Enemies)e.DrawEnemy(window); //-------------------DRAW ENEMIES

		window.display();
	}
	
	return 0;
}

void ResizeView(const RenderWindow& window, View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}