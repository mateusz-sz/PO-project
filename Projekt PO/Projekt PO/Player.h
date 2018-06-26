#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Animation.h"
#include "Collider.h"

using namespace sf;
class Player
{
public:
	Player (Texture* texture, Vector2u imageCount, float switchTime);
	~Player();
	void Update(float deltaTime);
	void DrawPlayer(RenderWindow &win);

	Vector2f GetPlayerPosition();
	Collider GetCollider() { return Collider(body); }

private:
	int health, armor;
	float PlayerSpeed;

	Animation animation;
	RectangleShape body;

	unsigned int row;
	
};

