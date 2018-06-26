#include<iostream>
#include"sfml\graphics.hpp"
#include"sfml\window.hpp"
#include"sfml\system.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>

//length of vector: |v| = sqrt(v.x^2 + v.y^2)
//normalize vector: u = v / |v|

#include "Player.h"
#include "Platform.h"

using namespace sf;

float ScreenX = 1080.0f, ScreenY = 720.0f;
static const float VIEW_HEIGHT = ScreenY;

void ResizeView(const RenderWindow& window, View& view);

int main()
{
	RenderWindow window(VideoMode(ScreenX, ScreenY), "Shooter", Style::Close | Style::Resize);
	View view(Vector2f(0, 0), Vector2f(ScreenX, ScreenY));
	Texture playerTexture;
	playerTexture.loadFromFile("Images/PlayerSprite.png");
	
	Player player(&playerTexture, Vector2u(4, 4), 0.3f);

	float deltaTime = 0.0f;
	Clock clock;
	Texture a; a.loadFromFile("Images/a.jpg");
	Texture b; b.loadFromFile("Images/b.jpg");
	Platform p1(&a, Vector2f(400, 200), Vector2f(500, 200));
	Platform p2(&b, Vector2f(400, 200), Vector2f(500, 0));

	while (window.isOpen())
	{
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
		player.Update(deltaTime);
	
		p1.GetCollider().CheckCollision(player.GetCollider(), 0.3f);
		p2.GetCollider().CheckCollision(player.GetCollider(), 0.8f);

		view.setCenter(player.GetPlayerPosition());     //player is in the center 

		window.clear(Color::Green);
		window.setView(view);
		player.DrawPlayer(window);
		p1.Draw(window);
		p2.Draw(window);


		window.display();
	}
	
	return 0;
}

void ResizeView(const RenderWindow& window, View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}